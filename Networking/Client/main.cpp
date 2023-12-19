/*
** EPITECH PROJECT, 2023
** R-TYPE
** File description:
** main
*/

#include "Client.hpp"
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char **argv)
{
    try {
        int tcp_port = 8080;
        int udp_port = 8082;

        Client client(tcp_port, udp_port);
        client.start();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
