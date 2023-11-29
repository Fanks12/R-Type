/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Registry
*/

#ifndef REGISTRY_HPP_
#define REGISTRY_HPP_
#include <unordered_map>
#include <string>

template <typename T>
class SparseArray;

class Registry {
    public:
        Registry();
        ~Registry();

        /**
         * @brief Create an entity for all components.
         * @return Id of the entity created.
         */
        int createEntity();

        /**
         * @brief Adds to the component the value of type T corresponding to an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param entityId The ID of the entity.
         * @param component The name of the component.
         * @param value The value to set. if value is None the components is like removed
         */
        template <typename T>
        void setComponentToEntity(int entityId, std::string component, T defaultValue);

        /**
         * @brief Removes a component of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param component The component to add.
         * @param name The name of the component.
         */
        template <typename T>
        void addComponent(SparseArray<T> component, std::string name);

        /**
         * @brief Removes a component of type T from an entity with the specified ID.
         * @param component The name of the component.
         */
        void removeComponent(std::string component);

        /**
         * @brief Gets the component of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param component The name of the component.
         * @return Reference to the component.
         */
        template <typename T>
        SparseArray<T>& getComponent(std::string component);

    protected:
    private:
        std::unordered_map<std::string, SparseArray<void *>> componentArrays;

        size_t nextEntityIndex = 0;
};

#endif /* !REGISTRY_HPP_ */

