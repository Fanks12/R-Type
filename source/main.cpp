/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "Registry.hpp"
#include "main.hpp"

int main()
{
    std::string Speed = "Speed";

    int index;
    int entNb = 0;
    Registry components;
    components.addComponent(std::move(SparseArray<int>()), Speed);

    index = components.createEntity();
    components.setComponentToEntity(entNb, Speed, 5);
    index++;

    /*try {
        SparseArray<std::string> Test(10);

        std::cout << Test[9] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }*/
    return 0;
}