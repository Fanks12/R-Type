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

bool trig(Registry *r, int id)
{
    SparseArray<std::any> shootCompo = r->getComponent<std::any>("Shoot");

    if (std::any_cast<Shoot>(shootCompo[id]).shoot == 1)
        return true;
    return false;
}

void eff(int id)
{
    std::cout << id << " a tirer" << std::endl;
}

int main()
{
    Registry components;
    int fusée = components.createEntity();
    int voiture = components.createEntity();
    int mob = components.createEntity();

    // Event test;
    // test.setAction(trig, &components, fusée);
    // test.setReaction(eff, fusée);

    components.addEvent(EventContener(EventContener::initFunct(trig, &components, fusée),
                                        EventContener::initFunct(eff, fusée)));

    components.addComponent("Speed");
    components.setComponentToEntity(fusée, "Speed", Speed(0, 0));
    components.setComponentToEntity(voiture, "Speed", Speed(0, 0));

    components.addComponent("Drawable");
    components.setComponentToEntity(fusée, "Drawable", std::pair<int, int>(100, 100));
    components.setComponentToEntity(voiture, "Drawable", std::pair<int, int>(100, 100));
    components.setComponentToEntity(mob, "Drawable", std::pair<int, int>(50, 100));

    components.addComponent("Position");
    components.setComponentToEntity(fusée, "Position", Position(100, 200));
    components.setComponentToEntity(voiture, "Position", Position(100, 305));
    components.setComponentToEntity(mob, "Position", Position(600, 200));

    components.addComponent("Control");
    components.setComponentToEntity(fusée, "Control", Control(1));
    components.setComponentToEntity(voiture, "Control", Control(2));

    components.addComponent("Shoot");
    components.setComponentToEntity(fusée, "Shoot", Shoot(1));

    components.addComponent("HitboxR");
    components.setComponentToEntity(fusée, "HitboxR", Hitbox(100, 200, 200, 300));
    components.setComponentToEntity(mob, "HitboxR", Hitbox(600, 200, 650, 300));

    components.addComponent("HitboxG");
    components.setComponentToEntity(mob, "HitboxG", Hitbox(600, 200, 650, 300));

    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
    components.runSystem();

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
