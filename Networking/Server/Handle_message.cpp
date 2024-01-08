/*
** EPITECH PROJECT, 2023
** Networking
** File description:
** Handle_message
*/

#include "Handle_message.hpp"

std::string Handle_message::Protocole(const std::string message, int uid)
{
    std::string uid_str = std::to_string(uid);
    std::string messageToSend;
    if (message == "Ready") {
        messageToSend = uid_str + " Ready";
        return messageToSend;
    } else if (message == "Start") {
        messageToSend = uid_str + " Start";
        return messageToSend;
    } else if (message == "End") {
        messageToSend = uid_str + " End";
        return messageToSend;
    } else if (message == "Pause") {
        messageToSend = uid_str + " Pause";
        return messageToSend;
    } else if (message == "Resume") {
        messageToSend = uid_str + " Resume";
        return messageToSend;
    } else if (message == "Quit") {
        messageToSend = uid_str + " Quit";
        return messageToSend;
    } else {
        messageToSend = uid_str + " " + message;
        return messageToSend;
    }
}

