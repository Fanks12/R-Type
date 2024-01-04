/*
** EPITECH PROJECT, 2024
** pong
** File description:
** pong
*/

#include "SystemDraw.hpp"
#include "SystemMove.hpp"
#include "SystemControl.hpp"
#include "SystemShoot.hpp"
#include <iostream>
#include <unistd.h>

int main()
{
    Registry components;

    // menu
    // init une entity qui va faire le background
    int background = components.createEntity();
    components.setComponentToEntity(background, "Drawable", Draw("", 700, 800));
    components.setComponentToEntity(background, "Position", Position());
    // init des boutons play multi quit
    int play = components.createEntity();
    components.setComponentToEntity(play, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(play, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(play, "Position", Position(200, 400));

    int join = components.createEntity();
    components.setComponentToEntity(join, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(join, "Position", Position(310, 400));

    int quit = components.createEntity();
    components.setComponentToEntity(quit, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(quit, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(quit, "Position", Position(420, 400));
    // init des event qui regissent chaque bouton
    // init le joueur de base que l'on controle
    int player = components.createEntity();
    components.setComponentToEntity(player, "Drawable", Draw("", 23, 100));
    components.setComponentToEntity(player, "HitboxR", Hitbox(23, 100));
    components.setComponentToEntity(player, "Position", Position(42, 42));
    components.setComponentToEntity(player, "Speed", Speed());
    components.setComponentToEntity(player, "Control", Control(1));
    // si multi init les joueur qui s'ajoutent

    return 0;
}