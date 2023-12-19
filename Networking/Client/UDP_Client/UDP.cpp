/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ClientUDP
*/

#include "UDP.hpp"

using asio::ip::udp;

UDP::UDP(int client_port): port(client_port), ioContext(), socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), isRunning(true) {

}

UDP::~UDP()
{
    stop();
}

void UDP::start()
{
    try {
        std::cout << "Enter a message for the serv:\n";
        while (true) {
            std::string msg_send;
            std::getline(std::cin, msg_send);
            socket.send_to(asio::buffer(msg_send), endpoint_server);
            std::vector<char> receive_buffer(1024);
            size_t bytes_received = socket.receive_from(asio::buffer(receive_buffer), endpoint_client);
            receive_buffer[bytes_received] = '\0';
            std::cout << "Received from " << endpoint_client.address().to_string() << " = " << receive_buffer.data() << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void UDP::stop()
{
    ioContext.stop();
}




// int main() {
//     int port = 8080;
//     std::string server_ip = "127.0.0.1";

//     udp_client(server_ip, port);
//     return 0;
// }
