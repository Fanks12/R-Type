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
        void makeMove(sf::Event event);
    protected:
    private:
        sf::Event _event;
};

SystemMove::SystemMove(Registry &registries) : System(registries)
{
}

void SystemMove::makeMove(sf::Event event)
{
    for (long unsigned int index = 0; index < std::any_cast<std::vector<int>>(_registries.getComponent("Speed")).size(); index++) {
        std::pair<int, int> position = std::any_cast<std::pair<int, int>>(_registries.getComponent("Position"))[index];
        if (_event.key.code == sf::Keyboard::Up)
            position.second -= std::any_cast<int>(_registries.getComponent("Speed"))[index];
        if (_event.key.code == sf::Keyboard::Down)
            position.second += std::any_cast<int>(_registries.getComponent("Speed"))[index];
        if (_event.key.code == sf::Keyboard::Left)
            position.first -= std::any_cast<int>(_registries.getComponent("Speed"))[index];
        if (_event.key.code == sf::Keyboard::Right)
            position.first += std::any_cast<int>(_registries.getComponent("Speed"))[index];
        _registries.setComponentToEntity(_registries.getEntityFromComponent("Position")[index], "Position", position);
    }
}

int SystemMove::run()
{
    switch (_event.type) {
        case sf::Event::KeyPressed:
                makeMove(_event);
        default:
            break;
    }
    return 1;
}

#endif /* !SYSTEMMOVE_HPP_ */
