/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** ClientUDP
*/

#include "UDP.hpp"

UDP::UDP(const std::string& server_ip, int client_port) : port(client_port), ioContext(), socket(ioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)), isRunning(true), endpoint_server(asio::ip::address::from_string(server_ip), port)
{
}

UDP::~UDP()
{
}

std::string xorEncryptDecrypt(const std::string& input, char key) {
    std::string output = input;
    for (char &c : output) {
        c ^= key;
    }
    return output;
}

void UDP::writeMessages(const std::string& message) {
    try {
        char key = 0x69;
        std::string encryptedMessage = xorEncryptDecrypt(message, key);
        socket.send_to(asio::buffer(encryptedMessage), endpoint_server);
    } catch (std::exception& e) {
        std::cerr << "Exception in writeMessages: " << e.what() << std::endl;
    }
}

std::string UDP::getmessage()
{
    return message_;
}

void UDP::receiveMessages() {
    try {
        std::vector<char> receive_buffer(1024);
        while (isRunning) {
            asio::ip::udp::endpoint sender_endpoint;
            size_t bytes_received = socket.receive_from(asio::buffer(receive_buffer), sender_endpoint);
            if (bytes_received > 0) {
                char key = 0x69;
                std::string received_data(receive_buffer.data(), bytes_received);
                std::string decryptedMessage = xorEncryptDecrypt(received_data, key);
                message_ = decryptedMessage;
                std::cout << "Received from the Server UDP = " << decryptedMessage << std::endl;
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in receiveMessages: " << e.what() << std::endl;
    }
}


void UDP::start() {
    std::cout << "UDP Client started on port " << port << std::endl;
    writeMessages("connection");
    std::thread receive_thread(&UDP::receiveMessages, this);
    receive_thread.detach();
}

// void UDP::start() {
//     std::cout << "UDP Client started on port " << port << std::endl;
//     std::thread receive_thread(&UDP::receiveMessages, this);
//     std::string message;
//     while (isRunning && std::getline(std::cin, message)) {
//         writeMessages(message);
//     }
//     stop();
//     receive_thread.join();
// }

void UDP::stop()
{
    ioContext.stop();
    socket.shutdown(asio::ip::udp::socket::shutdown_both);
    socket.close();
}
