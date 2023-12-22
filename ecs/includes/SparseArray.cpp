/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SparseArray
*/

#include "SparseArray.hpp"

template <typename T>
SparseArray<T>::SparseArray(int entityNumber)
{
    for (int i = 0; i < entityNumber; i++)
        _EntityList.push_back(std::string("vide"));
}

template <typename T>
SparseArray<T>::SparseArray(SparseArray const & copy)
{
    _EntityList = copy._EntityList;
}

template <typename T>
SparseArray<T>::SparseArray(SparseArray && move) noexcept
{
    _EntityList = move._EntityList;
}

template <typename T>
SparseArray<T>::~SparseArray()
{
    while (!_EntityList.empty())
        _EntityList.pop_back();
}

template <typename T>
void SparseArray<T>::addEntity()
{
    _EntityList.push_back(std::string("vide"));
}

template <typename T>
void SparseArray<T>::deleteEntity(int index)
{
    _EntityList.at(index) = std::string("vide");
}

template <typename T>
void SparseArray<T>::setComponentValue(int index, T component)
{
    _EntityList.at(index) = component;
}

template <typename T>
bool SparseArray<T>::hasComponent(int index)
{
    if (!_EntityList.at(index))
        return false;
    return true;
}

template <typename T>
T &SparseArray<T>::operator [](int index)
{
    return _EntityList.at(index);
}

template <typename T>
T const &SparseArray<T>::operator [](int index) const
{
    return _EntityList.at(index);
}