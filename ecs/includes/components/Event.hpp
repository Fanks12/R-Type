/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_
    #include "functional"

class Event {
    public:
        Event(std::function<bool()> trigger, std::function<bool()> effect);
        ~Event() = default;

        std::function<bool()> action;
        std::function<void()> reaction;
    protected:
    private:
};

Event::Event(std::function<bool()> trigger, std::function<bool()> effect) : action(trigger), reaction(effect) {}

#endif /* !EVENT_HPP_ */
