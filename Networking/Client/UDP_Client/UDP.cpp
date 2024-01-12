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

void UDP::writePacket(const Packet& packet)
{
    try {
        socket.send_to(asio::buffer(&packet, sizeof(Packet)), endpoint_server);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void UDP::readPacket()
{
    try {
        std::vector<char> receive_buffer(sizeof(Packet));
        size_t bytes_received = socket.receive_from(asio::buffer(receive_buffer), endpoint_client);
        if (bytes_received == sizeof(Packet)) {
            std::memcpy(&receivedPacket, receive_buffer.data(), sizeof(Packet));
        }
        std::cout << "Received from the Server Magic_number = " << receivedPacket.Magic_number << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

Packet UDP::getReceivedPacket()
{
    return receivedPacket;
}

void UDP::start()
{
    try {
        std::cout << "UDP Client started on port " << port << std::endl;
        while (true) {
            Packet outgoingPacket;
            outgoingPacket.Magic_number = 42;

            writePacket(outgoingPacket);
            readPacket();
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
