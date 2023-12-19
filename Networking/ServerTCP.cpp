/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerTCP
*/

#include "ServerTCP.hpp"

ServerTCP::ServerTCP(int portTCP) : isRunning(true), port(portTCP), ioContext(), endpoint(asio::ip::make_address("127.0.0.1"), 8282), acceptor(ioContext, endpoint) {
}

ServerTCP::~ServerTCP()
{
    stop();
}

void ServerTCP::initializeAcceptor()
{
    acceptor = asio::ip::tcp::acceptor(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
}


void ServerTCP::start()
{
    initializeAcceptor();
    run();
    std::cout << "ServerTCP::start" << std::endl;
}

void ServerTCP::run()
{
    std::cout << "ServerTCP::run" << std::endl;

    for (int i = 0; i < 4; ++i) {
        workerThreads.emplace_back(&ServerTCP::workerThread, this);
    }
    try {
        std::cout << "Listens on the port " << port << std::endl;
        while (isRunning) {
            std::shared_ptr<asio::ip::tcp::socket> socket = std::make_shared<asio::ip::tcp::socket>(ioContext);
            acceptor.accept(*socket); {
                std::lock_guard<std::mutex> lock(uidMutex);
                clientQueue.push(socket);
            }
            clientCV.notify_one();
            std::cout << "Accepted a new client" << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Exception in ServerTCP::run: " << e.what() << std::endl;
    }
    for (auto& thread : workerThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void ServerTCP::workerThread()
{
    while (isRunning) {
        std::shared_ptr<asio::ip::tcp::socket> socket;
        {
            std::unique_lock<std::mutex> lock(uidMutex);
            clientCV.wait(lock, [this] { return !clientQueue.empty(); });
            socket = clientQueue.front();
            clientQueue.pop();
        }
        if (socket) {
            handleClient(socket);
        }
    }
}

void ServerTCP::handleClient(std::shared_ptr<asio::ip::tcp::socket> clientSocket)
{
    int uid = nextUID++;
    clientUIDs[clientSocket] = uid;
    Handle_message handle_message;

    std::cout << "Client " << uid << " connected" << std::endl;

    try {
        while (isRunning) {
            std::vector<char> buffer(1024);
            size_t size_msg = clientSocket->read_some(asio::buffer(buffer));
            if (size_msg == 0) {
                std::cout << "Client " << uid << " disconnected" << std::endl;
                break;
            }
            if (buffer[0] == 'a') {
                std::cout << "Client " << uid << " disconnected" << std::endl;
                break;
            }
            std::cout << "Received from Client " << uid << ": " << std::string(buffer.begin(), buffer.begin() + size_msg) << std::endl;
            std::string messageToSend = handle_message.
            Protocole(std::string(buffer.begin(), buffer.begin() + size_msg), uid);
            // std::cout << "Message to send: " << messageToSend << std::endl;
            asio::write(*clientSocket, asio::buffer(buffer.data(), size_msg));
        }
    } catch (const std::exception& e) {
        std::cerr << "Client " << uid << " disconnected" << std::endl;
    }
    clientUIDs.erase(clientSocket);
}

void ServerTCP::stop()
{
    isRunning = false;
    ioContext.stop();
}
