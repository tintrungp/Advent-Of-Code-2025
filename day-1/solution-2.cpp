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
        bool wasZero = false;
        nextStep = std::stoi(line.substr(1));
        int overflow = nextStep / maxIdx;
        nextStep %= maxIdx;
        if (line[0] == 'R') {
            currIdx += nextStep;
            if (currIdx > 100) overflow++;
            currIdx %= maxIdx;
        } else {
            wasZero = (currIdx == 0);
            currIdx -= nextStep;
            if (currIdx < 0) {
                currIdx += maxIdx;
                if (!wasZero) overflow++;
            }
        }
        if (currIdx == 0) {
            password++;
        }
        // std::cout << "Overflow: " << overflow << std::endl;
        // std::cout << "Password: " << password << std::endl;
        password += overflow;
    }

    std::cout << "Password: " << password << std::endl;
    return 0;
}