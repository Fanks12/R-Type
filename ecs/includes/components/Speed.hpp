/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Speed
*/

#ifndef SPEED_HPP_
    #define SPEED_HPP_

class Speed {
    public:
        Speed(int abs = 0, int ord = 0) : x(abs), y(ord) {};
        ~Speed() = default;

        int x;
        int y;
};

#endif /* !SPEED_HPP_ */
