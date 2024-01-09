/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** TCP
*/

#include "TCP.hpp"

using asio::ip::tcp;

TCP::TCP(const std::string& server_ip, int client_port) : port(client_port), ioContext(), socket(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 0)), ip_server(server_ip)
{
}

TCP::~TCP()
{
    stop();
}

void TCP::readPacket(tcp::socket& socket)
{
    try {
        while (true) {
            size_t bytes_received = socket.read_some(asio::buffer(&receivedPacket, sizeof(Packet)));

            if (bytes_received == sizeof(Packet)) {
                std::cout << "Received Magic_number: " << receivedPacket.Magic_number << std::endl;
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void TCP::writePacket(const Packet& packet)
{
    try {
        asio::write(socket, asio::buffer(&packet, sizeof(Packet)));
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

Packet TCP::getReceivedPacket()
{
    return receivedPacket;
}

void TCP::start()
{
    std::cout << "TCP Client started on port " << port << std::endl;
    try {
        tcp::resolver resolver(ioContext);
        tcp::resolver::results_type endpoints = resolver.resolve(ip_server, std::to_string(port));
        asio::connect(socket, endpoints);
        std::thread reader_thread(&TCP::readPacket, this, std::ref(socket));

        while (true) {
            Packet outgoingPacket;
            outgoingPacket.Magic_number = 42;

            writePacket(outgoingPacket);
            readPacket(socket);
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
