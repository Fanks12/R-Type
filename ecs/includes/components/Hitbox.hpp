/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Hitbox
*/

#ifndef HITBOX_HPP_
    #define HITBOX_HPP_
    #include "Position.hpp"

class Hitbox {
    public:
        Hitbox(int abs1 = 0, int ord1 = 0, int abs2 = 0, int ord2 = 0) : topl(abs1, ord1), botr(abs2, ord2) {};
        ~Hitbox() = default;

        Position topl;
        Position botr;
};

#endif /* !HITBOX_HPP_ */
