#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

long long largestNumber(std::string number);

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
    long long sum = 0;
    while (std::getline(input, line)) {
        long long curr = largestNumber(line);
        std::cout << curr << std::endl;
        sum += curr;
    }
    
    std::cout << sum << std::endl;
    return 0;
}

long long largestNumber(std::string number) {
    int length = number.size();
    int digits = 11;
    int idx = -1;
    std::string result = "0";
    
    
    while (digits >= 0) {
        int startIdx = length - 1 - digits;
        char curr = number[startIdx];
        int tempIdx = 0;
        for (int i = startIdx; i > idx; i--) {
            char temp = number[i];
            std::cout << "i: " << i << std::endl;
            std::cout << "temp: " << temp << std::endl;
            if (temp >= curr) {
                curr = temp; 
                tempIdx = i;
            }
        }
        idx = tempIdx;
        result.push_back(curr);
        digits--;
    }
    return std::stoll(result);
}