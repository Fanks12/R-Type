/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-bilal.nhari
** File description:
** Action
*/

#ifndef ACTION_HPP_
    #define ACTION_HPP_
    #include "Registry.hpp"
    #include "Component.hpp"

class Action {
    public:
        Action();
        ~Action();

        // from here create static functions

        // action
        static bool everyXSecond(Clock *clock, int x);
        static bool idDead(Registry *registries, int id);
        static bool posLowerX(Registry *registries, int id, int x);
        static bool score(Registry *registries, int score);

        // reaction
        static int idSpeed(Registry *registries, int id, int value);
        static int idShoot(Registry *registries, int id, int type);
        static int IdLoseXHp(Registry *registries, int id, int x);
        static int restart(Registry *registries, std::function<int()> start);
    protected:
    private:
};

bool Action::everyXSecond(Clock *clock, int x)
{
    clock->stop();
    if (clock->elapsedTime() >= x) {
        clock->start();
        return true;
    }
    return false;
}

bool Action::score(Registry *registries, int score)
{
    if (registries->score >= score) {
        registries->score = 0;
        return true;
    }
    return false;
}

bool Action::idDead(Registry *registries, int id)
{
    SparseArray<std::any> healthCompo = registries->getComponent<std::any>("Health");

    if (healthCompo[id].type() != typeid(std::string)
        && std::any_cast<Health>(healthCompo[id]).health <= 0)
        return true;
    return false;
}

bool Action::posLowerX(Registry *registries, int id, int x)
{
    SparseArray<std::any> posCompo = registries->getComponent<std::any>("Position");

    if (posCompo[id].type() != typeid(std::string)
        && std::any_cast<Position>(posCompo[id]).x < x)
        return true;
    return false;
}

int Action::idSpeed(Registry *registries, int id, int value)
{
    registries->setComponentToEntity(id, "Speed", Speed(value));
    return 1;
}

int Action::idShoot(Registry *registries, int id, int type)
{
    registries->setComponentToEntity(id, "Shoot", Shoot(type));
    return 1;
}

int Action::IdLoseXHp(Registry *registries, int id, int x)
{
    SparseArray<std::any> healthCompo = registries->getComponent<std::any>("Health");

    if (healthCompo[id].type() == typeid(std::string))
        return 1;
    Health hp = std::any_cast<Health>(healthCompo[id]);
    hp.health -= x;
    registries->setComponentToEntity(id, "Health", hp);
    return 1;
}

int Action::restart(Registry *registries, std::function<int()> start)
{
    registries->cleanCompo();
    start();
    return 1;
}

#endif /* !ACTION_HPP_ */
