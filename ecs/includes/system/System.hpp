/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_
    #include "Registry.hpp"

class Registry;

class System {
    public:
        System(Registry &registries) : _registries(registries) {}
        ~System() = default;

        int run() { return 1; }
    protected:
    private:
        Registry _registries;
};

#endif /* !SYSTEM_HPP_ */
