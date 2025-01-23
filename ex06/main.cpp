#include <iostream>
#include "Harl.hpp"

void harlFilter(const Harl& harl, const int filterLevel, const std::string& string) {
    int stringLevel;

    if ((stringLevel = harl.getHarlLevel(string)) >= filterLevel) {
        harl.complain(string);
    }
}

int main(int argc, const char **argv) {
    Harl harl;
    int filterLevel;

    if (argc != 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    } else if ((filterLevel = harl.getHarlLevel(argv[1])) == -1) {
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }

    harlFilter(harl, filterLevel, "WARNING");
    harlFilter(harl, filterLevel, "else");
    harlFilter(harl, filterLevel, "DEBUG");
    harlFilter(harl, filterLevel, "ERROR");
    return 0;
}
