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
        Client client;
};

SystemConnect::SystemConnect(Registry &registries) : System(registries), client(SERVER_IP, TCP_PORT, UDP_PORT)
{
    // envoie une premier message pour avoir la connection
    // recup l'uuid
    int prevUuid = registries.uuid;
    SparseArray<std::any> controlCompo = _registries->getComponent<std::any>("Control");

    client.start();
    client.WriteMessageUDP("ça joue");
    // registries.uuid = uuid;
    // for (size_t i = 0; i < _registries->entityNumbers(); i++)
    //     if (controlCompo[i].type() != typeid(std::string)
    //     && std::any_cast<Control>(controlCompo[i]).control == prevUuid)
    //         registries.setComponentToEntity(i, "Control", Control(registries.uuid));

    // des envoie des données changé
    // recup des nouvelles données

}

int SystemConnect::run()
{
    // echange de packet
    // le joueur envoie position et score au server
    // exemple : pour chaque case du component Position envoyé :"i=0 c=Position x=20 y=30"
    // le joueur reçoit position et score du server
    // toutes les entités qui ont string en position = removeEntity(id);
    // mis a jour
    return 1;
}

#endif /* !SYSTEMCONNNECT_HPP_ */
