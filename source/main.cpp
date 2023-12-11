/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "main.hpp"

#include <iostream>

bool trigger()
{
    char userInput;
    std::cout << "Enter a character: ";
    std::cin >> userInput;

    if (userInput == 'a') {
        return true;
    }
    return false;
}

int main()
{
    systemevent test;
    test.startEvent(trigger, []() {
        std::cout << "decol lapin (oublie pas de mettre un coup de press aussi)" << std::endl;
    });
    std::cout << "end" << std::endl;
    while (true);
}
