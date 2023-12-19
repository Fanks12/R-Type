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
};

SystemShoot::SystemShoot(Registry &registries) : System(registries) {}

int SystemShoot::run()
{
    // if shoot different de string
    // if shoot == 1 create missile avec une vitesse de 20, 0
    // if shoot == 2 create missile avec une vitesse de -10, 0
    return 1;
}

#endif /* !SYSTEMSHOOT_HPP_ */
