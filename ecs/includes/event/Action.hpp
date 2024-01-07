/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-bilal.nhari
** File description:
** Action
*/

#ifndef ACTION_HPP_
    #define ACTION_HPP_
    #include "Registry.hpp"
    #include "Component.hpp"

class Action {
    public:
        Action();
        ~Action();

        // from here create static functions

        // action
        std::function<bool()> everyXSecond();
        bool idDead(Registry *registries, int id);

        // reaction
        std::function<void()> IdLoseXHp(int id, int x);
        void restart(Registry *registries, std::function<int()> start);
    protected:
    private:
};

bool Action::idDead(Registry *registries, int id)
{
    SparseArray<std::any> healthCompo = registries->getComponent<std::any>("Health");

    if (healthCompo[id].type() != typeid(std::string)
        && std::any_cast<Health>(healthCompo[id]).health == 0)
        return true;
    return false;
}

void Action::restart(Registry *registries, std::function<int()> start)
{
    registries->cleanCompo();
    start();
}

#endif /* !ACTION_HPP_ */
