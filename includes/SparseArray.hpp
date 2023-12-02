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
        SparseArray();
        SparseArray(int entityNumber);
        ~SparseArray();

        /**
         * @brief Add a new index to handle a new entity
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @param component Value to apply.
         */
        void addEntity();

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

        /**
         * @brief Gets the component value of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @return Value of the component for the target.
         */
        T getComponent(int index);
    protected:
    private:
        std::vector<T> EntityList;
};

#endif /* !SPARSEARRAY_HPP_ */
