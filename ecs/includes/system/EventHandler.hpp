/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemEvent
*/

#ifndef EVENTHANDLER_HPP_
    #define EVENTHANDLER_HPP_
    #include "Registry.hpp"
    #include "ISystem.hpp"
    #include "Component.hpp"

class Registry;

class EventHandler {

    public:
        EventHandler(Registry *registries);
        ~EventHandler() = default;

        void addEvent();
        int run();
    protected:
    private:
        std::vector<Event> ActionsReactions;
        Registry *_registries;
};

EventHandler::EventHandler(Registry *registries) : _registries(registries) {}

void EventHandler::addEvent()
{
    //action reaction j'ajoute
}

int EventHandler::run()
{
    for (const auto& pair : ActionsReactions)
        if (pair.action)
            pair.reaction;
    return 1;
}

#endif /* !EVENTHANDLER_HPP_ */
