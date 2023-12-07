/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
    #define SPARSEARRAY_HPP_
    #include <vector>

template <typename T>
class SparseArray {
    public:
        using size_type = typename std::vector<T>::size_type;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;

        SparseArray();
        SparseArray(int entityNumber);
        SparseArray(SparseArray const & copy); // copy constructor
        SparseArray(SparseArray && move) noexcept; // move constructor
        ~SparseArray();

        SparseArray & operator =(SparseArray const &copy); // copy assignment operator
        SparseArray & operator =(SparseArray &&move) noexcept; // move assignment operator

        /**
         * @brief Gets the component value of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @return reference to the Value of the component for the target.
         */
        T &operator [](int index);

        /**
         * @brief Gets the component value of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @return Value const reference of the component for the target.
         */
        T const &operator [](int index) const;

        // iterator begin ();
        // const_iterator begin() const;
        // const_iterator cbegin() const;

        // iterator end ();
        // const_iterator end() const;
        // const_iterator cend() const;

        // size_type size() const;
        // T &insert_at(size_type pos, Component const &);
        // T &insert_at(size_type pos, Component &&);

        /**
         * @brief Add a new index to handle a new entity
         * @tparam T The type of the component's value.
         */
        void addEntity();

        /**
         * @brief Delete value at the index
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         */
        void deleteEntity(int index);

        /**
         * @brief Change the component value from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @param component Value to apply.
         */
        void setComponentValue(int index, T component);

        /**
         * @brief Tells if the selected entity have the current component.
         * @param index The index of the entity targeted.
         * @return true if the component has a value false otherwise.
         */
        bool hasComponent(int index);

    protected:
    private:
        std::vector<T> _EntityList;
};

template <typename T>
SparseArray<T>::SparseArray()
{
}

template <typename T>
SparseArray<T>::SparseArray(int entityNumber)
{
    for (int i = 0; i < entityNumber; i++)
        _EntityList.push_back(T());
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
    _EntityList.push_back(T());
}

template <typename T>
void SparseArray<T>::deleteEntity(int index)
{
    _EntityList.at(index) = T();
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

#endif /* !SPARSEARRAY_HPP_ */
