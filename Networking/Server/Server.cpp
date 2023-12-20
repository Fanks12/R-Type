/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(int tcpPort, int udpPort) : tcpPort_(tcpPort), udpPort_(udpPort)
{
    tcpServer_ = std::make_unique<ServerTCP>(tcpPort_);
    udpServer_ = std::make_unique<ServerUDP>(udpPort_);
}

Server::~Server()
{

}

void Server::start()
{
    std::thread tcpThread([this]() {
        tcpServer_->start();
    });
    std::thread udpThread([this]() {
        udpServer_->start();
    });
    tcpThread.join();
    udpThread.join();
}
