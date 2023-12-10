#include <boost/asio.hpp>
#include <iostream>
#include <vector>
namespace asio = boost::asio;
using boost::asio::ip::udp;

const int Port_nbr = 8080;

int main() {
    try {
        asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), Port_nbr));
        std::cout << "Listens on the port 8080" << std::endl;
        while (true) {
            std::vector<char> buffer(1024);
            udp::endpoint endpoint;
            size_t size_msg = socket.receive_from(asio::buffer(buffer), endpoint);
            std::cout << "Received from " << endpoint.address().to_string() << " = " << std::string(buffer.begin(), buffer.begin() + size_msg) << std::endl;
            // ici fares on traite le message avant de le renvoyer
            socket.send_to(asio::buffer(buffer.data(), size_msg), endpoint);
        }
    } catch (std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
