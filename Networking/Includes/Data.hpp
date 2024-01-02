/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** Data
*/

#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
#include <asio.hpp>

class Data {
    public:
        Data() = default;
        ~Data() = default;
        struct ClientInfo {
            int uid;
            std::shared_ptr<asio::ip::tcp::socket> socket;
        };
        void addClient(std::shared_ptr<asio::ip::tcp::socket> socket, int uid);
        const std::list<ClientInfo>& getClients() const;

    private:
        std::list<ClientInfo> clients;
};
