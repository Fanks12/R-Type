/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Position
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

class Position {
    public:
        Position(int abs = 0, int ord = 0) : x(abs), y(ord) {};
        ~Position() = default;

        int x;
        int y;
};

#endif /* !POSITION_HPP_ */
