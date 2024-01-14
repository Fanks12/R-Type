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
        SystemControl(Registry &registries, sf::RenderWindow &window, Client *client);
        ~SystemControl() = default;

        int run();
    protected:
    private:
        bool inWindow(int id, Speed speed);
        Client *_client;

        sf::RenderWindow *_window;
        sf::Event _event;
};

SystemControl::SystemControl(Registry &registries, sf::RenderWindow &window, Client *client) : System(registries), _window(&window), _client(client) {}

bool SystemControl::inWindow(int id, Speed speed)
{
    Position pos;
    if (_registries->getComponent<std::any>("Position")[id].type() != typeid(std::string))
        pos = std::any_cast<Position>(_registries->getComponent<std::any>("Position")[id]);

    if (pos.x + speed.x > 700 || pos.x + speed.x < 0 || pos.y + speed.y > 500
       || pos.y + speed.y < 0)
        return false;
    return true;
}

int SystemControl::run()
{
    Shoot is_shooting;

    Speed speed;

    SparseArray<std::any> controlCompo = _registries->getComponent<std::any>("Control");

    SparseArray<std::any> speedCompo = _registries->getComponent<std::any>("Speed");

    SparseArray<std::any> shootCompo = _registries->getComponent<std::any>("Shoot");

    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return 0;
        if (_event.type == sf::Event::KeyPressed)
            switch (_event.key.code) {
                case sf::Keyboard::Up:
                    speed = Speed(0, -10);
                    break;
                case sf::Keyboard::Down:
                    speed = Speed(0, 10);
                    break;
                case sf::Keyboard::Left:
                    speed = Speed(-10, 0);
                    break;
                case sf::Keyboard::Right:
                    speed = Speed(10, 0);
                    break;
                case sf::Keyboard::Space:
                    is_shooting.shoot = 1;
                    break;
                case sf::Keyboard::Escape:
                    return 0;
                default:
                    break;
            }
    }

    for (size_t i = 0; i < _registries->entityNumbers(); i++) {
        if (!(controlCompo[i].type() == typeid(std::string)) && std::any_cast<Control>(controlCompo[i]).control == _registries->uuid) {
            if (!(speedCompo[i].type() == typeid(std::string)) && inWindow(i, speed))
                _registries->getComponent<std::any>("Speed")[i] = speed;
            if (!(shootCompo[i].type() == typeid(std::string))) {
                _registries->getComponent<std::any>("Shoot")[i] = is_shooting;
                if (_client != NULL && is_shooting.shoot == 1)
                        _client->WriteMessageUDP("i=" + std::to_string(i) + " s=1");
            }
        }
    }

    return 1;
}


#endif /* !SYSTEMCONTROL_HPP_ */
