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
        bool posInBox(Position point, Hitbox box);
        bool collision(Hitbox Receive, Hitbox Give);
        bool receive(Hitbox Receive);
};

SystemHitbox::SystemHitbox(Registry &registries) : System(registries) {}

bool SystemHitbox::posInBox(Position point, Hitbox box)
{
    if (point.first > box.first.first && point.first.first < box.second.first
    && point.second > box.first.second && point.second < box.second.second)
        return true;
    return false;
}

bool SystemHitbox::collision(Hitbox receive, Hitbox give)
{
    if (posInBox(receive.first, give) || posInBox(receive.second, give)
    || posInBox(give.first, receive) || posInBox(give.second, receive)
    || posInBox(Position(receive.first.first, receive.second.second), give)
    || posInBox(Position(receive.second.first, receive.first.second), give)
    || posInBox(Position(give.first.first, give.second.second), receive)
    || posInBox(Position(give.second.first, give.first.second), receive))
        return true;
    return false;
}

bool SystemHitbox::receive(Hitbox receive)
{
    SparseArray<std::any> hitgCompo = _registries->getComponent<std::any>("HitboxG");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++)
        if (collision(receive, hitrCompo[i]) /*&& team1 != team2*/)
            return true;
    return false;
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
