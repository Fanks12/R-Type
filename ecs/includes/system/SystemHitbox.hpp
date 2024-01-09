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
        int receive(Hitbox Receive, int team1);
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

int SystemHitbox::receive(Hitbox receive, int team1)
{
    SparseArray<std::any> hitgCompo = _registries->getComponent<std::any>("HitboxG");
    SparseArray<std::any> damageCompo = _registries->getComponent<std::any>("Damage");
    SparseArray<std::any> healthCompo = _registries->getComponent<std::any>("Health");
    SparseArray<std::any> teamCompo = _registries->getComponent<std::any>("Team");
    int team2;

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++) {
        team2 = (teamCompo[i].type() != typeid(std::string) ? std::any_cast<Team>(teamCompo[i]).team : 0);
        if (hitgCompo[i].type() != typeid(std::string)
         && damageCompo[i].type() != typeid(std::string)
         && collision(receive, std::any_cast<Hitbox>(hitgCompo[i]))
         && team1 > 0 && team2 > 0 && team1 != team2) {
            if (healthCompo[i].type() != typeid(std::string))
                _registries->setComponentToEntity(i, "Health", Health(std::any_cast<Health>(healthCompo[i]).health - 1));
            return std::any_cast<Damage>(damageCompo[i]).damage;
        }
    }
    return 0;
}


int SystemHitbox::run()
{
    SparseArray<std::any> hitrCompo = _registries->getComponent<std::any>("HitboxR");
    SparseArray<std::any> healthCompo = _registries->getComponent<std::any>("Health");
    SparseArray<std::any> teamCompo = _registries->getComponent<std::any>("Team");
    int damage = 0;
    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++)
        if (hitrCompo[i].type() != typeid(std::string) &&
        (damage = receive(std::any_cast<Hitbox>(hitrCompo[i]),
         (teamCompo[i].type() != typeid(std::string) ? std::any_cast<Team>(teamCompo[i]).team : 0))))
            _registries->setComponentToEntity(i, "Health", Health(std::any_cast<Health>(healthCompo[i]).health - damage));
    return 1;
}

#endif /* !SYSTEMHITBOX_HPP_ */
