/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemEvent
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_
    #include "Registry.hpp"
    #include "ISystem.hpp"
    #include "Component.hpp"

class Registry;

class Event {

    public:
        Event(Registry *registries);
        ~Event() = default;

        void addEvent(EventContener event);
        int run();

        // from here create static functions

        // action
        static std::function<bool()> everyXSecond();

        // reaction
        static std::function<void()> IdLoseXHp(int id, int x);
    protected:
    private:
        std::vector<EventContener> actionsReactions;
        Registry *_registries;
};

Event::Event(Registry *registries) : _registries(registries) {}

void Event::addEvent(EventContener event)
{
    actionsReactions.push_back(event);
}

int Event::run()
{
    for (auto& event : actionsReactions)
        event.run();
    return 1;
}

#endif /* !EVENT_HPP_ */
