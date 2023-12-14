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

int SystemMove::run()
{
    switch (_event.type) {
        case sf::Event::KeyPressed:
            for (long unsigned int index = 0; index < _registries.componentArrays.size(); index++) {
                // if (_registries.componentArrays["Position"][index] != "" and _registries.componentArrays["Vitesse"][index] != "") {
                //     if (_event.key.code == sf::Keyboard::Up)
                //         _registries.componentArrays["Position"][index].y -= _registries.componentArrays["Vitesse"][index];
                //     if (_event.key.code == sf::Keyboard::Down)
                //         _registries.componentArrays["Position"][index].y += _registries.componentArrays["Vitesse"][index];
                //     if (_event.key.code == sf::Keyboard::Left)
                //         _registries.componentArrays["Position"][index].x -= _registries.componentArrays["Vitesse"][index];
                //     if (_event.key.code == sf::Keyboard::Right)
                //         _registries.componentArrays["Position"][index].x += _registries.componentArrays["Vitesse"][index];
                // }
            }
        default:
            break;
    }
    return 1;
}

#endif /* !SYSTEMMOVE_HPP_ */
