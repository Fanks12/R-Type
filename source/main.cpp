#include "main.hpp"

#include <iostream>
#include <unistd.h>

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
        std::cout << "lezgooo" << std::endl;
    });
    std::cout << "end" << std::endl;
    while (true) {
        std::cout << "loop" << std::endl;
        sleep(1);
    };
}