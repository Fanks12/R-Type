/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemMove
*/

#ifndef SYSTEMMOVE_HPP_
    #define SYSTEMMOVE_HPP_
    #include "System.hpp"
    #include "Speed.hpp"
    #include <vector>
    #include <string>
    #include <any>
    #include <thread>

class SystemMove : public virtual System {
    public:
        SystemMove(Registry &registries);
        ~SystemMove() = default;

        int run();
    protected:
    private:
        void makeMove();
        void hitMove();
};

SystemMove::SystemMove(Registry &registries) : System(registries) {}

void SystemMove::makeMove()
{

    Position pos;
    Speed speed;
    SparseArray<std::any> speedCompo = _registries->getComponent<std::any>("Speed");
    SparseArray<std::any> positionCompo = _registries->getComponent<std::any>("Position");

    for (size_t i = 0; i < _registries->entityNumbers(); i++) {
        if (!(speedCompo[i].type() == typeid(std::string))
        && !(positionCompo[i].type() == typeid(std::string))) {
            pos = std::any_cast<Position>(positionCompo[i]);
            speed = std::any_cast<Speed>(speedCompo[i]);
            _registries->getComponent<std::any>("Position")[i] = Position((pos.x + speed.x), (pos.y + speed.y));
        }
    }
}

void SystemMove::hitMove()
{
    SparseArray<std::any> positionCompo = _registries->getComponent<std::any>("Position");
    SparseArray<std::any> hitgCompo = _registries->getComponent<std::any>("HitboxG");
    SparseArray<std::any> hitrCompo = _registries->getComponent<std::any>("HitboxR");
    Position pos;
    Hitbox hit;

    for (size_t i = 0; i < _registries->entityNumbers(); i++) {
        if (positionCompo[i].type() != typeid(std::string)) {
            pos = std::any_cast<Position>(positionCompo[i]);
            if (hitrCompo[i].type() != typeid(std::string)) {
                hit = std::any_cast<Hitbox>(hitrCompo[i]);
                hit.pos(pos.x, pos.y);
                _registries->setComponentToEntity(i, "HitboxR", hit);
            }
            if (hitgCompo[i].type() != typeid(std::string)) {
                hit = std::any_cast<Hitbox>(hitgCompo[i]);
                hit.pos(pos.x, pos.y);
                _registries->setComponentToEntity(i, "HitboxG", hit);
            }
        }
    }
}

int SystemMove::run()
{
    makeMove();
    hitMove();
    return 1;
}

#endif /* !SYSTEMMOVE_HPP_ */
