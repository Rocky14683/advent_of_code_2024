#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <sstream>

const std::string path = "../day2/day2_input.txt";

bool is_safe(const std::vector<int>& tokens) {
    if (tokens.size() < 2) return true;
    bool increasing = tokens[1] > tokens[0];
    for (size_t i = 1; i < tokens.size(); ++i) {
        if ((tokens[i] > tokens[i - 1]) != increasing || !(abs(tokens[i] - tokens[i - 1]) >= 1 && abs(tokens[i] - tokens[i - 1]) <= 3)) {
            return false;
        }
    }
    return true;
}

bool is_safe_with_dampener(const std::vector<int>& tokens) {
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::vector<int> modified_tokens = tokens;
        modified_tokens.erase(modified_tokens.begin() + i);
        if (is_safe(modified_tokens)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream file(path);
    assert(file.is_open());
    std::string line;
    int prev_num = 0;
    bool increasing = true;
    int num_safe = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> tokens;
        int number;
        while (iss >> number) {
            tokens.push_back(number);
        }

        if (is_safe(tokens) || is_safe_with_dampener(tokens)) {
            num_safe++;
        }
    }

    std::cout << "Number of safe: " << num_safe << std::endl;
    file.close();
    return 0;
}