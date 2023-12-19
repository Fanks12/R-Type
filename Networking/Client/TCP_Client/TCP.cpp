#include <asio.hpp>
#include <iostream>
#include <vector>
#include "TCP.hpp"

using asio::ip::tcp;

TCP::TCP(int client_port): port(client_port), ioContext(), socket(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)) {

}

TCP::~TCP()
{
    stop();
}

void TCP::start()
{
    try {
        asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(server_ip, std::to_string(port));
        asio::connect(socket, endpoints);

        std::cout << "Enter a message for the serv:\n";
        while (true) {
            std::string msg_send;
            std::getline(std::cin, msg_send);

            asio::write(socket, asio::buffer(msg_send));

            std::vector<char> receive_buffer(1024);
            size_t bytes_received = socket.read_some(asio::buffer(receive_buffer));

            std::cout << "Received: " << std::string(receive_buffer.data(), bytes_received) << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void TCP::stop()
{
    ioContext.stop();
}


// int main() {
//     int port = 8082;
//     std::string server_ip = "127.0.0.1";

//     tcp_client(server_ip, port);
//     return 0;
// }
