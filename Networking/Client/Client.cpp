/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(const std::string& server_ip, int tcpPort, int udpPort) : tcpPort_(tcpPort), udpPort_(udpPort), server_ip_(server_ip)
{
    std::cout << "Client created" << std::endl;
}

Client::~Client()
{
    tcpClient_->stop();
    udpClient_->stop();
}

void Client::WritePacketTCP(const Packet& packet)
{
    tcpClient_->writePacket(packet);
}

void Client::WritePacketUDP(const Packet& packet)
{
    udpClient_->writePacket(packet);
}

Packet Client::readPacketTCP()
{
    return tcpClient_->getReceivedPacket();
}

Packet Client::readPacketUDP()
{
    return udpClient_->getReceivedPacket();
}

void Client::start()
{
    try {
        // std::cout << "Client TCP started" << std::endl;
        // std::thread tcpThread([this]() {
        //     tcpClient_ = std::make_unique<TCP>(server_ip_, tcpPort_);
        //     tcpClient_->start();
        // });
        std::cout << "Client UDP started" << std::endl;
        std::thread udpThread([this]() {
            udpClient_ = std::make_unique<UDP>(server_ip_, udpPort_);
            udpClient_->start();
        });
        // tcpThread.join();
        // std::cout << "Client TCP stopped" << std::endl;
        udpThread.join();
        std::cout << "Client UDP stopped" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
