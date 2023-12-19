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
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "Handle_message.hpp"

class ServerTCP {
public:
    ServerTCP(int portTCP);
    ~ServerTCP();

    void start();
    void handleClient(std::shared_ptr<asio::ip::tcp::socket> clientSocket);
    void stop();

private:
    std::unordered_map<std::shared_ptr<asio::ip::tcp::socket>, int> clientUIDs;
    int nextUID;
    std::mutex uidMutex;
    std::condition_variable clientCV;
    std::queue<std::shared_ptr<asio::ip::tcp::socket>> clientQueue;
    int port;
    void initializeAcceptor();
    void run();
    void workerThread();
    asio::io_context ioContext;
    asio::ip::tcp::endpoint endpoint;
    asio::ip::tcp::acceptor acceptor;
    bool isRunning;
    std::vector<std::thread> workerThreads;
};
