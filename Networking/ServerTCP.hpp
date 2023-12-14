/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerTCP
*/

#pragma once
#include <asio.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>


class ServerTCP  {
    public:
        ServerTCP(int portTCP);
        ~ServerTCP();

        void start();
        void handleClient(std::shared_ptr<asio::ip::tcp::socket> clientSocket);
        void stop();

    private:
        int port;
        void initializeAcceptor();
        void handleClient(asio::ip::tcp::socket clientSocket);
        void run();
        asio::io_context ioContext;
        asio::ip::tcp::endpoint endpoint;
        asio::ip::tcp::acceptor acceptor;
        bool isRunning;
};
