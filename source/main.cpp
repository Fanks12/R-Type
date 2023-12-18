/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "SystemMove.hpp"
#include <iostream>

int main()
{
    Registry components;
    int fusée = components.createEntity();
    int voiture = components.createEntity();

    sf::Window window;
    window.create(sf::VideoMode(800, 600), "Bootstrap");

    components.addComponent("Speed");
    components.setComponentToEntity(fusée, "Speed", 5);
    components.setComponentToEntity(voiture, "Speed", 2);

    components.addComponent("Drawable");
    components.setComponentToEntity(fusée, "Drawable", std::pair<int, int>(10, 10));
    components.setComponentToEntity(voiture, "Drawable", std::pair<int, int>(10, 10));

    components.addComponent("Position");
    components.setComponentToEntity(fusée, "Position", std::pair<int, int>(20, 20));
    components.setComponentToEntity(voiture, "Position", std::pair<int, int>(10, 10));

    components.addSystem(new SystemMove(components, &window));
    components.runSystem();
}
