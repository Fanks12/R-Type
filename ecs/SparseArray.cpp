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
    T vide;

    for (int i = 0; i < entityNumber; i++)
        _EntityList.push_back(vide);
}

template <typename T>
SparseArray<T>::SparseArray(SparseArray const & copy)
{
    _EntityList = copy->_EntityList;
}

template <typename T>
SparseArray<T>::SparseArray(SparseArray && move) noexcept
{
    _EntityList = copy->_EntityList;
}

template <typename T>
SparseArray<T>::~SparseArray()
{
    while (!EntityList.empty())
        EntityList.pop_back()
}

template <typename T>
void SparseArray<T>::addEntity()
{
    T vide;

    _EntityList.push_back(vide);
}

template <typename T>
void SparseArray<T>::deleteEntity(int index)
{
    T vide;

    EntityList.at(index) = vide;
}

template <typename T>
void SparseArray<T>::setComponentValue(int index, T component)
{
    EntityList.at(index) = component;
}

template <typename T>
bool SparseArray<T>::hasComponent(int index)
{
    if (!EntityList.at(index))
        return false;
    return true;
}

template <typename T>
T &SparseArray<T>::operator [](int index)
{
    return EntityList.at(index);
}

template <typename T>
T const &SparseArray<T>::operator [](int index) const
{
    return EntityList.at(index);
}
