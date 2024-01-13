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

void Client::WriteMessageTCP(const std::string &msg)
{
    tcpClient_->writeMessages(msg);
}

void Client::WriteMessageUDP(const std::string &msg)
{
    udpClient_->writeMessages(msg);
}

std::string Client::getmessageTCP()
{
    return tcpClient_->getmessage();
}

std::string Client::getmessageUDP()
{
    return udpClient_->getmessage();
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
        // std::cout << "Client TCP stoped" << std::endl;
        udpThread.join();
        } catch (std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
    }
}
