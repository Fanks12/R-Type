/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** rtype
*/

#include "main.hpp"

int main()
{
    Registry components;

    // menu
    components.addComponent("Drawable");
    components.addComponent("Position");
    components.addComponent("HitboxR");
    components.addComponent("HitboxG");
    components.addComponent("Speed");
    components.addComponent("Control");
    components.addComponent("Shoot");
    components.addComponent("Damage");
    components.addComponent("Health");
    // init une entity qui va faire le background
    // int background = components.createEntity();
    // components.setComponentToEntity(background, "Drawable", Draw("", 700, 800));
    // components.setComponentToEntity(background, "Position", Position());
    // init des boutons play multi quit
    int play = components.createEntity();
    components.setComponentToEntity(play, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(play, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(play, "Position", Position(600, 100));

    int join = components.createEntity();
    components.setComponentToEntity(join, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(join, "Position", Position(600, 220));

    int quit = components.createEntity();
    components.setComponentToEntity(quit, "Drawable", Draw("", 100, 100));
    components.setComponentToEntity(quit, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(quit, "Position", Position(600, 340));
    // init des event qui regissent chaque bouton
    // init le joueur de base que l'on controle
    int player = components.createEntity();
    components.setComponentToEntity(player, "Drawable", Draw("", 100, 50));
    components.setComponentToEntity(player, "HitboxR", Hitbox(100, 100));
    components.setComponentToEntity(player, "Position", Position(50, 50));
    components.setComponentToEntity(player, "Speed", Speed());
    components.setComponentToEntity(player, "Control", Control(1));
    components.setComponentToEntity(player, "Shoot", Shoot(1));

    // event
    // if hp play < 100 fait la moula puis remet les pv a 100

    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemHitbox(components));
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
    components.runSystem();
    // si multi init les joueur qui s'ajoutent

    // dans le fonction event
    components.removeEntity(play);
    components.removeEntity(join);
    components.removeEntity(quit);
    // Event : si joueur meurt on relance
    // Event : toutes les 1-4 sec envoie un ennemie
    // Event : compteur de point arrive a 30 = Ennemi special
    // les regles de jeu se mettent en place
    // tout les 1 - 4 sec (en fonction du nombre de joueur) un ennemy aleatoire apparait
    // un compteur de kill interne prend en consideration l'avancé de la quete spacial
    // quand compteur complete les joueurs entre en phase finale
    // 5 etoiles GTA ya le boss qui spawn et c'est la derka partout
    return 0;
}