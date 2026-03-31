#include "server.h"
#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>


namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

void startServer(int port, std::string origin){
    std::cout << "Starting server on port " << port << " with origin " << origin << std::endl;
    asio::io_context ioc;
    tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port));

    std::cout << "Server listening on port " << port << "\n";

    while (true) {
        tcp::socket socket(ioc);
        acceptor.accept(socket);

        // read request
        // build fixed response
        // write response
    }
}