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
    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600

class Object {
    public:
        Object(std::string path, int x, int y, int w, int h, int nbframes = 1) : rect(x, y, w, h), frames(nbframes)
        {
            texture.loadFromFile(path);
            sprite.setTexture(texture);
            sprite.setTextureRect(rect);

        };
        ~Object() = default;

        sf::Sprite sprite;
        sf::Texture texture;
        sf::IntRect rect;
        int frames;
};

class SystemDraw : public virtual System {
    public:
        SystemDraw(Registry &registries);
        ~SystemDraw() = default;

        int run();
        sf::RenderWindow _window;
    protected:
    private:
        void updateCache();
        void updatePosition();
        void updateEntities();
        void addInCache(int it, Draw value);
        void addInCache(int it, std::string value);

        sf::Event _event;
        std::vector<std::any> _cache;
};

SystemDraw::SystemDraw(Registry &registries) : System(registries),
_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window") {}

void SystemDraw::addInCache(int it, Draw value)
{
    if (it >= _cache.size())
        _cache.push_back(Object(value.path, 0, 0, value.dim.first, value.dim.second, value.frames));
    else if (_cache.at(it).type() == typeid(std::string))
        _cache.at(it) = Object(value.path, 0, 0, value.dim.first, value.dim.second, value.frames);
}

void SystemDraw::addInCache(int it, std::string value)
{
    if (it >= _cache.size())
        _cache.push_back(value);
    else if (_cache.at(it).type() != typeid(std::string))
        _cache.at(it) = value;
}

void SystemDraw::updateCache()
{
    Draw index;
    SparseArray<std::any> drawCompo = _registries->getComponent<std::any>("Drawable");

    for (size_t i = 0; i < _registries->entityNumbers(); i++)
        if (drawCompo[i].type() != typeid(std::string)) {
            index = std::any_cast<Draw>(drawCompo[i]);
            addInCache(i, index);
        } else
            addInCache(i, std::string("vide"));
}

void SystemDraw::updatePosition()
{
    Position pos;
    SparseArray<std::any> posCompo = _registries->getComponent<std::any>("Position");
    int i = 0;

    for (auto &entity : _cache) {
        if (posCompo[i].type() != typeid(std::string)
           && entity.type() != typeid(std::string)) {
            pos = std::any_cast<Position>(posCompo[i]);
            Object object = std::any_cast<Object>(entity);
            object.sprite.setPosition(sf::Vector2f(pos.x, pos.y));
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

    // Clear screen
    _window.clear();

    // Draw the sprite
    for (auto &entity : _cache)
        if (entity.type() != typeid(std::string)) {
            Object index = std::any_cast<Object>(entity);
            _window.draw(index.sprite);
        }

    // Update the window
    _window.display();
    return 1;
}

#endif /* !SYSTEMDRAW_HPP_ */
