/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SparseArray
*/

#include "SparseArray.hpp"

template <typename T>
SparseArray<T>::SparseArray()
{
}

template <typename T>
SparseArray<T>::SparseArray(int entityNumber)
{
    for (int i = 0; i < entityNumber; i++)
        EntityList.push_back(None);
}

template <typename T>
SparseArray<T>::~SparseArray()
{
    while (!EntityList.empty())
        EntityList.pop_back()
}

template <typename T>
void SparseArray<T>::setComponentValue(int index, T component)
{
    EntityList.at(index) = component;
}

template <typename T>
bool SparseArray<T>::hasComponent(int index)
{
    if (EntityList.at(index) != None)
        return true;
    return false;
}

template <typename T>
T SparseArray<T>::getComponent(int index)
{
    return EntityList.at(index);
}