/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "SystemMove.hpp"
#include <iostream>
#include <unistd.h>

int main()
{
    Registry components;
    int fusée = components.createEntity();
    int voiture = components.createEntity();

    sf::Window window;
    window.create(sf::VideoMode(800, 600), "Bootstrap");

    components.addComponent("Speed");
    components.setComponentToEntity(fusée, "Speed", std::pair<int, int>(1, 1));
    components.setComponentToEntity(voiture, "Speed", std::pair<int, int>(1, 1));

    components.addComponent("Drawable");
    components.setComponentToEntity(fusée, "Drawable", std::pair<int, int>(10, 10));
    components.setComponentToEntity(voiture, "Drawable", std::pair<int, int>(10, 10));

    components.addComponent("Position");
    components.setComponentToEntity(fusée, "Position", std::pair<int, int>(20, 20));
    components.setComponentToEntity(voiture, "Position", std::pair<int, int>(10, 10));

    components.addSystem(new SystemMove(components, &window));

    while (window.isOpen()) {
        components.runSystem();
        sleep(1);
    }
}
