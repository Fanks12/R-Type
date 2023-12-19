/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemMove
*/

#ifndef SYSTEMMOVE_HPP_
    #define SYSTEMMOVE_HPP_
    #include "System.hpp"
    #include <vector>
    #include <string>
    #include <any>
    #include <thread>
    #include <mutex>
    #include <iostream>

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

void SystemMove::makeMove() {
    for (size_t index = 0; index < _registries.entityNumbers(); index++) {
        std::pair<int, int> position = std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Position")[index]);
        if (_registries.getComponent<std::any>("Speed")[index].has_value() == false or _registries.getComponent<std::any>("Position")[index].has_value() == false)
            return;

        position.first += std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Speed")[index]).first;
        position.second += std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Speed")[index]).second;
        _registries.setComponentToEntity(index, "Position", position);
        std::cout << "Position : " << std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Position")[index]).first << " " << std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Position")[index]).second << std::endl;
    }
}

int SystemMove::run()
{
    makeMove();
    return 1;
}

#endif /* !SYSTEMMOVE_HPP_ */
