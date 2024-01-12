/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerUDP
*/

#include "ServerUDP.hpp"

ServerUDP::ServerUDP(int serv_port) : port(serv_port), ioContext(), socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), isRunning(true)
{
    endpoint = asio::ip::udp::endpoint(asio::ip::udp::v4(), port);
}

ServerUDP::~ServerUDP()
{
}

void ServerUDP::start()
{
    run();
    std::cout << "ServerUDP::start" << std::endl;
}

int ServerUDP::generateClientId() {
    return nextClientId++;
}

std::string xorEncryptDecrypt(const std::string& input, char magic_number) {
    std::string output = input;

    for (size_t i = 0; i < output.size(); ++i) {
        output[i] ^= magic_number;
    }
    return output;
}

void ServerUDP::sendToClient(const std::string& message, int clientId) {
    auto it = clients.begin();
    while (it != clients.end()) {
        if (it->second.id == clientId) {
            char magic_number = 0x69;
            std::string fullmessage = "You send: " + message;
            std::string encryptedMessage = xorEncryptDecrypt(fullmessage, magic_number);
            socket.send_to(asio::buffer(encryptedMessage), it->second.endpoint);
            break;
        }
        ++it;
    }
}

void ServerUDP::handleClient(const asio::ip::udp::endpoint& clientEndpoint, const std::string& message) {
    auto it = clients.find(clientEndpoint);
    if (it == clients.end()) {
        ClientInfo clientInfo;
        clientInfo.endpoint = clientEndpoint;
        clientInfo.id = generateClientId();
        clients[clientEndpoint] = clientInfo;
        std::string welcomeMsg = "Welcome to the server client ID =" + std::to_string(clientInfo.id);
        std::string encryptedWelcomeMsg = xorEncryptDecrypt(welcomeMsg, 0x69);
        socket.send_to(asio::buffer(encryptedWelcomeMsg), clientEndpoint);
        std::cout << "Nouveau client connecté: ID " << clientInfo.id << std::endl;
    } else {
        std::cout << "Received from the Client ID " << it->second.id << " = " << message << std::endl;
        sendToAllClients(message, it->second.id);
    }
}


void ServerUDP::run() {
    std::cout << "ServerUDP::run" << std::endl;
    try {
        std::cout << "UDP Server listening on port " << port << std::endl;

        while (isRunning) {
            std::vector<char> buffer(1024);
            asio::ip::udp::endpoint senderEndpoint;
            size_t size_msg = socket.receive_from(asio::buffer(buffer), senderEndpoint);
            if (size_msg > 0) {
                char magic_number = 0x69;
                std::string message(buffer.begin(), buffer.begin() + size_msg);
                std::string decryptedMessage = xorEncryptDecrypt(message, magic_number);
                handleClient(senderEndpoint, decryptedMessage);
            }
        }
    } catch (std::exception &e) {
        std::cerr << "UDP Exception: " << e.what() << std::endl;
    }
}

void ServerUDP::sendToAllClients(const std::string& message, int clientId) {
    char magic_number = 0x69;
    std::string fullmessage;
    for (const auto& client_pair : clients) {
        const ClientInfo& client = client_pair.second;
        if (client.id == clientId) {
            fullmessage = "You sended: " + message;
            std::string encryptedMessage = xorEncryptDecrypt(fullmessage, magic_number);
            socket.send_to(asio::buffer(encryptedMessage), client.endpoint);
        } else {
            fullmessage = "Client " + std::to_string(clientId) + " send: " + message;
            std::string encryptedMessage = xorEncryptDecrypt(fullmessage, magic_number);
            socket.send_to(asio::buffer(encryptedMessage), client.endpoint);
        }
    }
}

std::string ServerUDP::getClientList() const {
    std::string clientList;
    for (const auto& client_pair : clients) {
        const ClientInfo& client = client_pair.second;
        clientList += "Client ID " + std::to_string(client.id) + " at " + client.endpoint.address().to_string() + ":" + std::to_string(client.endpoint.port()) + "\n";
    }
    return clientList;
}

void ServerUDP::stop()
{
    isRunning = false;
    ioContext.stop();
    socket.close();
}