/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerTCP
*/

#include "ServerTCP.hpp"


ServerTCP::ServerTCP(int portTCP) : isRunning(true), port(portTCP), ioContext(), endpoint(asio::ip::make_address("127.0.0.1"), 8282), acceptor(ioContext, endpoint)
{
}

ServerTCP::~ServerTCP()
{
}

void ServerTCP::initializeAcceptor()
{
    acceptor = asio::ip::tcp::acceptor(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
}


void ServerTCP::start()
{
    initializeAcceptor();
    std::cout << "ServerTCP::start" << std::endl;
    run();
}

void ServerTCP::run()
{
    try {
        for (int i = 0; i < 4; ++i) {
            workerThreads.emplace_back(&ServerTCP::workerThread, this);
        }

        std::cout << "Listens on the port " << port << std::endl;
        while (isRunning) {
            std::shared_ptr<asio::ip::tcp::socket> socket = std::make_shared<asio::ip::tcp::socket>(ioContext);
            acceptor.accept(*socket);
            {
                std::lock_guard<std::mutex> lock(uidMutex);
                clientQueue.push(socket);
            }
            clientCV.notify_one();
            std::cout << "Accepted a new client" << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "Exception in ServerTCP::run: " << e.what() << std::endl;
    }

    for (auto &thread : workerThreads) {
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
    data.addClient(clientSocket, uid);
    Handle_message handle_message;

    std::cout << "Client " << uid << " connected" << std::endl;
    Packet uidPacket;
    uidPacket.Magic_number = 42;
    clientSocket->write_some(asio::buffer(&uidPacket, sizeof(Packet)));

    try {
        while (isRunning) {
            Packet receivedPacket;
            size_t bytes_received = clientSocket->read_some(asio::buffer(&receivedPacket, sizeof(Packet)));

            if (bytes_received == sizeof(Packet)) {
                std::cout << "Received Magic_number from Client " << uid << ": " << receivedPacket.Magic_number << std::endl;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Client " << uid << " disconnected: " << e.what() << std::endl;
    }
    clientUIDs.erase(clientSocket);
}

bool ServerTCP::areAllClientsReady() const
{
    return readyClients.size() == data.getClients().size();
}

void ServerTCP::stop()
{
    isRunning = false;
    ioContext.stop();
}
