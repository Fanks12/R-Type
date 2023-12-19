#include <asio.hpp>
#include <iostream>
#include <vector>

using asio::ip::udp;

void udp_client(const std::string& server_ip, int port)
{
    try {
        asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 0));
        udp::endpoint endpoint_server(asio::ip::address::from_string(server_ip), port);
        std::cout << "Enter a message for the serv:\n";
        while (true) {
            std::string msg_send;
            std::getline(std::cin, msg_send);
            socket.send_to(asio::buffer(msg_send), endpoint_server);
            std::vector<char> receive_buffer(1024);
            udp::endpoint endpoint_client;
            size_t bytes_received = socket.receive_from(asio::buffer(receive_buffer), endpoint_client);
            receive_buffer[bytes_received] = '\0';
            std::cout << "Received from " << endpoint_client.address().to_string() << " = " << receive_buffer.data() << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    int port = 8080;
    std::string server_ip = "127.0.0.1";

    udp_client(server_ip, port);
    return 0;
}
