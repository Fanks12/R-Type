/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "main.hpp"
#include "SystemDraw.hpp"
#include "SystemMove.hpp"

int main()
{
    Registry components;
    int fusée = components.createEntity();
    int voiture = components.createEntity();

    components.addComponent("Speed");
    components.setComponentToEntity(fusée, "Speed", 5);
    components.setComponentToEntity(voiture, "Speed", 2);

    components.addComponent("Drawable");
    components.setComponentToEntity(fusée, "Drawable", std::pair<int, int>(10, 10));
    components.setComponentToEntity(voiture, "Drawable", std::pair<int, int>(10, 10));

    components.addComponent("Position");
    components.setComponentToEntity(fusée, "Position", std::pair<int, int>(20, 20));
    components.setComponentToEntity(voiture, "Position", std::pair<int, int>(10, 10));

    components.addSystem(new SystemDraw(components));
    components.runSystem();

    // components.addSystem(new SystemMove(components));
    // components.runSystem();

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