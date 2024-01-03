/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Draw
*/

#ifndef DRAW_HPP_
    #define DRAW_HPP_
    #include <string>

class Draw {
    public:
        Draw(std::string _path, int x, int y, int frame = 1) : path(_path), dim(x, y), frames(frame) {}
        ~Draw() = default;

        std::string path;
        std::pair<int, int> dim;
        int frames;
};

#endif /* !DRAW_HPP_ */
