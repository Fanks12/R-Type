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
    protected:
    private:
        void sender();
        void interpreter();
        void initialisation();
        Client client;
};

SystemConnect::SystemConnect(Registry &registries) : System(registries), client(SERVER_IP, TCP_PORT, UDP_PORT)
{
    initialisation();
}

void SystemConnect::initialisation()
{
    // envoie une premier message pour avoir la connection
    // recup l'uuid

    int prevUuid = _registries->uuid;
    SparseArray<std::any> controlCompo = _registries->getComponent<std::any>("Control");

    client.start();

    //recup message
    // ==== dans thread
    std::string message = client.getmessageUDP();
    // std::getline(std::cin, message);
    // ====

    std::string uuidStr = message.substr(message.find('=') + 1);
    int uuid = std::stoi(uuidStr);

    for (size_t i = 0; i < _registries->entityNumbers(); i++)
        if (controlCompo[i].type() != typeid(std::string)
        && std::any_cast<Control>(controlCompo[i]).control == prevUuid)
            _registries->setComponentToEntity(i, "Control", Control(_registries->uuid));

    // des envoie des données changé
    // recup des nouvelles données
}

int SystemConnect::run()
{
    // echange de packet
    // le joueur envoie position et score au server
    sender();
    // === === ===
    // le joueur reçoit position et score du server
    interpreter();
    // == thread join ==
    // mis a jour
    return 1;
}

void SystemConnect::sender()
{
    SparseArray<std::any> posCompo = _registries->getComponent<std::any>("Position");
    Position index;

    for (size_t i = 0; i < _registries->entityNumbers(); i++)
        if (posCompo[i].type() != typeid(std::string)) {
            index = std::any_cast<Position>(posCompo[i]);
            std::cout << "i=" << i << "x=" << index.x << "y=" << index.y << std::endl;
        } else
            std::cout << "i=" << i << "string" << std::endl;
}

void SystemConnect::interpreter()
{
    std::string input = client.getmessageUDP(/*_registries->uuid*/);

    std::istringstream stream(input);
    std::string token;

    int iValue = 0;
    int xValue = 0;
    int yValue = 0;
    int sValue = 0;
    int tValue = 0;

    while (stream >> token) {
        if (token == "i=0")
            stream >> iValue;
        if (token == "posx=")
            stream >> xValue;
        if (token == "posy=")
            stream >> yValue;
        if (token == "shoot=")
            stream >> tValue;
        if (token == "score=") {
            stream >> sValue;
            _registries->score = sValue;
        }
        if (token == "string")
            return;
    }
    if (iValue < _registries->entityNumbers() && tValue == 0 && sValue == 0)
        _registries->setComponentToEntity(iValue, "Position", Position(xValue, yValue));
    else if (iValue < _registries->entityNumbers() && sValue == 0)
        _registries->setComponentToEntity(iValue, "Shoot", Shoot(tValue));
}

#endif /* !SYSTEMCONNNECT_HPP_ */
