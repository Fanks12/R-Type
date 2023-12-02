/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Registry
*/

#include "Registry.hpp"

Registry::Registry()
{
}

Registry::~Registry()
{
}

int Registry::createEntity()
{
    for (auto component : componentArrays)
        component.second.addEntity();
    entityNumber++;
    return entityNumber - 1;
}

template <typename T>
void Registry::setComponentToEntity(int entityId, std::string component, T defaultValue)
{
    componentArrays[component].setComponentValue(entityId, defaultValue)
}

template <typename T>
void Registry::addComponent(SparseArray<T> component, std::string name)
{
    componentArrays.emplace(name, component);
}

void Registry::removeEntity(int entityIndex)
{
    for (auto component : componentArrays)
        component.second.setValueComponent(entityIndex, NULL);
}

template <typename T>
SparseArray<T>& Registry::getComponent(std::string component)
{
    return componentArrays[component];
}