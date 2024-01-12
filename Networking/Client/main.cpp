#include "Client.hpp"
#include <iostream>
#include <string>

void printHelp()
{
    std::cout << "Usage: ./client --ip <server_ip> --uport <udp_port>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --ip <server_ip>    Specify the server IP address" << std::endl;
    std::cout << "  --uport <udp_port>  Specify the UDP port number" << std::endl;
    std::cout << "  -h, --help          Show help message" << std::endl;
}

int main(int argc, char **argv)
{
    try {
        int tcp_port = 4242;
        int udp_port = 8080;
        std::string server_ip = "127.0.0.1";

        for (int i = 1; i < argc; ++i) {
            std::string arg(argv[i]);
            if (arg == "--ip" && i + 1 < argc) {
                server_ip = argv[i + 1];
            } else if (arg == "--uport" && i + 1 < argc) {
                udp_port = std::stoi(argv[i + 1]);
            } else if (arg == "-h" || arg == "--help") {
                printHelp();
                return 0;
            }
        }

        Client client(server_ip, tcp_port, udp_port);
        client.start();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
