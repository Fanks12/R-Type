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
        std::vector<std::variant<std::string, sf::Sprite>> _cache;
};

SystemDraw::SystemDraw(Registry &registries) : System(registries), _window(sf::RenderWindow(sf::VideoMode(800, 600), "Bootstrap"))
{}

void SystemDraw::updateCache()
{
    std::pair<int, int> index;
    SparseArray<std::any> drawCompo = _registries.getComponent<std::any>("Drawable");
    for (int i = 0; i < _registries.entityNumbers(); i++)
        if (i >= _cache.size())
            _cache.push_back((index = std::any_cast<std::pair<int, int>>(drawCompo[i])) ? sf::RectangleShape(sf::Vector2f(index.first, index.second)) : "vide");
        else if ((index = std::any_cast<std::pair<int, int>>(drawCompo[i])) && _cache.at(i) == "vide")
            _cache.push_back(sf::RectangleShape(sf::Vector2f(index.first, index.second)));
        else
            _cache.at(i) = "vide";
}

void SystemDraw::updatePosition()
{
    std::pair<int, int> index;
    SparseArray<std::any> posCompo = _registries.getComponent<std::any>("Position");
    // boucle sur cache
    // si non vide / index = std::any_cast<std::pair<int, int>>(drawCompo[i])
    // _cache[i].position = sf::Vector2f(index.first, index.second);

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
        if (!std::holds_alternative<std::string>(entity))
            _window.draw(std::get<sf::Sprite>(entity));

    // Update the window
    _window.display();
    return 1;
}

#endif /* !SYSTEMDRAW_HPP_ */
