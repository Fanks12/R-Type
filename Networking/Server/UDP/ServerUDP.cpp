/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ServerUDP
*/

#include "ServerUDP.hpp"

ServerUDP::ServerUDP(int serv_port): port(serv_port), ioContext(), socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), isRunning(true) {

}

ServerUDP::~ServerUDP() {
    stop();
}

void ServerUDP::start() {
    run();
    std::cout << "ServerUDP::start" << std::endl;
}

void ServerUDP::stop() {
    isRunning = false;
    ioContext.stop();
    socket.close();
}

void ServerUDP::run() {
    std::cout << "ServerUDP::run" << std::endl;
    try {
        std::cout << "UDP Server listening on port " << port << std::endl;

        while (isRunning) {
            std::vector<char> buffer(1024);
            size_t size_msg = socket.receive_from(asio::buffer(buffer), endpoint);

            std::cout << "UDP Received from " << endpoint.address().to_string()
                      << " = " << std::string(buffer.begin(), buffer.begin() + size_msg) << std::endl;

            // Ici bilal, on traitera le message pour le renvoyer
            socket.send_to(asio::buffer(buffer.data(), size_msg), endpoint);
        }
    } catch (std::exception &e) {
        std::cerr << "UDP Exception: " << e.what() << std::endl;
    }
}
