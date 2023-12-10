/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** cient_udp
*/

#include <boost/asio.hpp>
#include <iostream>
#include <vector>

namespace asio = boost::asio;
using boost::asio::ip::udp;

const int PORT_NUMBER = 8080;

int main() {
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 0));
        udp::endpoint endpoint_server(boost::asio::ip::address::from_string("127.0.0.1"), PORT_NUMBER);
        std::cout << "Enter a message to send (Press Ctrl+C to exit):\n";
        while (true) {
            std::string msg_send;
            std::getline(std::cin, msg_send);
            socket.send_to(boost::asio::buffer(msg_send), endpoint_server);
            std::vector<char> receive_buffer(1024);
            udp::endpoint endpoint_client;
            size_t bytes_received = socket.receive_from(boost::asio::buffer(receive_buffer), endpoint_client);
            receive_buffer[bytes_received] = '\0';
            std::cout << "Received from " << endpoint_client.address().to_string() << " = " << receive_buffer.data() << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
