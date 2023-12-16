/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemMove
*/

#ifndef SYSTEMMOVE_HPP_
    #define SYSTEMMOVE_HPP_
    #include "System.hpp"
    #include "SparseArray.hpp"
    #include "Registry.hpp"
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include <string>
    #include <any>

class SystemMove : public virtual System {
    public:
        SystemMove(Registry &registries);
        ~SystemMove() = default;

        int run();
        void makeMove();
    protected:
    private:
        sf::Event _event;
};

SystemMove::SystemMove(Registry &registries) : System(registries)
{
}

void SystemMove::makeMove()
{
    for (long unsigned int index = 0; index < _registries.entityNumbers(); index++) {
        std::pair<int, int> position = std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Position")[index]);
        if (_registries.getComponent<std::any>("Speed")[index].has_value() == false || _registries.getComponent<std::any>("Position")[index].has_value() == false)
            return;

        if (_event.key.code == sf::Keyboard::Up)
            position.second -= std::any_cast<int>(_registries.getComponent<std::any>("Speed")[index]);
        else if (_event.key.code == sf::Keyboard::Down)
            position.second += std::any_cast<int>(_registries.getComponent<std::any>("Speed")[index]);
        else if (_event.key.code == sf::Keyboard::Left)
            position.first -= std::any_cast<int>(_registries.getComponent<std::any>("Speed")[index]);
        else if (_event.key.code == sf::Keyboard::Right)
            position.first += std::any_cast<int>(_registries.getComponent<std::any>("Speed")[index]);
        _registries.setComponentToEntity(index, "Position", position);
    }
}

int SystemMove::run()
{
    switch (_event.type) {
        case sf::Event::KeyPressed:
                makeMove();
        default:
            break;
    }
    return 1;
}

#endif /* !SYSTEMMOVE_HPP_ */
