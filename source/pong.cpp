/*
** EPITECH PROJECT, 2023
** pong
** File description:
** main
*/

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
    int player1 = components.createEntity();
    int player2 = components.createEntity();
    int ball = components.createEntity();

    components.addEvent(EventContener(EventContener::initFunct(trig, &components, player1),
                                        EventContener::initFunct(eff, player1)));

    components.addComponent("Speed");
    components.setComponentToEntity(player1, "Speed", Speed(0, 0));
    components.setComponentToEntity(player2, "Speed", Speed(0, 0));
    components.setComponentToEntity(ball, "Speed", Speed(1, 1));

    components.addComponent("Drawable");
    components.setComponentToEntity(player1, "Drawable", Draw("", 23, 170));
    components.setComponentToEntity(player2, "Drawable", Draw("", 23, 170));
    components.setComponentToEntity(ball, "Drawable", Draw("", 23, 23));

    components.addComponent("Position");
    components.setComponentToEntity(player1, "Position", Position(2, 230));
    components.setComponentToEntity(player2, "Position", Position(774, 230));
    components.setComponentToEntity(ball, "Position", Position(300, 300));

    components.addComponent("Control");
    components.setComponentToEntity(player1, "Control", Control(1));
    components.setComponentToEntity(player2, "Control", Control(2));

    components.addComponent("Shoot");
    components.setComponentToEntity(player1, "Shoot", Shoot(1));

    components.addComponent("HitboxR");
    components.setComponentToEntity(player1, "HitboxR", Hitbox(23, 170));
    components.setComponentToEntity(player2, "HitboxR", Hitbox(23, 170));
    components.setComponentToEntity(ball, "HitboxR", Hitbox(23, 23));

    components.addComponent("HitboxG");
    components.setComponentToEntity(ball, "HitboxG", Hitbox(23, 23));

    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
    components.runSystem();
    return 0;
}
