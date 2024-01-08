/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Health
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_

class Health {
    public:
        Health(int val = 0) : health(val) {};
        ~Health() = default;

        int health;
};

#endif /* !HEALTH_HPP_ */
