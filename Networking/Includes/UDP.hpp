/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** UDP
*/

#pragma once

#include <asio.hpp>
#include <iostream>
#include <vector>
#include <thread>

class UDP {
    public:
        UDP() = default;
        UDP(int port);
        ~UDP();

        void stop();
        void start();

    protected:
    private:
        int port;
        asio::io_context ioContext;
        asio::ip::udp::socket socket;
        asio::ip::udp::endpoint endpoint_server;
        asio::ip::udp::endpoint endpoint_client;
        bool isRunning;
};
