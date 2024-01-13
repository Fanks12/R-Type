/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-bilal.nhari
** File description:
** SystemClearLag
*/

#ifndef SYSTEMCLEARLAG_HPP_
#define SYSTEMCLEARLAG_HPP_

class SystemClearLag : public virtual System {
    public:
        SystemClearLag(Registry &registries);
        ~SystemClearLag() = default;

        int run();
    protected:
    private:
};

SystemClearLag::SystemClearLag(Registry &registries) : System(registries) {}

SystemClearLag::run()
{
    return 1;
}

#endif /* !SYSTEMCLEARLAG_HPP_ */
