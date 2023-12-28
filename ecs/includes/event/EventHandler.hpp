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

        void addEvent(Event event);
        int run();
    protected:
    private:
        std::vector<Event> actionsReactions;
        Registry *_registries;
};

EventHandler::EventHandler(Registry *registries) : _registries(registries) {}

void EventHandler::addEvent(Event event)
{
    actionsReactions.push_back(event);
}

int EventHandler::run()
{
    for (auto& event : actionsReactions)
        event.run();
    return 1;
}

#endif /* !EVENTHANDLER_HPP_ */
