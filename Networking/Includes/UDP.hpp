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
#include <mutex>
#include <condition_variable>
#include <queue>


class UDP {
    public:
        UDP() = default;
        UDP(const std::string& server_ip, int port);
        ~UDP();

        void stop();
        void start();
        void writeMessages(const std::string& message);
        std::string getmessage();
        void receiveMessages();
        int getreceive();

    protected:
    private:
        int port;
        int _receive;
        std::string message_;
        asio::io_context ioContext;
        asio::ip::udp::socket socket;
        asio::ip::udp::endpoint endpoint_server;
        asio::ip::udp::endpoint endpoint_client;
        bool isRunning;
};
