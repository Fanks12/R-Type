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
    #include <variant>

class SystemDraw : public virtual System {
    public:
        SystemDraw(Registry &registries);
        ~SystemDraw() = default;

        int run();
    protected:
    private:
        void updateCache();
        void updatePosition();
        void updateEntities();

        sf::RenderWindow _window;
        sf::Event _event;
        std::vector<std::any> _cache;
};

SystemDraw::SystemDraw(Registry &registries) : System(registries), _window(sf::VideoMode(800, 600), "SFML window")
{}

void SystemDraw::updateCache()
{
    std::pair<int, int> index;
    SparseArray<std::any> drawCompo = _registries.getComponent<std::any>("Drawable");

    for (size_t i = 0; i < _registries.entityNumbers(); i++)
        if (drawCompo[i].type() == typeid(std::pair<int, int>)) {
            index = std::any_cast<std::pair<int, int>>(drawCompo[i]);
            if (i >= _cache.size())
                _cache.push_back(sf::RectangleShape(sf::Vector2f(index.first, index.second)));
            else if (_cache.at(i).type() == typeid(std::string))
                _cache.at(i) = index;
        } else
            _cache.at(i) = "vide";
}

void SystemDraw::updatePosition()
{
    std::pair<int, int> index;
    SparseArray<std::any> posCompo = _registries.getComponent<std::any>("Position");
    int i = 0;

    for (auto &entity : _cache) {
        if (!(entity.type() == typeid(std::string))) {
            index = std::any_cast<std::pair<int, int>>(posCompo[i]);
            sf::RectangleShape object = std::any_cast<sf::RectangleShape>(entity);
            object.setPosition(sf::Vector2f(index.first, index.second));
            entity = object;
        }
        i++;
    }
}

void SystemDraw::updateEntities()
{
    updateCache();
    updatePosition();
}

int SystemDraw::run()
{
    if (!_window.isOpen())
        return 0;

    updateEntities();

    while (_window.pollEvent(_event))
    {
        // Close window: exit
        if (_event.type == sf::Event::Closed)
            _window.close();
    }

    // Clear screen
    _window.clear();

    // Draw the sprite
    for (auto &entity : _cache)
        if (!(entity.type() == typeid(std::string))) {
            sf::RectangleShape index = std::any_cast<sf::RectangleShape>(entity);
            _window.draw(index);
        }

    // Update the window
    _window.display();
    return 1;
}

#endif /* !SYSTEMDRAW_HPP_ */
