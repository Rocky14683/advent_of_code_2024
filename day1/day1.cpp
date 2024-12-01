#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <sstream>
#include <map>

const std::string path = "../day1/day1_input.txt";

int main() {
    std::ifstream file(path);
    assert(file.is_open());

    std::string line;
    std::string group1, group2;
    std::vector<int> group1_values;
    std::map<int, int> freq_map;
    int sum = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        assert(iss >> group1 >> group2);

        group1_values.emplace_back(std::stoi(group1));
        freq_map[std::stoi(group2)]++;
    }

    for(const auto& val : group1_values) { // left
        sum += freq_map[val] * val;
    }


    file.close();
    std::cout << "Sum of differences: " << sum << std::endl;
    return 0;
}