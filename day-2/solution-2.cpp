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
    std::vector<std::pair<long long,long long>> ranges;
    long long result = 0;

    // Parse the input file and store the ranges in a vector
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            long long start = std::stoll(token.substr(0, token.find('-')));
            long long end = std::stoll(token.substr(token.find('-') + 1));
            ranges.push_back(std::make_pair(start, end));
        }
    }

    for (int i = 0; i < ranges.size(); i++) {
        long long start = ranges[i].first;
        long long end = ranges[i].second;
        std::string curr;
        while (start <= end) {
            curr = std::to_string(start);
            int length = curr.size();
            bool isSequence = false;
            for (int j = 2; j <= length; j++) {
                // std::cout << "curr: " << curr << std::endl;
                if (length % j == 0) {
                    bool repeats = true;
                    int steps = length / j;
                    // std::cout << "steps: " << steps << std::endl;
                    for (int k = 0; k < length; k++) {
                        std::string firstHalf = curr.substr(k * steps, steps);
                        std::string secondHalf = curr.substr((k+1) * steps, steps);
                        if (secondHalf.empty()) break;
                        // std::cout << "k: " << k << std::endl;
                        // std::cout << "j: " << j << std::endl;
                        // std::cout << firstHalf << " - " << secondHalf << std::endl;
                        if (firstHalf != secondHalf) {
                            repeats = false;
                            break;
                        }
                    }
                    if (repeats) {
                        isSequence = true;
                        std::cout << curr << " is a sequence" << std::endl;
                        break;
                    }
                }
            }
            if (isSequence) {
                result += start;
            }
            start++;
        }
    }

    std::cout << "Result: " << result << std::endl;
 
    return 0;
}