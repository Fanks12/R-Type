/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Registry
*/

#ifndef REGISTRY_HPP_
#define REGISTRY_HPP_
    #include "SparseArray.hpp"
    #include "Event.hpp"
    #include "ISystem.hpp"
    #include <unordered_map>
    #include <string>
    #include <any>
    #include <unistd.h>

class ISystem;

class Event;

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
         * @brief add a component with the specified name
         * @param name The name of the component.
         */
        void addComponent(std::string name);

        /**
         * @brief Removes a entity with the specified ID.
         * @param entityIndex index of the entity to simulately remove.
         */
        void removeEntity(int entityIndex);

        /**
         * @brief Add a system of type T to the array.
         * @tparam T The type of the system's value.
         * @param system the system to add.
         */
        void addSystem(ISystem *system);

        /**
         * @brief Run all systems.
         */
        void runSystem();

        /**
         * @brief Gets the component of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param component The name of the component.
         * @return Reference to the component.
         */
        template <typename T>
        SparseArray<T> &getComponent(std::string component);

        /**
         * @brief Gets the component of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param component The name of the component.
         * @return Reference const to the component.
         */
        template <typename T>
        SparseArray<T> const &getComponent(std::string component) const;

        /**
         * @brief return entity number value
         * @return The entityNulber value
         */
        size_t entityNumbers() const { return entityNumber; }

        void cleanCompo();

        /**
         * @brief return if the registry is running
         * @return The _running value
         */
        bool isRunning() const { return run; }
        int uuid = 1;

        void addEvent(EventContener newEvent) { event.addEvent(newEvent); }

        void popBackEvent() { event.popBack(); }
    protected:
    private:
        std::unordered_map<std::string, SparseArray<std::any>> componentArrays;
        std::vector<ISystem *> systemArrays;
        Event event;
        size_t entityNumber = 0;
        int run = 1;
        int score = 0;
};

Registry::Registry() {}

Registry::~Registry() {}

int Registry::createEntity()
{
    for (auto& [key, value] : componentArrays)
        value.addEntity();
    entityNumber++;
    return entityNumber - 1;
}

template <typename T>
void Registry::setComponentToEntity(int entityId, std::string component, T defaultValue)
{
    componentArrays.at(component).setComponentValue(entityId, defaultValue);
}

void Registry::addComponent(std::string name)
{
    SparseArray<std::any> component(entityNumber);
    componentArrays.emplace(name, component);
}

void Registry::addSystem(ISystem *system)
{
    systemArrays.push_back(system);
}

void Registry::runSystem()
{
    while (run) {
        usleep(3000);
        run = event.run();
        for (auto system : systemArrays) {
            if (!run)
                break;
            run = system->run();
        }
    }
}

void Registry::removeEntity(int entityIndex)
{
    for (auto& component : componentArrays)
        component.second.deleteEntity(entityIndex);
}

void Registry::cleanCompo()
{
    for (auto& component : componentArrays)
        component.second.cleanArray();
}

template <typename T>
SparseArray<T> &Registry::getComponent(std::string component)
{
    return componentArrays.at(component);
}

template <typename T>
SparseArray<T> const &Registry::getComponent(std::string component) const
{
    return componentArrays.at(component);
}

#endif /* !REGISTRY_HPP_ */

