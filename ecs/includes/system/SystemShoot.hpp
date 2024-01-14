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
        SystemShoot(Registry &registries, Client *client);
        ~SystemShoot() = default;

        int run();
    protected:
    private:
        void setBullet(int type, Position pos);
        Client *_client;
};

SystemShoot::SystemShoot(Registry &registries, Client *client) : System(registries), _client(client) {}

void SystemShoot::setBullet(int type, Position pos)
{
    if (type == 0)
        return;
    int bullet = _registries->createEntity();
    _registries->setComponentToEntity(bullet, "Drawable", Draw("", 20, 10));
    _registries->setComponentToEntity(bullet, "Position", Position(pos.x, pos.y));
    _registries->setComponentToEntity(bullet, "Damage", Damage(1));
    _registries->setComponentToEntity(bullet, "Health", Health(1));
    _registries->setComponentToEntity(bullet, "HitboxG", Hitbox(20, 10));
    _registries->setComponentToEntity(bullet, "Team", Team(type));
    if (type == 1)
        _registries->setComponentToEntity(bullet, "Speed", Speed(2));
    if (type == 2)
        _registries->setComponentToEntity(bullet, "Speed", Speed(-2));
}

int SystemShoot::run()
{
    SparseArray<std::any> posCompo = _registries->getComponent<std::any>("Position");
    SparseArray<std::any> shootCompo = _registries->getComponent<std::any>("Shoot");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++) {
        if (!(shootCompo[i].type() == typeid(std::string)) && !(posCompo[i].type() == typeid(std::string))) {
            if (_client && std::any_cast<Shoot>(shootCompo[i]).shoot != 0)
                _client->WriteMessageUDP("i=" + std::to_string(i) + " shoot=" + std::to_string(std::any_cast<Shoot>(shootCompo[i]).shoot));
            setBullet(std::any_cast<Shoot>(shootCompo[i]).shoot, std::any_cast<Position>(posCompo[i]));
            _registries->setComponentToEntity(i, "Shoot", Shoot());
        }
    }
    return 1;
}

#endif /* !SYSTEMSHOOT_HPP_ */
