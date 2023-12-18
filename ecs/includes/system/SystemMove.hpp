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
    #include <thread>

class SystemMove : public virtual System {
    public:
        SystemMove(Registry &registries, sf::Window *window);
        ~SystemMove() = default;

        int run();
        void makeMove();
    protected:
    private:
        sf::Event _event;
        sf::Window *_window;
};

SystemMove::SystemMove(Registry &registries, sf::Window *window) : System(registries)
{
    _window = window;
}

void SystemMove::makeMove()
{
    switch (_event.type) {
        case sf::Event::KeyPressed: 
            for (long unsigned int index = 0; index < _registries.entityNumbers(); index++) {
                std::pair<int, int> position = std::any_cast<std::pair<int, int>>(_registries.getComponent<std::any>("Position")[index]);
                if (_registries.getComponent<std::any>("Speed")[index].has_value() == false or _registries.getComponent<std::any>("Position")[index].has_value() == false)
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
            break;
    }
}

int SystemMove::run()
{
    _event = sf::Event();
    while (_window->pollEvent(_event)) {
        makeMove();
    }
    return 0;
}

#endif /* !SYSTEMMOVE_HPP_ */
