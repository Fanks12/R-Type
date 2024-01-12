#include "Server.hpp"
#include <iostream>
#include <string>

void printHelp()
{
    std::cout << "Usage: ./server --uport <udp_port> --tport <tcp_port>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --uport <udp_port>  Specify the UDP port number" << std::endl;
    std::cout << "  --tport <tcp_port>  Specify the TCP port number" << std::endl;
    std::cout << "  -h, --help          Show help message" << std::endl;
}

int main(int argc, char **argv)
{
    try {
        int tcpPort = 4242;
        int udpPort = 8080;

        for (int i = 1; i < argc; i += 2) {
            std::string arg(argv[i]);
            if (arg == "--uport") {
                udpPort = std::stoi(argv[i + 1]);
            } else if (arg == "--tport") {
                tcpPort = std::stoi(argv[i + 1]);
            } else if (arg == "-h" || arg == "--help") {
                printHelp();
                return 0;
            } else {
                std::cerr << "Unknown option: " << arg << std::endl;
                return 1;
            }
        }

        Server server(tcpPort, udpPort);
        server.start();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
