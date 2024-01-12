/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemHealth
*/

#ifndef SYSTEMHEALTH_HPP_
    #define SYSTEMHEALTH_HPP_
    #include "System.hpp"

class SystemHealth : public virtual System {
    public:
        SystemHealth(Registry &registries);
        ~SystemHealth() = default;

        int run();
    protected:
    private:
};

SystemHealth::SystemHealth(Registry &registries) : System(registries) {}

int SystemHealth::run() {
    SparseArray<std::any> healthCompo = _registries->getComponent<std::any>("Health");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++)
        if (healthCompo[i].type() != typeid(std::string)
        && std::any_cast<Health>(healthCompo[i]).health <= 0)
            _registries->removeEntity(i);
    return 1;
}

#endif /* !SYSTEMHEALTH_HPP_ */
