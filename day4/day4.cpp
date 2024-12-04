#include <iostream>
#include <fstream>
#include <cassert>

const std::string path = "../day4/day4_input.txt";
const std::string target1 = "MAS";
const std::string target2 = "MARS";

bool check_xmas(const std::vector<std::string>& word_grid, int row, int col) {
    int rows = word_grid.size();
    int cols = word_grid[0].size();

    if (row - 1 < 0 || row + 1 >= rows || col - 1 < 0 || col + 1 >= cols) { return false; }

    std::string diag1 = {word_grid[row - 1][col - 1], word_grid[row][col], word_grid[row + 1][col + 1]};
    std::string diag2 = {word_grid[row - 1][col + 1], word_grid[row][col], word_grid[row + 1][col - 1]};

    return (diag1 == "MAS" || diag1 == "SAM") && (diag2 == "MAS" || diag2 == "SAM");
}

int count_xmas(const std::vector<std::string>& word_grid) {
    int count = 0;

    for (int row = 0; row < word_grid.size(); ++row) {
        for (int col = 0; col < word_grid[0].size(); ++col) {
            if (check_xmas(word_grid, row, col)) { count++; }
        }
    }

    return count;
}

int main() {
    std::ifstream file(path);
    assert(file.is_open());
    std::string line;
    std::vector<std::string> word_grid;
    while (std::getline(file, line)) {
        word_grid.emplace_back(line);
    }
    file.close();

    auto times = count_xmas(word_grid);
    std::cout << times << std::endl;
    return 0;
}