/*
** EPITECH PROJECT, 2023
** pong
** File description:
** main
*/

#include "main.hpp"

int main()
{
    Registry components;

    components.addComponent("Drawable");
    components.addComponent("Position");
    components.addComponent("HitboxR");
    components.addComponent("HitboxG");
    components.addComponent("Speed");
    components.addComponent("Control");
    components.addComponent("Shoot");
    components.addComponent("Damage");
    components.addComponent("Health");

    int play = components.createEntity();
    components.setComponentToEntity(play, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(play, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(play, "Position", Position(600, 100));
    components.setComponentToEntity(play, "Health", Health(1));

    int join = components.createEntity();
    components.setComponentToEntity(join, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(join, "Position", Position(600, 220));
    components.setComponentToEntity(join, "Health", Health(1));

    int quit = components.createEntity();
    components.setComponentToEntity(quit, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(quit, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(quit, "Position", Position(600, 340));
    components.setComponentToEntity(quit, "Health", Health(1));

    int player = components.createEntity();
    components.setComponentToEntity(player, "Drawable", Draw("", 23, 170));
    components.setComponentToEntity(player, "HitboxR", Hitbox(23, 170));
    components.setComponentToEntity(player, "Position", Position(20, 50));
    components.setComponentToEntity(player, "Speed", Speed());
    components.setComponentToEntity(player, "Control", Control(1));

    int player2 = components.createEntity();
    components.setComponentToEntity(player2, "Drawable", Draw("", 23, 170));
    components.setComponentToEntity(player2, "HitboxR", Hitbox(23, 170));
    components.setComponentToEntity(player2, "Position", Position(750, 50));
    components.setComponentToEntity(player2, "Speed", Speed());
    components.setComponentToEntity(player2, "Control", Control(2));

    int ball = components.createEntity();
    components.setComponentToEntity(ball, "Drawable", Draw("", 23, 23));
    components.setComponentToEntity(ball, "HitboxR", Hitbox(23, 23));
    components.setComponentToEntity(ball, "Position", Position(400, 250));
    components.setComponentToEntity(ball, "Speed", Speed());


    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemHitbox(components));
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
    components.runSystem();

    components.removeEntity(play);
    components.removeEntity(join);
    components.removeEntity(quit);

    return 0;
}