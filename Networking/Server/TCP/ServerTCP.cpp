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
    data.addClient(clientSocket, uid);
    Handle_message handle_message;

    std::cout << "Client " << uid << " connected" << std::endl;
    asio::write(*clientSocket, asio::buffer(std::to_string(uid)));

    try {
        while (isRunning) {
            std::vector<char> buffer(1024);
            size_t size_msg = clientSocket->read_some(asio::buffer(buffer));
            if (size_msg == 0 || strcmp(std::string(buffer.begin(), buffer.begin() + size_msg).c_str(), "quit") == 0) {
                std::cout << "Client " << uid << " disconnected" << std::endl;
                break;
            }
            if (strcmp(std::string(buffer.begin(), buffer.begin() + size_msg).c_str(), "Ready") == 0) {
                {
                    std::lock_guard<std::mutex> lock(readyClientsMutex);
                    readyClients.insert(clientSocket);
                }
                if (areAllClientsReady()) {
                    std::cout << "All clients are ready" << std::endl;
                    for (const auto& clientInfo : data.getClients()) {
                        std::cout << "Send to Client " << clientInfo.uid << ": " << "Start" << std::endl;
                        asio::write(*(clientInfo.socket), asio::buffer("Start"));
                    }
                }
            }
            std::cout << "Received from Client " << uid << ": " << std::string(buffer.begin(), buffer.begin() + size_msg) << std::endl;
            std::string messageToSend = handle_message.
            Protocole(std::string(buffer.begin(), buffer.begin() + size_msg), uid);
            for (const auto& clientInfo : data.getClients()) {
                std::cout << "Send to Client " << clientInfo.uid << ": " << messageToSend << std::endl;
                asio::write(*(clientInfo.socket), asio::buffer(messageToSend));
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Client " << uid << " disconnected" << std::endl;
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
