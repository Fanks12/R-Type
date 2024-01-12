/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(int tcpPort, int udpPort) : tcpPort_(tcpPort), udpPort_(udpPort)
{
    // tcpServer_ = std::make_unique<ServerTCP>(tcpPort_);
    udpServer_ = std::make_unique<ServerUDP>(udpPort_);
}

Server::~Server()
{
    // tcpServer_->stop();
    udpServer_->stop();
}

void Server::SendToAllClientsUDP(const std::string &msg)
{
    udpServer_->sendToAllClients(msg);
}

void Server::SendToClientUDP(const std::string &msg, int ClientID)
{
    udpServer_->sendToClient(msg, ClientID);
}

void Server::start()
{
    // std::cout << "Server TCP started" << std::endl;
    // std::thread tcpThread([this]() {
    //     tcpServer_->start();
    // });
    std::cout << "Server UDP started" << std::endl;
    std::thread udpThread([this]() {
        udpServer_->start();
    });
    // tcpThread.join();
    udpThread.join();
    std::cout << "Server UDP stoped" << std::endl;
}
