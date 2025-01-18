#include <iostream>
#include <fstream>
#include <cstdlib>

void replaceAndWrite(std::ifstream& inputFile, std::ofstream& outputFile,
                     const std::string& target, const std::string& replacement);

int main(int argc, char **argv) {
    std::string replaceExtention = ".replace";
    if (argc != 4) {
        std::cerr << "Error: Number of args is wrong" << std::endl;
        return EXIT_FAILURE;
    }
    std::string fileName = argv[1];
    std::string targetString = argv[2];
    std::string replacementString = argv[3];

    if (targetString.empty()) {
        std::cerr << "Error: Target string is empty." << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream inputFile(fileName.c_str(), std::ios::in | std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error: Could not open '" << argv[1] << "'" << std::endl;
        return EXIT_FAILURE;
    }

    std::string fileNameReplace = argv[1];
    fileNameReplace.append(replaceExtention);
    std::ofstream outputFile(fileNameReplace.c_str(), std::ios::out | std::ios::binary);
    if (!outputFile) {
        inputFile.close();
        std::cerr << "Error: Could not open '" << argv[1] << replaceExtention << std::endl;
        return EXIT_FAILURE;
    }

    replaceAndWrite(inputFile, outputFile, targetString, replacementString);

    inputFile.close();
    outputFile.close();

    return EXIT_SUCCESS;
}
