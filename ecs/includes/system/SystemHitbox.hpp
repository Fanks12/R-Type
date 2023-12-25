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
        bool posInBox(std::pair<int, int> point, std::pair<std::pair<int, int>, std::pair<int, int>> box);
        bool collision(std::pair<int, int> Receive, std::pair<int, int> Give);
        bool receive(std::pair<int, int> Receive);
};

SystemHitbox::SystemHitbox(Registry &registries) : System(registries) {}

bool SystemHitbox::posInBox(std::pair<int, int> point,
                        std::pair<std::pair<int, int>, std::pair<int, int>> box)
{
    if (point.first > box.first.first && point.first.first < box.second.first
    && point.second > box.first.second && point.second < box.second.second)
        return true;
    return false;
}

bool SystemHitbox::collision(std::pair<std::pair<int, int>, std::pair<int, int>> receive,
                            std::pair<std::pair<int, int>, std::pair<int, int>> give)
{
    if (posInBox(receive.first, give) || posInBox(receive.second, give)
    || posInBox(give.first, receive) || posInBox(give.second, receive)
    || posInBox(std::pair<int, int>(receive.first.first, receive.second.second), give)
    || posInBox(std::pair<int, int>(receive.second.first, receive.first.second), give)
    || posInBox(std::pair<int, int>(give.first.first, give.second.second), receive)
    || posInBox(std::pair<int, int>(give.second.first, give.first.second), receive))
        return true;
    return false;
}

bool SystemHitbox::receive(std::pair<std::pair<int, int>, std::pair<int, int>> receive)
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
