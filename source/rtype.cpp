/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** rtype
*/

#include "main.hpp"

int menu(Registry *components);

int spawnEnnemy(Registry *registries, int type)
{
    // if (type == 1)
    // if (type == 2)
    return 1;
}

void rtype(Registry *components, int player)
{
    // Event : si joueur meurt on relance
    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, player),
                                    EventContener::initFunct(Action::restart, components, EventContener::initFunct(menu, components))));
    // Event : compteur de point arrive a 30 = Ennemi special
    components->addEvent(EventContener(EventContener::initFunct(Action::score, components, (30 * NBPLAYER)),
                                    EventContener::initFunct(spawnEnnemy, components, 1)));
    // Event : toutes les 1-4 sec reduit par le temp de jeu envoie un ennemie de plus en plus fort
    components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, Clock(), (-NBPLAYER + 5)),
                                    EventContener::initFunct(spawnEnnemy, components, 2)));

    // quand compteur complete les joueurs entre en phase finale
    // 5 etoiles GTA ya le boss qui spawn et c'est la derka partout
}

int quitHit()
{
    return 0;
}

int playHit(Registry *components, int player, int play, int join, int quit)
{
    components->removeEntity(play);
    components->removeEntity(join);
    components->removeEntity(quit);
    rtype(components, player);
    return 1;
}

int menu(Registry *components)
{
    // menu
    int play = components->createEntity();
    components->setComponentToEntity(play, "Drawable", Draw("", 100, 100));
    components->setComponentToEntity(play, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(play, "Position", Position(600, 100));

    int join = components->createEntity();
    components->setComponentToEntity(join, "Drawable", Draw("", 100, 100));
    components->setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(join, "Position", Position(600, 220));

    int quit = components->createEntity();
    components->setComponentToEntity(quit, "Drawable", Draw("", 100, 100));
    components->setComponentToEntity(quit, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(quit, "Position", Position(600, 340));
    // init des event qui regissent chaque bouton
    // init le joueur de base que l'on controle
    int player = components->createEntity();
    components->setComponentToEntity(player, "Drawable", Draw("", 100, 50));
    components->setComponentToEntity(player, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(player, "Position", Position(50, 50));
    components->setComponentToEntity(player, "Speed", Speed());
    components->setComponentToEntity(player, "Control", Control(1));
    components->setComponentToEntity(player, "Shoot", Shoot(1));

    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, play),
                                    EventContener::initFunct(playHit, components, player, play, join, quit)));

    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, quit), quitHit));
    // event
    // if hp play < 100 fait la moula puis remet les pv a 100
    components->runSystem();
    // si multi init les joueur qui s'ajoutent
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

    SystemDraw *Drawing = new SystemDraw(components);
    components.addSystem(Drawing);
    components.addSystem(new SystemHitbox(components));
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window));
    components.addSystem(new SystemShoot(components));
}

int main()
{
    Registry components;

    initCore(components);
    menu(&components);

    return 0;
}