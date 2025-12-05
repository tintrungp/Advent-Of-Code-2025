#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    // Check if the input file is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    std::string line;
    int sum = 0;
    while (std::getline(input, line)) {
        std::cout << line << std::endl;

        char num1 = line[0];
        char num2 = line[1];
        std::string total;

        int max = INT_MIN;
        for (int i = 1; i < line.size(); i++) {

            
            
            num2 = line[i];
            std::cout << num1 << " " << num2 << std::endl;
            total.push_back(num1);
            total.push_back(num2);
            if (stoi(total) > max) max = stoi(total);
            if (num2 > num1) num1 = num2;
            total.clear();
        }
        std::cout << max << std::endl;
        sum += max;
    }
    std::cout << sum << std::endl;
    return 0;
}