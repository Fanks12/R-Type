/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(const std::string& server_ip, int tcpPort, int udpPort) : tcpPort_(tcpPort), udpPort_(udpPort), server_ip_(server_ip)
{
}

Client::~Client()
{
}

void Client::start()
{
    try {
    std::thread tcpThread([this]() {
        tcpClient_ = std::make_unique<TCP>(server_ip_, tcpPort_);
        tcpClient_->start();
    });
    // std::thread udpThread([this]() {
        // udpClient_->start();
    // });
    tcpThread.join();
    // udpThread.join();
    tcpClient_->stop();
    // udpClient_->stop();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
