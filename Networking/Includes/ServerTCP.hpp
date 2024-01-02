/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerTCP
*/

#pragma once
#include "Handle_message.hpp"
#include "Data.hpp"
#include <asio.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

class ServerTCP {
    public:
        ServerTCP(int portTCP);
        ~ServerTCP();

        void start();
        void handleClient(std::shared_ptr<asio::ip::tcp::socket> clientSocket);
        bool areAllClientsReady() const;
        void stop();

    private:
        std::mutex readyClientsMutex;
        std::unordered_set<std::shared_ptr<asio::ip::tcp::socket>> readyClients;
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
        Data data;
};
