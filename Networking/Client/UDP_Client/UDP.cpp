/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ClientUDP
*/

#include "UDP.hpp"

UDP::UDP(const std::string& server_ip, int client_port) : port(client_port), ioContext(), socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)), isRunning(true), endpoint_server(asio::ip::address::from_string(server_ip), port)
{
}

UDP::~UDP()
{
}

void UDP::writeMessages(std::string message_)
{
    try {
        std::getline(std::cin, message_);
        socket.send_to(asio::buffer(message_), endpoint_server);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

std::string UDP::getmessage()
{
    return message_;
}

void UDP::start()
{
    try {
        std::cout << "UDP Client started on port " << port << std::endl;
        while (true) {
            writeMessages(message_);
            std::vector<char> receive_buffer(1024);
            size_t bytes_received = socket.receive_from(asio::buffer(receive_buffer), endpoint_client);
            receive_buffer[bytes_received] = '\0';
            std::cout << "Received from the Server" << " = " << receive_buffer.data() << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void UDP::stop()
{
    ioContext.stop();
    socket.shutdown(asio::ip::udp::socket::shutdown_both);
    socket.close();
}
