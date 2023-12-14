/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerTCP
*/

#include "ServerTCP.hpp"

ServerTCP::ServerTCP(int portTCP) : isRunning(true), port(portTCP), ioContext(), endpoint(asio::ip::make_address("127.0.0.1"), 8282), acceptor(ioContext, endpoint) {
}

ServerTCP::~ServerTCP() {
    stop();
}

void ServerTCP::initializeAcceptor() {
    acceptor = asio::ip::tcp::acceptor(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
}


void ServerTCP::start() {
    initializeAcceptor();
    run();
    std::cout << "ServerTCP::start" << std::endl;
}

void ServerTCP::run() {
    std::cout << "ServerTCP::run" << std::endl;
    try {
        std::cout << "Listens on the port " << port << std::endl;
        while (isRunning) {
            std::shared_ptr<asio::ip::tcp::socket> socket = std::make_shared<asio::ip::tcp::socket>(ioContext);
            acceptor.accept(*socket);
            std::thread([this, socket]() {
                handleClient(socket);
            }).detach();
        }
    } catch (std::exception &e) {
        std::cerr << "Exception in ServerTCP::run: " << e.what() << std::endl;
    }
}

void ServerTCP::handleClient(std::shared_ptr<asio::ip::tcp::socket> clientSocket) {
    try {
        while (isRunning) {
            std::vector<char> buffer(1024);
            size_t size_msg = clientSocket->read_some(asio::buffer(buffer));

            if (size_msg == 0) {
                std::cout << "Client disconnected" << std::endl;
                break;
            }

            std::cout << "Received from " << clientSocket->remote_endpoint().address().to_string()
                      << " = " << std::string(buffer.begin(), buffer.begin() + size_msg) << std::endl;

            // Ici nelly, on traite le message avant de le renvoyer
            asio::write(*clientSocket, asio::buffer(buffer.data(), size_msg));
        }
    } catch (std::exception &e) {
        std::cerr << "Exception in handleClient: " << e.what() << std::endl;
    }
}

void ServerTCP::stop() {
    isRunning = false;
    ioContext.stop();
}