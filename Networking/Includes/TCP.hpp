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
#include <atomic>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <queue>

class TCP {
    public:
        TCP() = default;
        TCP(int portTCP);
        ~TCP();

    void start(const std::string& server_ip, int port);
    void stop();


    protected:
    private:
        int port;
        asio::io_context ioContext;
        asio::ip::tcp::socket socket;
        asio::ip::tcp::endpoint endpoint;
        asio::ip::tcp::acceptor acceptor;
        bool isRunning;
};
