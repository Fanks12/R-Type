/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** TCP
*/

#pragma once
#include <asio.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "Packet.hpp"


class TCP {
    public:
        TCP() = default;
        TCP(const std::string& server_ip, int client_port);
        ~TCP();
        void start();
        void readPacket(asio::ip::tcp::socket& socket);
        void writePacket(const Packet& packet);
        Packet getReceivedPacket();
        void stop();

    protected:
    private:
        std::thread reader_thread;
        int port;
        Packet receivedPacket;
        std::string ip_server;
        asio::io_context ioContext;
        asio::ip::tcp::socket socket;
        asio::ip::tcp::endpoint endpoint;
};
