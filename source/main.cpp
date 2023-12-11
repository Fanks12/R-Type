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

    int fusée;
    int voiture;
    int entNb = 0;
    Registry components;
    components.addComponent(std::move(SparseArray<std::any>()), Speed);

    fusée = components.createEntity();
    voiture = components.createEntity();
    entNb++;
    components.setComponentToEntity(fusée, Speed, 5);
    components.setComponentToEntity(voiture, Speed, 2);
    SparseArray<std::any> speedcompo = components.getComponent<std::any>(Speed);
    std::cout << std::any_cast<int>(speedcompo[voiture]) << std::endl;
    std::cout << std::any_cast<int>(components.getComponent<std::any>(Speed)[fusée]) << std::endl;

    /*try {
        SparseArray<std::string> Test(10);

        std::cout << Test[9] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }*/
    return 0;
}