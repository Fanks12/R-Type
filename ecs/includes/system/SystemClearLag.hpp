/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-bilal.nhari
** File description:
** SystemClearLag
*/

#ifndef SYSTEMCLEARLAG_HPP_
    #define SYSTEMCLEARLAG_HPP_
    #include "System.hpp"

class SystemClearLag : public virtual System {
    public:
        SystemClearLag(Registry &registries);
        ~SystemClearLag() = default;

        int run();
    protected:
    private:
};

SystemClearLag::SystemClearLag(Registry &registries) : System(registries) {}

int SystemClearLag::run()
{
    SparseArray<std::any> posCompo = _registries->getComponent<std::any>("Position");

    size_t loop = _registries->entityNumbers();
    for (size_t i = 0; i < loop; i++)
        if (posCompo[i].type() != typeid(std::string)
        && (std::any_cast<Position>(posCompo[i]).x <= -100
        || std::any_cast<Position>(posCompo[i]).x >= 900))  {
            _registries->removeEntity(i);
        }
    return 1;
}

#endif /* !SYSTEMCLEARLAG_HPP_ */
