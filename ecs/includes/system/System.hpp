/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_
    #include "Registry.hpp"
    #include "ISystem.hpp"

class Registry;

class System : public ISystem {
    public:
        System(Registry &registries) : _registries(&registries) {}
        ~System() = default;

        virtual int run();
    protected:
        Registry *_registries;
    private:
};

int System::run() { return 1; }

#endif /* !SYSTEM_HPP_ */
