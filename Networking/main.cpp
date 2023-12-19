#include "Server.hpp"
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char **argv)
{
    try {
        po::options_description desc("Options");
        desc.add_options()
            ("help", "Show help message")
            ("tcp_port", po::value<int>()->default_value(8082), "Specify the TCP port number")
            ("udp_port", po::value<int>()->default_value(8080), "Specify the UDP port number");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

        int tcpPort = vm["tcp_port"].as<int>();
        int udpPort = vm["udp_port"].as<int>();

        Server server(tcpPort, udpPort);
        server.start();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
