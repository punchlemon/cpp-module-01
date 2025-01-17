#include <cstdlib>
#include <string>
#include <iostream>

void printStringAddressAndValue(std::string* strP) {
    std::cout
        << "memory address: " << strP
        << ", "
        << "value: " << *strP
        << std::endl;
}

int main( void ) {
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;
    printStringAddressAndValue(&string);
    printStringAddressAndValue(stringPTR);
    printStringAddressAndValue(&stringREF);
    return EXIT_SUCCESS;
}
