/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** event
*/

#include "main.hpp"

#include <thread>
#include <iostream>

void checkAlive(std::function<bool()> func, std::function<void()> react)
{
    while (true) {
        if (func()) {
            react();
            break;
        }
    }
}

void systemevent::startEvent(std::function<bool()> func, std::function<void()> react)
{
    std::thread([&]() {
            checkAlive(func, react);
        }).detach();
}