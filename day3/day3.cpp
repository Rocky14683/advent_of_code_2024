#include <iostream>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <sstream>
#include <map>
#include <regex>

const std::string path = "../day3/day3_input.txt";

int main() {
    std::ifstream file(path);
    assert(file.is_open());
    std::string line;
    std::string content;
    while (std::getline(file, line)) {
        content.append(line);
    }
    file.close();

    std::regex mul_regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::regex do_regex(R"(do\(\))");
    std::regex dont_regex(R"(don't\(\))");
    std::smatch match;
    int sum = 0;
    bool mul_enabled = true;


    for (auto it = content.begin(); it != content.end();) {
        std::string sub_content(it, content.end());
        std::smatch do_match, dont_match, mul_match;
        bool found_do = std::regex_search(sub_content, do_match, do_regex);
        bool found_dont = std::regex_search(sub_content, dont_match, dont_regex);
        bool found_mul = std::regex_search(sub_content, mul_match, mul_regex);

        if (found_do && (!found_dont || do_match.position() < dont_match.position()) && (!found_mul || do_match.position() < mul_match.position())) {
            mul_enabled = true;
            it += do_match.position() + do_match.length();
        } else if (found_dont && (!found_do || dont_match.position() < do_match.position()) && (!found_mul || dont_match.position() < mul_match.position())) {
            mul_enabled = false;
            it += dont_match.position() + dont_match.length();
        } else if (found_mul && (!found_do || mul_match.position() < do_match.position()) && (!found_dont || mul_match.position() < dont_match.position())) {
            if (mul_enabled) {
                int x = std::stoi(mul_match[1].str());
                int y = std::stoi(mul_match[2].str());
                sum += x * y;
            }
            it += mul_match.position() + mul_match.length();
        } else {
            break;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}