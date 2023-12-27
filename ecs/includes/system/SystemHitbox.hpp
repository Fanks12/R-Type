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
    if (point.x > box.topl.x && point.x < box.botr.x
    && point.y > box.topl.y && point.y < box.botr.y)
        return true;
    return false;
}

bool SystemHitbox::collision(Hitbox receive, Hitbox give)
{
    if (posInBox(receive.topl, give) || posInBox(receive.botr, give)
    || posInBox(give.topl, receive) || posInBox(give.botr, receive)
    || posInBox(Position(receive.topl.x, receive.botr.y), give)
    || posInBox(Position(receive.botr.x, receive.topl.y), give)
    || posInBox(Position(give.topl.x, give.botr.y), receive)
    || posInBox(Position(give.botr.x, give.topl.y), receive))
        return true;
    return false;
}

bool SystemHitbox::receive(Hitbox receive)
{
    SparseArray<std::any> hitgCompo = _registries->getComponent<std::any>("HitboxG");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++)
        if (collision(receive, std::any_cast<Hitbox>(hitrCompo[i])) /*&& team1 != team2*/)
            return true;
    return false;
}

int SystemHitbox::run() {

    SparseArray<std::any> hitrCompo = _registries->getComponent<std::any>("HitboxR");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++) {
        if (receive(std::any_cast<Hitbox>(hitrCompo[i]))
    }
    // si une hitbox donnant touche une hitbox recevante d'une equipe differente call l'event hitbox
}

#endif /* !SYSTEMHITBOX_HPP_ */
