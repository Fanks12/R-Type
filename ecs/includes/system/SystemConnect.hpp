/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-bilal.nhari
** File description:
** SystemConnnect
*/

#ifndef SYSTEMCONNNECT_HPP_
    #define SYSTEMCONNNECT_HPP_
    #include "System.hpp"
    #include "Client.hpp"
    #include <memory>
    #include <thread>
    #include <iostream>
    #include <mutex>

    #define TCP_PORT 4242
    #define UDP_PORT 8080
    #define SERVER_IP "127.0.0.1"

class SystemConnect : public virtual System {
    public:
        SystemConnect(Registry &registries);
        ~SystemConnect() = default;

        int run();
        Client *client;
    protected:
    private:
        void sender();
        void interpreter();
        void initialisation();
};

SystemConnect::SystemConnect(Registry &registries) : System(registries), client(new Client(SERVER_IP, TCP_PORT, UDP_PORT))
{
    initialisation();
}

void SystemConnect::initialisation()
{
    client->start();
    client->WriteMessageUDP("Connecting");

    std::string message;

    while (client->getreceiveUDP() <= 0);
    message = client->getmessageUDP();


    std::string uuidStr = message.substr(message.find('=') + 1);
    _registries->uuid = std::stoi(uuidStr);

    std::thread receive_thread(&SystemConnect::interpreter, this);
    receive_thread.detach();

    // des envoie des données changé
    // recup des nouvelles données
}

int SystemConnect::run()
{
    // echange de packet
    // le joueur envoie position et score au server
    // === === ===
    // le joueur reçoit position et score du server
    sender();
    // == thread join ==
    // mis a jour
    return 1;
}

void SystemConnect::sender()
{
    SparseArray<std::any> posCompo = _registries->getComponent<std::any>("Position");
    SparseArray<std::any> controlCompo = _registries->getComponent<std::any>("Control");
    SparseArray<std::any> shootCompo = _registries->getComponent<std::any>("Shoot");
    Position index;

    for (size_t i = 0; i < _registries->entityNumbers(); i++)
        if (posCompo[i].type() != typeid(std::string) && controlCompo[i].type() != typeid(std::string)
        && std::any_cast<Control>(controlCompo[i]).control == _registries->uuid) {
            index = std::any_cast<Position>(posCompo[i]);
            client->WriteMessageUDP("i=" + std::to_string(i) + " x=" + std::to_string(index.x) + " y=" + std::to_string(index.y));
        }

    client->WriteMessageUDP("score=" + std::to_string(_registries->score));
}

void SystemConnect::interpreter()
{
    while (_registries->isRunning()) {
        if (client->getreceiveUDP() <= 0)
            continue;
        std::string input = client->getmessageUDP();
        std::string sub;

        int id = -1;
        int x = -1;
        int y = -1;
        int shoot = -1;

        for (int i = 0; i < 10; i++) {
            sub = input.substr(0, input.find(" "));
            input = input.substr(input.find(" ") + 1);
            if (sub.compare("You") == 0 || sub.compare("string") == 0)
                break;
            if (sub.substr(0, input.find("=") + 1).compare("i=") == 0)
                id = std::stoi(sub.substr(input.find("=") + 1));
            if (sub.substr(0, input.find("=") + 1).compare("x=") == 0)
                x = std::stoi(sub.substr(input.find("=") + 1));
            if (sub.substr(0, input.find("=") + 1).compare("y=") == 0)
                y = std::stoi(sub.substr(input.find("=") + 1));
            if (sub.substr(0, input.find("=") + 1).compare("shoot=") == 0)
                shoot = std::stoi(sub.substr(input.find("=") + 1));
            if (sub.substr(0, input.find("=") + 1).compare("score=") == 0) {
                _registries->score = std::stoi(sub.substr(input.find("=") + 1));
            }
        }
        if (id < _registries->entityNumbers() && id != -1 && x != -1 && y != -1 && shoot == -1)
            _registries->setComponentToEntity(id, "Position", Position(x, y));
        if (id < _registries->entityNumbers() && id != -1 && shoot != -1)
            _registries->setComponentToEntity(id, "Shoot", Shoot(shoot));
    }
}

#endif /* !SYSTEMCONNNECT_HPP_ */
