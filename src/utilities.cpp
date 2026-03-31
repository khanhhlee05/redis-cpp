
#include <string>
#include "../include/utilities.h"

bool isValidPort(const std::string& port) {
    try {
        int portInt = std::stoi(port);
        return portInt > 0 && portInt < 65536;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    } catch (const std::exception& e) {
        return false;
    }
}

bool isValidOrigin(const std::string& url) {
    return url.rfind("http://", 0) == 0 ||
           url.rfind("https://", 0) == 0;
}
