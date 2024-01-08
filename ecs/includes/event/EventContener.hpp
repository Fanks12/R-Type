/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Event
*/

#ifndef EVENTCONTENER_HPP_
    #define EVENTCONTENER_HPP_
    #include "functional"

class EventContener {
    public:
        EventContener() {};
        EventContener(std::function<bool()> trigger, std::function<int()> effect);
        ~EventContener() = default;

        int run()
        {
            if (action())
                return reaction();
            return 1;
        }

        template<typename Func, typename... Args>
        void setAction(Func&& fonction, Args&&... args) {
            action = [fonction, args...]() { return fonction(args...); };
        }

        template<typename Func, typename... Args>
        void setReaction(Func&& fonction, Args&&... args) {
            reaction = [fonction, args...]() { return fonction(args...); };
        }

        template<typename Func, typename... Args>
        static auto initFunct(Func&& fonction, Args&&... args) {
            return [fonction, args...]() { return fonction(args...); };
        }

        std::function<bool()> action;
        std::function<int()> reaction;
    protected:
    private:
};

EventContener::EventContener(std::function<bool()> trigger, std::function<int()> effect) : action(trigger), reaction(effect) {}

#endif /* !EVENTCONTENER_HPP_ */
