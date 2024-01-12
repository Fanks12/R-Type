/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerUDP
*/

#pragma once

#include <asio.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include "Packet.hpp"

class ServerUDP {
public:
    ServerUDP(int port);
    ~ServerUDP();

    void start();
    void stop();

private:
    int port;
    asio::io_context ioContext;
    asio::ip::udp::socket socket;
    asio::ip::udp::endpoint endpoint;
    bool isRunning;
    void run();
    void handlePacket(const Packet& packet);
};
