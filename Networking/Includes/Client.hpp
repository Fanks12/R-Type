/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** Client
*/

#pragma once
#include <iostream>
#include <thread>
#include <memory>
#include "UDP.hpp"
#include "TCP.hpp"


class Client {
    public:
        Client() = default;
        Client(const std::string& server_ip, int tcpPort, int udpPort);
        ~Client();
        void start();
        void WriteMessageTCP(const std::string &msg);
        void WriteMessageUDP(const std::string &msg);
        std::string getmessageTCP();
        std::string getmessageUDP();

    protected:
    private:
        bool BeforGame_;
        std::shared_ptr<TCP> tcpClient_;
        std::shared_ptr<UDP> udpClient_;
        int tcpPort_;
        int udpPort_;
        std::string server_ip_;
};
