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
#include <unordered_map>

class ServerUDP {
public:
    ServerUDP(int port);
    ~ServerUDP();

    void start();
    void stop();
    void sendToAllClients(const std::string& message, int clientId);
    void sendToClient(const std::string& message, int clientId);
private:
    struct ClientInfo {
        int id;
        asio::ip::udp::endpoint endpoint;
    };
    struct EndpointHash {
        size_t operator()(const asio::ip::udp::endpoint& ep) const {
            return std::hash<std::string>()(ep.address().to_string() + ":" + std::to_string(ep.port()));
        }
    };

    int port;
    asio::io_context ioContext;
    asio::ip::udp::socket socket;
    asio::ip::udp::endpoint endpoint;
    bool isRunning;

    std::unordered_map<asio::ip::udp::endpoint, ClientInfo, EndpointHash> clients;
    int nextClientId = 1;

    void run();
    std::string getClientList() const;
    int generateClientId();
    void handleClient(const asio::ip::udp::endpoint& clientEndpoint, const std::string& decryptedMessage);

};
