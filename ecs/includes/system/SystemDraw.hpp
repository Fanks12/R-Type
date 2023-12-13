/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemDraw
*/

#ifndef SYSTEMDRAW_HPP_
    #define SYSTEMDRAW_HPP_
    #include "System.hpp"
    #include <SFML/Graphics.hpp>
    #include <vector>

class Registry;

class SystemDraw : System {
    public:
        SystemDraw(Registry &registries);
        ~SystemDraw() = default;

        int run();
    protected:
    private:
        Registry _registries;
        sf::RenderWindow _window;
        sf::Event _event;
        std::vector<sf::Sprite> _cache;
};

SystemDraw::SystemDraw(Registry &registries) : System(registries), _window(sf::RenderWindow(sf::VideoMode(800, 600), "Bootstrap"))
{

}

int SystemDraw::run()
{
    if (!_window.isOpen())
        return 0;

    while (_window.pollEvent(_event))
    {
        // Close window: exit
        if (_event.type == sf::Event::Closed)
            _window.close();
    }

    // Clear screen
    _window.clear();

    // Draw the sprite
    for (auto entity : _cache)
        _window.draw(entity);

    // Update the window
    _window.display();
    return 1;
}

#endif /* !SYSTEMDRAW_HPP_ */
