/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <any>
#include <functional>

class systemevent {
    public:
        systemevent() = default;
        ~systemevent() = default;
        void startEvent(std::function<bool()> func, std::function<void()> react);
    protected:
    private:
};

#endif /* !MAIN_HPP_ */
