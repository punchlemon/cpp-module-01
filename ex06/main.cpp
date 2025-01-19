#include <iostream>
#include <vector>
#include "Harl.hpp"

bool harlFilter(std::map<std::string, int> order, const std::string& filter,
    const std::vector<std::string>& stringVector) {
    Harl harl;
    std::map<std::string, int>::iterator filterIt = order.find(filter);
    if (filterIt == order.end()) {
        return false;
    }
    int filterLevel = filterIt->second;
    for (size_t i = 0; i < stringVector.size(); ++i) {
        if (filterLevel <= order.find(stringVector[i])->second) {
            harl.complain(stringVector[i]);
        }
    }
    return true;
}

int main(int argc, const char **argv) {
    std::map<std::string, int> order;
    order["DEBUG"] = 1;
    order["INFO"] = 2;
    order["WARNING"] = 3;
    order["ERROR"] = 4;

    if (argc != 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }

    std::vector<std::string> stringVector;
    stringVector.push_back("WARNING");
    stringVector.push_back("else");
    stringVector.push_back("DEBUG");
    stringVector.push_back("ERROR");
    if (!harlFilter(order, argv[1], stringVector)) {
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }
    return 0;
}
