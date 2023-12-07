/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "SparseArray.hpp"
#include "Registry.hpp"
#include "main.hpp"

int main()
{
    std::string Speed = "Speed";
    std::string Drawable = "Drawable";
    std::string xPosition = "xPosition";
    std::string yPosition = "yPosition";
    std::string Controllable = "Controllable";
    int entNb;
    Registry components;
    SparseArray<void *> comp;
    components.addComponent(comp, Speed);
    components.addComponent(comp, Drawable);
    components.addComponent(comp, xPosition);
    components.addComponent(comp, yPosition);
    components.addComponent(comp, Controllable);
    entNb = components.createEntity();
    components.setComponentToEntity(entNb, Speed, (void *)10);
    components.setComponentToEntity(entNb, Drawable, (void *)1);
    components.setComponentToEntity(entNb, xPosition, (void *)100);
    components.setComponentToEntity(entNb, yPosition, (void *)100);
    components.setComponentToEntity(entNb, Controllable, (void *)1);
    //auto retValue = components.getComponent(Speed);
    /*try {
        SparseArray<std::string> Test(10);

        std::cout << Test[9] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }*/
    return 0;
}