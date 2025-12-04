#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
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
            if (curr.size() % 2 == 0) {
                std::string firstHalf = curr.substr(0, curr.size() / 2);
                std::string secondHalf = curr.substr(curr.size() / 2);
                if (firstHalf == secondHalf) {
                    std::cout << curr << std::endl;
                    result += start;
                }
            }
            start++;
        }
    }
    
    for (const auto& range : ranges) {
        std::cout << range.first << " - " << range.second << std::endl;
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}