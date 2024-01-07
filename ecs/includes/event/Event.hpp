/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SystemEvent
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_
    #include "EventContener.hpp"

class Event {

    public:
        Event() {};
        ~Event() = default;

        void addEvent(EventContener event);
        int run();
    protected:
    private:
        std::vector<EventContener> actionsReactions;
};

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
