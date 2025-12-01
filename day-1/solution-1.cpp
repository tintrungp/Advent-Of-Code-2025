#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("input-1.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    std::string line;
    const int maxIdx = 100;
    int currIdx = 50;
    int password = 0;
    int nextStep;
    while (std::getline(input, line)) {
        nextStep = std::stoi(line.substr(1));
        if (line[0] == 'R') {
            currIdx += nextStep;
            currIdx %= maxIdx;
        } else {
            nextStep %= maxIdx;
            currIdx -= nextStep;
            if (currIdx < 0) currIdx += maxIdx;
        }

        if (currIdx == 0) password++;
    }

    std::cout << "Password: " << password << std::endl;
    return 0;
}