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
        Event() {};
        Event(std::function<bool()> trigger, std::function<void()> effect);
        ~Event() = default;

        void run() { if (action()) { reaction(); } }

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

        // from here create static functions

        // action
        static std::function<bool()> everyXSecond();

        // reaction
        static std::function<void()> IdLoseXHp(int id, int x);

        std::function<bool()> action;
        std::function<void()> reaction;
    protected:
    private:
};

Event::Event(std::function<bool()> trigger, std::function<void()> effect) : action(trigger), reaction(effect) {}

#endif /* !EVENT_HPP_ */
