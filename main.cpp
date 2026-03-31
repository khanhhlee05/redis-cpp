#include <iostream>
#include <string>
#include "utilities.h"

int main(int argc, char* argv[]){

    if (argc == 2 || argc == 5){
        if (argc == 2 && std::string(argv[1]) == "--clear-cache"){
           std::cout << "Clearing cache" << std::endl; // TODO: implement clearCache
        } else if (argc == 5 && std::string(argv[1]) == "--port" && std::string(argv[3]) == "--origin"){
            int port;
            if (isValidPort(argv[2])){
                port = std::stoi(argv[2]);
            } else {
                std::cout << "Invalid port" << std::endl;
                return 1;
            }

            std::string origin;
            if (isValidOrigin(argv[4])){
                origin = argv[4];
            } else {
                std::cout << "Invalid origin" << std::endl;
                return 1;
            }

            // TODO: implement startServer
            std::cout << "Starting server on port " << argv[2] << " with origin " << argv[4] << std::endl;
        } else {
            std::cout << "Usage: " << argv[0] << " --port <port> --origin <origin>" << std::endl;
            std::cout << "Usage: " << argv[0] << " --clear-cache" << std::endl;
            return 1;
        }
    } else {
        std::cout << "Usage: " << argv[0] << " --port <port> --origin <origin>" << std::endl;
        std::cout << "Usage: " << argv[0] << " --clear-cache" << std::endl;
        return 1;
    }

    return 0;
}