/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemShoot
*/

#ifndef SYSTEMSHOOT_HPP_
    #define SYSTEMSHOOT_HPP_
    #include "System.hpp"

class SystemShoot : public virtual System {
    public:
        SystemShoot(Registry &registries);
        ~SystemShoot() = default;

        int run();
    protected:
    private:
        void setBullet(int type, std::pair<int, int> pos);
};

SystemShoot::SystemShoot(Registry &registries) : System(registries) {}

void SystemShoot::setBullet(int type, std::pair<int, int> pos)
{
    if (type == 0)
        return;
    int bullet = _registries->createEntity();
    _registries->setComponentToEntity(bullet, "Drawable", std::pair<int, int>(20, 10));
    _registries->setComponentToEntity(bullet, "Position", std::pair<int, int>(pos.first, pos.second));
    if (type == 1)
        _registries->setComponentToEntity(bullet, "Speed", std::pair<int, int>(2, 0));
    if (type == 2)
        _registries->setComponentToEntity(bullet, "Speed", std::pair<int, int>(-2, 0));
}

int SystemShoot::run()
{
    SparseArray<std::any> posCompo = _registries->getComponent<std::any>("Position");
    SparseArray<std::any> shootCompo = _registries->getComponent<std::any>("Shoot");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++) {
        if (!(shootCompo[i].type() == typeid(std::string)) && !(posCompo[i].type() == typeid(std::string)))
            setBullet(std::any_cast<int>(shootCompo[i]), std::any_cast<std::pair<int, int>>(posCompo[i]));
    }
    return 1;
}

#endif /* !SYSTEMSHOOT_HPP_ */
