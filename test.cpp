/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** TCP
*/

#include <asio.hpp>
#include <iostream>
#include <vector>
#include <thread>

using asio::ip::tcp;

void readMessages(tcp::socket& socket)
{
    try {
        while (true) {
            std::vector<char> receive_buffer(1024);
            size_t bytes_received = socket.read_some(asio::buffer(receive_buffer));
            std::cout << "Received: " << std::string(receive_buffer.data(), bytes_received) << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void tcp_client(const std::string& server_ip, int port)
{
    try {
        asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(server_ip, std::to_string(port));
        asio::connect(socket, endpoints);
        std::thread reader_thread(readMessages, std::ref(socket));

        while (true) {
            std::string msg_send;
            std::getline(std::cin, msg_send);
            asio::write(socket, asio::buffer(msg_send));
        }

        reader_thread.join();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    int port = 4242;
    std::string server_ip = "127.0.0.1";

    tcp_client(server_ip, port);
    return 0;
}
