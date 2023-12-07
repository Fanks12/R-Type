/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "SparseArray.hpp"
#include "Registry.hpp"
#include "main.hpp"
#include <stdbool.h>

int main()
{
    std::string Speed = "Speed";
    std::string Drawable = "Drawable";
    std::string Position = "Position";
    std::string Controllable = "Controllable";
    int entNb;
    Registry components;
    components.addComponent(SparseArray<int>(), Speed);
    /*components.addComponent(SparseArray<bool>(), Drawable);
    components.addComponent(SparseArray<std::pair>(), Position);
    components.addComponent(SparseArray<bool>(), Controllable);*/
    entNb = components.createEntity();
    components.setComponentToEntity(entNb, Speed, 5);
    /*components.setComponentToEntity(entNb, Drawable, true);
    components.setComponentToEntity(entNb, Position, (100, 100));
    components.setComponentToEntity(entNb, Controllable, true);*/
    //auto retValue = components.getComponent(Speed);
    /*try {
        SparseArray<std::string> Test(10);

        std::cout << Test[9] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }*/
    return 0;
}