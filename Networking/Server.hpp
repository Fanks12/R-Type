/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** Server
*/

#include "ServerTCP.hpp"
#include "ServerUDP.hpp"
#include <iostream>
#include <thread>
#include <memory>


class Server {
    public:
        Server() = default;
        Server(int tcpPort, int udpPort);
        ~Server();

        void start();

    private:
        std::shared_ptr<ServerTCP> tcpServer_;
        std::shared_ptr<ServerUDP> udpServer_;
        int tcpPort_;
        int udpPort_;
};
