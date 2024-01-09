/*
** EPITECH PROJECT, 2023
** pong
** File description:
** main
*/

#include "main.hpp"

void spawn_ball(Registry *components)
{
    int ball = components->createEntity();
    components->setComponentToEntity(ball, "Drawable", Draw("asset/space.png", 50, 50));
    components->setComponentToEntity(ball, "HitboxR", Hitbox(50, 50));
    components->setComponentToEntity(ball, "Position", Position(50, 50));
    components->setComponentToEntity(ball, "Speed", Speed(1, 1));
    components->setComponentToEntity(ball, "Team", Team(0));
}

int play(Registry *components)
{
    int player = components->createEntity();
    components->setComponentToEntity(player, "Drawable", Draw("asset/space.png", 23, 170));
    components->setComponentToEntity(player, "HitboxR", Hitbox(23, 170));
    components->setComponentToEntity(player, "Position", Position(23, 50));
    components->setComponentToEntity(player, "Speed", Speed());
    components->setComponentToEntity(player, "Control", Control(1));
    components->setComponentToEntity(player, "Team", Team(1));

    int player2 = components->createEntity();
    components->setComponentToEntity(player2, "Drawable", Draw("asset/space.png", 23, 170));
    components->setComponentToEntity(player2, "HitboxR", Hitbox(23, 170));
    components->setComponentToEntity(player2, "Position", Position(750, 50));
    components->setComponentToEntity(player2, "Speed", Speed());
    components->setComponentToEntity(player2, "Control", Control(2));
    components->setComponentToEntity(player2, "Team", Team(2));

    // components->addEvent(EventContener(EventContener::initFunct(Action::XPlayerConnected, components, spawn_ball), spawn_ball));
    components->runSystem();
    return 0;
}

void initCore(Registry &components)
{
    components.addComponent("Drawable");
    components.addComponent("Position");
    components.addComponent("HitboxR");
    components.addComponent("HitboxG");
    components.addComponent("Speed");
    components.addComponent("Control");
    components.addComponent("Shoot");
    components.addComponent("Damage");
    components.addComponent("Health");
    components.addComponent("Team");

    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemHealth(components));
    components.addSystem(new SystemHitbox(components));
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
}

int main()
{
    Registry components;

    initCore(components);
    play(&components);

    return 0;
}