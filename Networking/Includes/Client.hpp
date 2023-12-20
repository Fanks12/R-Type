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
        void TcpWrite(const std::string &msg);

    protected:
    private:
        std::shared_ptr<TCP> tcpClient_;
        std::shared_ptr<UDP> udpClient_;
        int tcpPort_;
        int udpPort_;
        std::string server_ip_;
};
