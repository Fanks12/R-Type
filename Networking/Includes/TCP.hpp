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

class TCP {
    public:
        TCP() = default;
        TCP(const std::string& server_ip, int client_port);
        ~TCP();
        void start();
        void readMessages(asio::ip::tcp::socket& socket);
        void stop();
        void writeMessages(std::string msg_send);

    protected:
    private:
        int port;
        std::string ip_server;
        asio::io_context ioContext;
        asio::ip::tcp::socket socket;
        asio::ip::tcp::endpoint endpoint;
};