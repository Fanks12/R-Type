/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemHitbox
*/

#ifndef SYSTEMHITBOX_HPP_
    #define SYSTEMHITBOX_HPP_
    #include "System.hpp"

class SystemHitbox : public virtual System {
    public:
        SystemHitbox(Registry &registries);
        ~SystemHitbox() = default;

        int run();
    protected:
    private:
        bool collision(std::pair<int, int> Receive, std::pair<int, int> Give);
        bool receive(std::pair<int, int> Receive);
};

SystemHitbox::SystemHitbox(Registry &registries) : System(registries) {}

bool SystemHitbox::collision(std::pair<int, int> Receive, std::pair<int, int> Give)
{
    // if receive touch give return true
}

bool SystemHitbox::receive(std::pair<int, int> Receive)
{
    SparseArray<std::any> hitgCompo = _registries->getComponent<std::any>("HitboxG");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++)
        if (collision(hitrCompo[i]))
            return true;
    return false;
    // if les coo de g sont dans receive et qu'ils ont pas la meme team ya collision
    // active collision effect
}

int SystemHitbox::run() {

    SparseArray<std::any> hitrCompo = _registries->getComponent<std::any>("HitboxR");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++) {
        if (receive(hitrCompo[i]))
    }
    // si une hitbox donnant touche une hitbox recevante d'une equipe differente call l'event hitbox
}

#endif /* !SYSTEMHITBOX_HPP_ */
