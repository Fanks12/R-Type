/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-bilal.nhari
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_
    #include <chrono>

class Clock {
    public:
        Clock() { start(); };
        ~Clock() = default;
        void start() {
            startTime = std::chrono::high_resolution_clock::now();
        }

        void stop() {
            endTime = std::chrono::high_resolution_clock::now();
        }

        int elapsedTime() {
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
            return duration.count();
        }

    private:
        std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::high_resolution_clock::time_point endTime;
};

#endif /* !CLOCK_HPP_ */
