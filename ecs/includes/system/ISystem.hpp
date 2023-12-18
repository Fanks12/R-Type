/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
    #define ISYSTEM_HPP_

class ISystem {
    public:
        ISystem() = default;
        ~ISystem() = default;

        virtual int run() = 0;
    protected:
    private:
};

#endif /* !ISYSTEM_HPP_ */
