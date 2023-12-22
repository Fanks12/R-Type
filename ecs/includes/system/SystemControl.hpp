/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemControl
*/

#ifndef SYSTEMCONTROL_HPP_
    #define SYSTEMCONTROL_HPP_
    #include "System.hpp"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ESCAPE 27

class SystemControl : public virtual System {
    public:
        SystemControl(Registry &registries, sf::RenderWindow &window);
        ~SystemControl() = default;

        int run();
    protected:
    private:
        bool inWindow(int id, std::pair<int, int> speed);

        sf::RenderWindow *_window;
        sf::Event _event;
};

SystemControl::SystemControl(Registry &registries, sf::RenderWindow &window) : System(registries), _window(&window) {}

bool SystemControl::inWindow(int id, std::pair<int, int> speed)
{
    std::pair<int, int> pos = std::any_cast<std::pair<int, int>>(_registries->getComponent<std::any>("Position")[id]);

    if (pos.first + speed.first > 700)
        return false;
    if (pos.first + speed.first < 0)
        return false;
    if (pos.second + speed.second > 500)
        return false;
    if (pos.second + speed.second < 0)
        return false;
    return true;
}

int SystemControl::run() {

    int is_shooting = 0;

    std::pair<int, int> speed;

    SparseArray<std::any> controlCompo = _registries->getComponent<std::any>("Control");

    SparseArray<std::any> speedCompo = _registries->getComponent<std::any>("Speed");

    SparseArray<std::any> shootCompo = _registries->getComponent<std::any>("Shoot");

    std::string id = std::to_string(_registries->uuid);

    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return 0;
        if (_event.type == sf::Event::KeyPressed)
            switch (_event.key.code) {
                case sf::Keyboard::Up:
                    speed = std::pair<int, int>(0, -10);
                    _registries->client.TcpWrite(id + " Up");
                    break;
                case sf::Keyboard::Down:
                    speed = std::pair<int, int>(0, 10);
                    _registries->client.TcpWrite(id + " Down");
                    break;
                case sf::Keyboard::Left:
                    speed = std::pair<int, int>(-10, 0);
                    _registries->client.TcpWrite(id + " Left");
                    break;
                case sf::Keyboard::Right:
                    speed = std::pair<int, int>(10, 0);
                    _registries->client.TcpWrite(id + " Right");
                    break;
                case sf::Keyboard::Space:
                    is_shooting = 1;
                    _registries->client.TcpWrite(id + " Shoot");
                    break;
                case sf::Keyboard::Escape:
                    return 0;
                default:
                    break;
            }
    }

    for (size_t i = 0; i < _registries->entityNumbers(); i++) {
        if (!(controlCompo[i].type() == typeid(std::string)) && std::any_cast<int>(controlCompo[i]) == _registries->uuid) {
            if (!(speedCompo[i].type() == typeid(std::string)) && inWindow(i, speed))
                _registries->getComponent<std::any>("Speed")[i] = speed;
            if (!(shootCompo[i].type() == typeid(std::string)))
                _registries->getComponent<std::any>("Shoot")[i] = is_shooting;
        }
    }

    return 1;
}


#endif /* !SYSTEMCONTROL_HPP_ */
