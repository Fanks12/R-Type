/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** rtype
*/

#include "main.hpp"

int menu(Registry *components);

int YouWin(Registry *components) {
    int YouWin = components->createEntity();
    components->setComponentToEntity(YouWin, "Drawable", Draw(15, 818, 815));
    components->setComponentToEntity(YouWin, "Position", Position());
    return 1;
}

int YouLose(Registry *components) {
    int YouLose = components->createEntity();
    components->setComponentToEntity(YouLose, "Drawable", Draw(16, 818, 815));
    components->setComponentToEntity(YouLose, "Position", Position());
    return 1;
}

int randomInt(int seed, int min, int max)
{
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

int spawnEnnemy(Registry *components, int type)
{
    if (type == 1) {
        components->score++;
        int mob = components->createEntity();
        components->setComponentToEntity(mob, "Drawable", Draw(3, 500, 500));
        components->setComponentToEntity(mob, "HitboxR", Hitbox((500 * 0.4), (500 * 0.4)));
        components->setComponentToEntity(mob, "HitboxG", Hitbox((500 * 0.4), (500 * 0.4)));
        components->setComponentToEntity(mob, "Damage", Damage(100));
        components->setComponentToEntity(mob, "Position", Position(WINDOW_WIDTH, WINDOW_HEIGHT / 2 - 100));
        components->setComponentToEntity(mob, "Health", Health(110));
        components->setComponentToEntity(mob, "Speed", Speed(-1));
        components->setComponentToEntity(mob, "Team", Team(2));
        components->addEvent(EventContener(EventContener::initFunct(Action::posLowerX, components, mob, WINDOW_WIDTH - 250),
                                EventContener::initFunct(Action::idSpeed, components, mob, 0)));
        Clock *shootMob = new Clock();
        components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, shootMob, 1),
                                EventContener::initFunct(Action::idShoot, components, mob, 2)));
        Clock *timeMob = new Clock();
        components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, timeMob, 2),
                                EventContener::initFunct(spawnEnnemy, components, 2)));
        components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, mob),
                                EventContener::initFunct(YouWin, components)));
    }
    if (type == 2) {
        int mob = components->createEntity();
        components->setComponentToEntity(mob, "Drawable", Draw(2, 500, 500));
        components->setComponentToEntity(mob, "HitboxR", Hitbox((500 * 0.2), (500 * 0.2)));
        components->setComponentToEntity(mob, "HitboxG", Hitbox((500 * 0.2), (500 * 0.2)));
        components->setComponentToEntity(mob, "Damage", Damage(10));
        components->setComponentToEntity(mob, "Position", Position(WINDOW_WIDTH, randomInt(components->score, 105, WINDOW_HEIGHT - 105)/*random entre 105 et WINDOW_HEIGHT - 105*/));
        components->setComponentToEntity(mob, "Health", Health(1));
        components->setComponentToEntity(mob, "Speed", Speed(-1));
        components->setComponentToEntity(mob, "Team", Team(2));
        components->addEvent(EventContener(EventContener::initFunct(Action::posLowerX, components, mob, WINDOW_WIDTH - randomInt(components->score, 100, WINDOW_HEIGHT - 300)),
                                EventContener::initFunct(Action::idSpeed, components, mob, 0)));
        Clock *timeMob = new Clock();
        components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, timeMob, 1),
                                EventContener::initFunct(Action::idShoot, components, mob, 2)));
    }
    return 1;
}

void rtype(Registry *components, int player)
{
    // // Event : compteur de point arrive a 30 = Ennemi special
    components->addEvent(EventContener(EventContener::initFunct(Action::score, components, (10 * NBPLAYER)),
                                    EventContener::initFunct(spawnEnnemy, components, 1)));
    // Event : toutes les 1-4 sec reduit par le temp de jeu envoie un ennemie de plus en plus fort
    Clock *spawn = new Clock();
    components->addEvent(EventContener(EventContener::initFunct(Action::everyXSecond, spawn, 3),
                                    EventContener::initFunct(spawnEnnemy, components, 2)));

    // Event : si joueur meurt on relance
    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, player),
                                    EventContener::initFunct(YouLose, components)));
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

// int joinHit(Registry *components)
// {
//     components->addSystem(new SystemConnect(*components));

//     return 1;
// }

int menu(Registry *components)
{
    // menu
    int background = components->createEntity();
    components->setComponentToEntity(background, "Drawable", Draw(10, 1280, 720));
    components->setComponentToEntity(background, "Position", Position());

    int play = components->createEntity();
    components->setComponentToEntity(play, "Drawable", Draw(4, 152, 84));
    components->setComponentToEntity(play, "HitboxR", Hitbox(152, 84));
    components->setComponentToEntity(play, "Position", Position(600, 100));
    components->setComponentToEntity(play, "Health", Health(1));

    int join = components->createEntity();
    components->setComponentToEntity(join, "Drawable", Draw(5, 100, 100));
    components->setComponentToEntity(join, "HitboxR", Hitbox(100, 100));
    components->setComponentToEntity(join, "Position", Position(600, 220));
    components->setComponentToEntity(join, "Health", Health(1));

    int quit = components->createEntity();
    components->setComponentToEntity(quit, "Drawable", Draw(6, 170, 90));
    components->setComponentToEntity(quit, "HitboxR", Hitbox(170, 90));
    components->setComponentToEntity(quit, "Position", Position(600, 340));
    components->setComponentToEntity(quit, "Health", Health(1));
    // init des event qui regissent chaque bouton
    // init le joueur de base que l'on controle
    int player = components->createEntity();
    components->setComponentToEntity(player, "Drawable", Draw(1, 519, 480));
    components->setComponentToEntity(player, "HitboxR", Hitbox((519 * 0.2), (480 * 0.2)));
    components->setComponentToEntity(player, "Position", Position(50, 50));
    components->setComponentToEntity(player, "Speed", Speed());
    components->setComponentToEntity(player, "Control", Control(1));
    components->setComponentToEntity(player, "Shoot", Shoot());
    components->setComponentToEntity(player, "Health", Health(50));
    components->setComponentToEntity(player, "Team", Team(1));

    int player2 = components->createEntity();
    components->setComponentToEntity(player2, "Drawable", Draw(1, 519, 480));
    components->setComponentToEntity(player2, "HitboxR", Hitbox((519 * 0.2), (480 * 0.2)));
    components->setComponentToEntity(player2, "Position", Position(50, 150));
    components->setComponentToEntity(player2, "Speed", Speed());
    components->setComponentToEntity(player2, "Control", Control(2));
    components->setComponentToEntity(player2, "Shoot", Shoot());
    components->setComponentToEntity(player2, "Health", Health(50));
    components->setComponentToEntity(player2, "Team", Team(1));

    //#################### init des event qui regissent chaque bouton ####################//
    // Event : si le joueur touche le bouton play
    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, play),
                                    EventContener::initFunct(playHit, components, player, play, join, quit)));
    // Event : si le joueur touche le bouton join
    // components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, join),
    //                                 EventContener::initFunct(joinHit, components)));
    // Event : si le joueur touche le bouton quit
    components->addEvent(EventContener(EventContener::initFunct(Action::idDead, components, quit), quitHit));
    //####################################################################################//

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
    SystemConnect *Connect = new SystemConnect(components);
    components.addSystem(Drawing);
    components.addSystem(Connect);
    components.addSystem(new SystemClearLag(components));
    components.addSystem(new SystemHitbox(components));
    components.addSystem(new SystemMove(components));
    components.addSystem(new SystemControl(components, Drawing->_window, Connect->client));
    components.addSystem(new SystemShoot(components));
}

int main()
{
    Registry components;

    initCore(components);
    menu(&components);

    return 0;
}