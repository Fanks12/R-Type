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
        void popBack();
        int run();
    protected:
    private:
        std::vector<EventContener> actionsReactions;
};

void Event::addEvent(EventContener event)
{
    actionsReactions.push_back(event);
}

void Event::popBack()
{
    actionsReactions.pop_back();
}

int Event::run()
{
    int res = 1;
    size_t size = actionsReactions.size();
    for (size_t i = 0; i < size; i++) {
        res = actionsReactions.at(i).run();
        if (!res)
            return 0;
    }
    return 1;
}

#endif /* !EVENT_HPP_ */
