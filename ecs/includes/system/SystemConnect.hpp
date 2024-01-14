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
        int safeStoi(std::string message);
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
    usleep(1000);
    message = client->getmessageUDP();
    std::cout << message << std::endl;


    std::string uuidStr = message.substr(message.find('=') + 1);
    _registries->uuid = safeStoi(uuidStr);

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
    Shoot indux;

    for (size_t i = 0; i < _registries->entityNumbers(); i++) {
        if (posCompo[i].type() != typeid(std::string) && controlCompo[i].type() != typeid(std::string)
        && std::any_cast<Control>(controlCompo[i]).control == _registries->uuid) {
            index = std::any_cast<Position>(posCompo[i]);
            client->WriteMessageUDP("i=" + std::to_string(i) + " x=" + std::to_string(index.x) + " y=" + std::to_string(index.y));
        }
        if (shootCompo[i].type() != typeid(std::string) && controlCompo[i].type() != typeid(std::string)
        && std::any_cast<Control>(controlCompo[i]).control == _registries->uuid) {
            indux = std::any_cast<Shoot>(shootCompo[i]);
            if (indux.shoot)
                client->WriteMessageUDP("i=" + std::to_string(i) + " s=1");
        }
    }

    client->WriteMessageUDP("score=" + std::to_string(_registries->score));
}

int SystemConnect::safeStoi(std::string message)
{
    try {
        int number = std::stoi(message);
        return number;
    } catch (const std::invalid_argument& e) {
        return -1;
    }
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

        // std::cout << input << std::endl;

        for (int i = 0; i < 10; i++) {
            sub = input.substr(0, input.find(" "));
            input = input.substr(input.find(" ") + 1);
            if (sub.compare("You") == 0 || sub.compare("string") == 0)
                break;
            if (sub.substr(0, input.find("=") + 1).compare("i=") == 0) {
                // std::cout << sub << std::endl;
                id = safeStoi(sub.substr(input.find("=") + 1));
            }
            if (sub.substr(0, input.find("=") + 1).compare("x=") == 0)
                x = safeStoi(sub.substr(input.find("=") + 1));
            if (sub.substr(0, input.find("=") + 1).compare("y=") == 0)
                y = safeStoi(sub.substr(input.find("=") + 1));
            if (sub.substr(0, input.find("=") + 1).compare("s=") == 0) {
                shoot = safeStoi(sub.substr(input.find("=") + 1));
            }
            if (sub.substr(0, input.find("=") + 1).compare("score=") == 0) {
                _registries->score = safeStoi(sub.substr(input.find("=") + 1));
            }
        }
        // std::cout << id << shoot << std::endl;

        if (id < _registries->entityNumbers() && id != -1 && x != -1 && y != -1)
            _registries->setComponentToEntity(id, "Position", Position(x, y));
        if (id < _registries->entityNumbers() && id != -1 && shoot != -1)
            _registries->setComponentToEntity(id, "Shoot", Shoot(shoot));
    }
}

#endif /* !SYSTEMCONNNECT_HPP_ */
