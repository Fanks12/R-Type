/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

// #include "main.hpp"
#include "SystemDraw.hpp"
#include "SystemMove.hpp"
#include "SystemControl.hpp"
#include "SystemShoot.hpp"
#include <iostream>
#include <unistd.h>
#include "Client.hpp"
#include <thread>

int main()
{
    Registry components;
    components.uuid = 1;
    int fusée = components.createEntity();
    int voiture = components.createEntity();
    int mob = components.createEntity();
    Client *client = &components.client;

    std::thread clientThread([client]() {
        client->start();
    });

    components.addComponent("Speed");
    components.setComponentToEntity(fusée, "Speed", std::pair<int, int>(0, 0));
    components.setComponentToEntity(voiture, "Speed", std::pair<int, int>(0, 0));

    components.addComponent("Drawable");
    components.setComponentToEntity(fusée, "Drawable", std::pair<int, int>(100, 100));
    components.setComponentToEntity(voiture, "Drawable", std::pair<int, int>(100, 100));
    components.setComponentToEntity(mob, "Drawable", std::pair<int, int>(50, 100));

    components.addComponent("Position");
    components.setComponentToEntity(fusée, "Position", std::pair<int, int>(100, 200));
    components.setComponentToEntity(voiture, "Position", std::pair<int, int>(100, 305));
    components.setComponentToEntity(mob, "Position", std::pair<int, int>(600, 200));

    components.addComponent("Control");
    components.setComponentToEntity(fusée, "Control", 0);
    components.setComponentToEntity(voiture, "Control", 1);

    components.addComponent("Shoot");
    components.setComponentToEntity(fusée, "Shoot", 0);

    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
    std::thread sysThread([&components]() {
        components.runSystem();
    });
    clientThread.join();
    sysThread.join();
    //display position
    // std::cout << "fusée: " << std::any_cast<std::pair<int, int>>(components.getComponent<std::any>("Position")[fusée]).first << std::endl;
    // SparseArray<std::any> speedCompo = components.getComponent<std::any>("Position");
    // std::pair<int, int> caca(1, 4);
    // components.getComponent<std::any>("Position")[fusée] = caca;
    // std::cout << "fusée: " << std::any_cast<std::pair<int, int>>(components.getComponent<std::any>("Position")[fusée]).first << std::endl;
    // std::cout << "voiture: " << std::any_cast<std::pair<int, int>>(components.getComponent<std::any>("Position")[voiture]).first << " " << std::any_cast<std::pair<int, int>>(components.getComponent<std::any>("Position")[voiture]).second << std::endl;

    // Load a sprite to display
    // sf::RectangleShape square(sf::Vector2f(10, 10));

    //zega.system;

    // on init tout les system dans system
    // quand on appel play ça met en marche tout les sys de base

    // Start the game loop

    /*try {
        SparseArray<std::string> Test(10);

        std::cout << Test[9] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }*/

    return 0;
}
