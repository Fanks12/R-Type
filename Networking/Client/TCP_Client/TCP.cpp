/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** TCP
*/

#include "TCP.hpp"

using asio::ip::tcp;

TCP::TCP(const std::string& server_ip, int client_port): port(client_port), ioContext(), socket(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 0)), ip_server(server_ip)
{
}

TCP::~TCP()
{
    stop();
}

void TCP::readMessages(tcp::socket& socket)
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

void TCP::start()
{
    std::cout << "TCP Client started on port " << port << std::endl;
    try {
        tcp::resolver resolver(ioContext);
        tcp::resolver::results_type endpoints = resolver.resolve(ip_server, std::to_string(port));
        asio::connect(socket, endpoints);
        std::thread reader_thread(&TCP::readMessages, this, std::ref(socket));

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

void TCP::stop()
{
    ioContext.stop();
    socket.shutdown(asio::ip::tcp::socket::shutdown_both);
    socket.close();
}
