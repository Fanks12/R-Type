/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** rtype
*/

#include "main.hpp"

int menu(Registry *components);

int spawnEnnemy(Registry *components, int type)
{
    if (type == 1) {
        int mob = components->createEntity();
        components->setComponentToEntity(mob, "Drawable", Draw("asset/space.png", 250, 100));
        components->setComponentToEntity(mob, "HitboxR", Hitbox(250, 100));
        components->setComponentToEntity(mob, "Position", Position(WINDOW_WIDTH, WINDOW_HEIGHT / 2 - 100));
        components->setComponentToEntity(mob, "Health", Health(110));
        components->setComponentToEntity(mob, "Speed", Speed(-1));
        components->setComponentToEntity(mob, "Team", Team(2));
        // Clock *timeMob = new Clock();
        // components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, timeMob, 2),
        //                         EventContener::initFunct(Action::idShoot, components, mob, 2)));
        // ça shoot partout
    }
    if (type == 2) {
        int mob = components->createEntity();
        components->setComponentToEntity(mob, "Drawable", Draw("asset/space.png", 100, 100));
        components->setComponentToEntity(mob, "HitboxR", Hitbox(100, 100));
        components->setComponentToEntity(mob, "Position", Position(WINDOW_WIDTH, 105/*random entre 105 et WINDOW_HEIGHT - 105*/));
        components->setComponentToEntity(mob, "Health", Health(1));
        components->setComponentToEntity(mob, "Speed", Speed(-1));
        components->setComponentToEntity(mob, "Team", Team(2));
        Clock *timeMob = new Clock();
        components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, timeMob, 2),
                                EventContener::initFunct(Action::idShoot, components, mob, 2)));
    }
    return 1;
}

int eff(int id)
{
    std::cout << id << " a touche" << std::endl;
    return 1;
}

void rtype(Registry *components, int player)
{
    // Event : si joueur meurt on relance
    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, player),
                                    EventContener::initFunct(Action::restart, components, EventContener::initFunct(menu, components))));
    // // Event : compteur de point arrive a 30 = Ennemi special
    components->addEvent(EventContener(EventContener::initFunct(Action::score, components, (30 * NBPLAYER)),
                                    EventContener::initFunct(spawnEnnemy, components, 1)));
    // Event : toutes les 1-4 sec reduit par le temp de jeu envoie un ennemie de plus en plus fort
    Clock *spawn = new Clock();
    components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, spawn, 4),
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
    components->addSystem(new SystemHealth(*components));

    rtype(components, player);
    return 1;
}

int menu(Registry *components)
{
    // menu
    // int background = components->createEntity();
    // components->setComponentToEntity(background, "Drawable", Draw("asset/space.png", 800, 600));
    // components->setComponentToEntity(background, "Position", Position());

    int play = components->createEntity();
    components->setComponentToEntity(play, "Drawable", Draw("asset/space.png", 100, 100));
    components->setComponentToEntity(play, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(play, "Position", Position(600, 100));
    components->setComponentToEntity(play, "Health", Health(1));

    int join = components->createEntity();
    components->setComponentToEntity(join, "Drawable", Draw("asset/space.png", 100, 100));
    components->setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(join, "Position", Position(600, 220));

    int quit = components->createEntity();
    components->setComponentToEntity(quit, "Drawable", Draw("asset/space.png", 100, 100));
    components->setComponentToEntity(quit, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(quit, "Position", Position(600, 340));
    components->setComponentToEntity(quit, "Health", Health(1));
    // init des event qui regissent chaque bouton
    // init le joueur de base que l'on controle
    int player = components->createEntity();
    components->setComponentToEntity(player, "Drawable", Draw("asset/space.png", 100, 50));
    components->setComponentToEntity(player, "HitboxR", Hitbox(100, 50));
    components->setComponentToEntity(player, "Position", Position(50, 50));
    components->setComponentToEntity(player, "Speed", Speed());
    components->setComponentToEntity(player, "Control", Control(components->uuid));
    components->setComponentToEntity(player, "Shoot", Shoot(1));
    components->setComponentToEntity(player, "Team", Team(1));


    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, play),
                                    EventContener::initFunct(playHit, components, player, play, join, quit)));

    // event sur online button
    // -> on te donne un uuid
    // -> choisir un lobby
    // -> activé le systeme d'echange de données

    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, quit), quitHit));

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
    components.addComponent("Team");

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