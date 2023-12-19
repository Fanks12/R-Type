/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemControl
*/

#ifndef SYSTEMCONTROL_HPP_
    #define SYSTEMCONTROL_HPP_
    #include "System.hpp"
    #include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ESCAPE 27

class SystemControl : public virtual System {
    public:
        SystemControl(Registry &registries);
        ~SystemControl() = default;

        int run();
    protected:
    private:
};

SystemControl::SystemControl(Registry &registries) : System(registries) {}

int SystemControl::run() {
    int key = _getch();

    int is_shooting = 0;

    std::pair<int, int> speed;

    SparseArray<std::any> controlCompo = _registries.getComponent<std::any>("Control");

    SparseArray<std::any> speedCompo = _registries.getComponent<std::any>("Speed");

    SparseArray<std::any> shootCompo = _registries.getComponent<std::any>("Shoot");

    switch (key) {
        case KEY_UP:
            speed = std::pair<int, int>(0, 10);
            break;
        case KEY_DOWN:
            speed = std::pair<int, int>(0, -10);
            break;
        case KEY_LEFT:
            speed = std::pair<int, int>(-10, 0);
            break;
        case KEY_RIGHT:
            speed = std::pair<int, int>(10, 0);
            break;
        case KEY_SPACE:
            is_shooting = 1;
            break;
        case KEY_ESCAPE:
            return 0;
        default:
            break;
    }

    for (size_t i = 0; i < _registries.entityNumbers(); i++) {
        if (!(controlCompo[i].type() == typeid(std::string))) {
            if (!(shootCompo[i].type() == typeid(std::string)))
                speedCompo[i] = speed;
            if (!(shootCompo[i].type() == typeid(std::string)))
                shootCompo[i] = is_shooting;
        }
    }

    return 1;
}


#endif /* !SYSTEMCONTROL_HPP_ */
