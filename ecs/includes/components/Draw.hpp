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
        Draw(int _path = 0, int x = 0, int y = 0, int frame = 1) : Texture_id(_path), dim(x, y), frames(frame) {}
        ~Draw() = default;

        int Texture_id;
        std::pair<int, int> dim;
        int frames;
};

#endif /* !DRAW_HPP_ */
