#include <queue>
#include <fstream>

void replaceAndWriteWithoutNewline(std::ifstream& inputFile, std::ofstream& outputFile,
                                   const std::string& target, const std::string& replacement,
                                   bool inputFileEndsWithNewline)
{
    std::string line;
    while (std::getline(inputFile, line)) {
        if (inputFile.peek() != EOF || inputFileEndsWithNewline)
            line += '\n';
        size_t pos = 0;
        while ((pos = line.find(target, pos)) != std::string::npos) {
            line.erase(pos, target.length());
            line.insert(pos, replacement);
            pos += replacement.length();
        }
        outputFile << line;
    }
}

void replaceAndWriteWithNewline(std::ifstream& inputFile, std::ofstream& outputFile,
                                const std::string& target, const std::string& replacement,
                                bool inputFileEndsWithNewline,
                                bool targetEndsWithNewline,
                                size_t newlineCount)
{
    std::queue<std::string> lineBuffer;
    std::string buffer;
    std::string line;
    size_t pos;

    while (std::getline(inputFile, line)) {
        if (inputFile.peek() != EOF || inputFileEndsWithNewline)
            line += '\n';
        buffer += line;
        lineBuffer.push(line);

        if (targetEndsWithNewline) {
            if (lineBuffer.size() < newlineCount) {
                continue;
            }
        } else if (lineBuffer.size() < (newlineCount + 1)) {
            continue;
        }

        pos = 0;
        while ((pos = buffer.find(target, pos)) != std::string::npos) {
            buffer.erase(pos, target.length());
            buffer.insert(pos, replacement);
            pos += replacement.length();
        }
        if (pos == std::string::npos) {
            outputFile << lineBuffer.front();
            buffer.erase(0, lineBuffer.front().length());
            lineBuffer.pop();
        } else {
            outputFile << buffer.substr(0, pos);
            buffer.erase(0, pos);
            while (!lineBuffer.empty()) {
                lineBuffer.pop();
            }
            lineBuffer.push(buffer);
        }

    }
    if (!buffer.empty()) {
        outputFile << buffer;
    }
}

void replaceAndWrite(std::ifstream& inputFile, std::ofstream& outputFile,
                     const std::string& target, const std::string& replacement) {

    if (inputFile.peek() == EOF)
        return;

    bool containsNewline = (target.find('\n') != std::string::npos);

    bool targetEndsWithNewline = false;
    size_t newlineCount = 0;
    for (size_t i = 0; i < target.size(); i++) {
        if (target[i] == '\n') {
            newlineCount++;
        }
    }
    targetEndsWithNewline = target[target.size() - 1] == '\n';

    inputFile.seekg(0, std::ios::end);
    inputFile.seekg(-1, std::ios::cur);
    bool inputFileEndsWithNewline = (inputFile.tellg() > 0 && inputFile.peek() == '\n');
    inputFile.seekg(0, std::ios::beg);

    if (containsNewline == 0) {
        replaceAndWriteWithoutNewline(inputFile, outputFile,
                                      target, replacement,
                                      inputFileEndsWithNewline);
    } else {
        replaceAndWriteWithNewline(inputFile, outputFile,
                                   target, replacement,
                                   inputFileEndsWithNewline,
                                   targetEndsWithNewline,
                                   newlineCount);
    }
}
