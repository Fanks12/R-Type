/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** Data
*/

#include "Data.hpp"

void Data::addClient(std::shared_ptr<asio::ip::tcp::socket> socket, int uid)
{
    ClientInfo info = {uid, socket};
    clients.push_back(info);
}

const std::list<Data::ClientInfo>& Data::getClients() const
{
    return clients;
}
