/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "SparseArray.hpp"
#include "main.hpp"

int main()
{
    try {
        SparseArray<std::string> Test(10);

        std::cout << Test[9] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}