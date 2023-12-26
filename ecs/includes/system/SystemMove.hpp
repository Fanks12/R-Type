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

int SystemMove::run()
{
    makeMove();
    return 1;
}

#endif /* !SYSTEMMOVE_HPP_ */
