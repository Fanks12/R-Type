/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(int tcpPort, int udpPort) : tcpPort_(tcpPort), udpPort_(udpPort) {
    tcpClient_ = std::make_unique<TCP>(tcpPort_);
    udpClient_ = std::make_unique<UDP>(udpPort_);
}

Client::~Client()
{
}

void Client::start() {
    std::thread tcpThread([this]() {
        tcpClient_->start();
    });
    std::thread udpThread([this]() {
        udpClient_->start();
    });
    tcpThread.join();
    udpThread.join();
}
