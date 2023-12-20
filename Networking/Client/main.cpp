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
        int tcp_port = 4242;
        int udp_port = 8080;
        std::string server_ip = "127.0.0.1";

        Client client(server_ip, tcp_port, udp_port);
        std::cout << "Client started" << std::endl;
        client.start();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
