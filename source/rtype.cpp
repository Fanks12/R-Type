/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** rtype
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
    components.setComponentToEntity(background, "Drawable", /*sprite, size*/);
    components.setComponentToEntity(background, "Position", Position());
    // init des boutons play multi quit
    int play = components.createEntity();
    components.setComponentToEntity(play, "Drawable", /*sprite, size*/);
    components.setComponentToEntity(play, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(play, "Position", Position(200, 400));

    int join = components.createEntity();
    components.setComponentToEntity(join, "Drawable", /*sprite, size*/);
    components.setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(join, "Position", Position(310, 400));

    int quit = components.createEntity();
    components.setComponentToEntity(quit, "Drawable", /*sprite, size*/);
    components.setComponentToEntity(quit, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(quit, "Position", Position(420, 400));
    // init des event qui regissent chaque bouton
    // init le joueur de base que l'on controle
    int player = components.createEntity();
    components.setComponentToEntity(player, "Drawable", /*sprite, size*/);
    components.setComponentToEntity(player, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(player, "Position", Position(420, 400));
    components.setComponentToEntity(player, "Speed", Speed());
    components.setComponentToEntity(player, "Control", Control(1));
    components.setComponentToEntity(player; "Shooy", Shoot(1));
    // si multi init les joueur qui s'ajoutent

    // les boutons du menu disparraissent
    // les regles de jeu se mettent en place
    // tout les 1 - 4 sec (en fonction du nombre de joueur) un ennemy aleatoire apparait
    // un compteur de kill interne prend en consideration l'avancé de la quete spacial
    // quand compteur complete les joueurs entre en phase finale
    // 5 etoiles GTA ya le boss qui spawn et c'est la derka partout
    return 0;
}