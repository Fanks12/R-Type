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
        Hitbox(int x = 0, int y = 0) : topl(0, 0), botr(x, y) {};
        ~Hitbox() = default;

        void pos(int x, int y) {
            topl.x = x;
            topl.y = y;
            botr.x = x + dim.x;
            botr.y = y + dim.y;
        }
        Position topl;
        Position botr;
        Position dim;
};

#endif /* !HITBOX_HPP_ */
