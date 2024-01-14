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
    #include <SFML/Audio.hpp>
    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600

class Object {
    public:
        Object(int path, int x, int y, int w, int h, int nbframes = 1) : rect(x, y, w, h), frames(nbframes)
        {
            textId = path;
            sprite.setTextureRect(rect);
        };
        ~Object() = default;

        int textId;
        sf::Sprite sprite;
        sf::IntRect rect;
        int frames;
};

class SystemDraw : public virtual System {
    public:
        SystemDraw(Registry &registries);
        ~SystemDraw();

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
        // sf::Music music;
        std::vector<std::any> _cache;
        sf::Texture Ennemy;
        sf::Texture SpaceShip;
        sf::Texture Space;
        sf::Texture Shoot_player;
        sf::Texture Shoot_ennemy;
        sf::Texture YouWin;
        sf::Texture YouLose;
        sf::Texture Play;
        sf::Texture Quit;
};

SystemDraw::~SystemDraw() {
    Space.~Texture();
    SpaceShip.~Texture();
    Ennemy.~Texture();
    Shoot_player.~Texture();
    Shoot_ennemy.~Texture();
    YouLose.~Texture();
    YouWin.~Texture();
    Play.~Texture();
    Quit.~Texture();
    _window.close();
}

SystemDraw::SystemDraw(Registry &registries) : System(registries),
_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window") {
    SpaceShip.loadFromFile("asset/Player.png");
    Space.loadFromFile("asset/space.jpg");
    Ennemy.loadFromFile("asset/mob.png");
    Shoot_player.loadFromFile("asset/shoot_player.png");
    Shoot_ennemy.loadFromFile("asset/shoot_ennemy.png");
    YouLose.loadFromFile("asset/You_lose.png");
    YouWin.loadFromFile("asset/You_win.png");
    Play.loadFromFile("asset/play.png");
    Quit.loadFromFile("asset/quit_button.png");

    // music.openFromFile("music.ogg");
    // music.play();
}

void SystemDraw::addInCache(int it, Draw value)
{
    if (it >= _cache.size())
        _cache.push_back(Object(value.Texture_id, 0, 0, value.dim.first, value.dim.second, value.frames));
    else if (_cache.at(it).type() == typeid(std::string))
        _cache.at(it) = Object(value.Texture_id, 0, 0, value.dim.first, value.dim.second, value.frames);
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
        if (posCompo[i].type() == typeid(std::string))
            _registries->removeEntity(i);
        else if (entity.type() != typeid(std::string)) {
            pos = std::any_cast<Position>(posCompo[i]);
            Object object = std::any_cast<Object>(entity);
            if (object.textId == 1) {
                object.sprite.setTexture(SpaceShip);
                object.sprite.setScale(sf::Vector2f(0.2, 0.2));
            }
            if (object.textId == 2) {
                object.sprite.setTexture(Ennemy);
                object.sprite.setScale(sf::Vector2f(0.2, 0.2));

            }
            if (object.textId == 4) {
                object.sprite.setTexture(Play);
                object.sprite.setScale(sf::Vector2f(1, 1));
            }
            if (object.textId == 6) {
                object.sprite.setTexture(Quit);
                object.sprite.setScale(sf::Vector2f(1, 1));
            }
            if (object.textId == 10) {
                object.sprite.setTexture(Space);
            }
            if (object.textId == 11) {
                object.sprite.setTexture(Shoot_player);
                object.sprite.setScale(sf::Vector2f(0.8, 0.8));
            }
            if (object.textId == 12) {
                object.sprite.setTexture(Shoot_ennemy);
                object.sprite.setScale(sf::Vector2f(0.8, 0.8));
            }
            if (object.textId == 15) {
                object.sprite.setTexture(YouWin);
                object.sprite.setScale(sf::Vector2f(1.5, 1.5));
            }
            if (object.textId == 16) {
                object.sprite.setTexture(YouLose);
                object.sprite.setScale(sf::Vector2f(1.5, 1.5));
            }
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
    if (!_window.isOpen()) {
        // music.stop();
        return 0;
    }

    updateEntities();

    // Clear screen
    _window.clear();

    // Draw the sprite
    for (auto &entity : _cache)
        if (entity.type() != typeid(std::string))
            _window.draw(std::any_cast<Object>(entity).sprite);

    // Update the window
    _window.display();
    return 1;
}

#endif /* !SYSTEMDRAW_HPP_ */
