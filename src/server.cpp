#include "../include/server.h"
#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>
namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

void startServer(int port, const std::string& origin){
    std::cout << "Starting server on port " << port << " with origin " << origin << std::endl;
    asio::io_context ioc;
    tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), port));

    std::cout << "Server listening on port " << port << "\n";

    while (true) {
        try {
            // accept connection
            tcp::socket socket(ioc);
            acceptor.accept(socket);

            // read request
            beast::flat_buffer buffer;
            http::request<http::string_body> req;
            http::read(socket, buffer, req);

            // build fixed response
            http::response<http::string_body> res;
            res.version(req.version());
            res.result(http::status::ok);
            res.set(http::field::server, "redis-cpp");
            res.set(http::field::content_type, "text/html");
            res.body() = "Hello, World!";
            res.prepare_payload();

            // write response
            http::write(socket, res);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
