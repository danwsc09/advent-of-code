#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h>
#include "constants.h"

bool is_adjacent_to_symbol(const std::vector<std::string>& graph, int row, int start, int end);
bool is_special_symbol(char c);

int main() {
    std::ifstream file(std::string(INPUT_DIRECTORY) + "day3a.txt");
    std::string line;

    int result_sum = 0;
    std::vector<std::string> graph;

    while (std::getline(file, line)) {
        if (line.length() == 0) break;
        graph.push_back(line.substr(0, line.size()));
    }

    for (int row = 0; row < graph.size(); row++) {
        std::string row_str = graph[row];

        int j = 0;
        while (j < row_str.size()) {
            while (j < row_str.size() && row_str[j] == '.') {
                j++;
            }

            if (j == row_str.size()) break;

            if (isdigit(row_str[j])) {
                int start = j;
                while (j < row_str.size() && isdigit(row_str[j])) {
                    j++;
                }

                int number = std::stoi(row_str.substr(start, j - start));

                // check the box around graph[row][start..j-1] for non-digit, non-'.' characters
                if (is_adjacent_to_symbol(graph, row, start, j - 1)) {
                    result_sum += number;
                }

            } else { // is a symbol
                j++;
            }
        }

    }

    std::cout << result_sum << std::endl;
    return 0;
}

// start and end are inclusive
bool is_adjacent_to_symbol(const std::vector<std::string>& graph, int row, int start, int end) {
    // check row above
    if (row > 0) {
        if (start > 0 && is_special_symbol(graph[row - 1][start - 1])) {
                return true;
        }
        if (end < graph[row].size() - 1 && is_special_symbol(graph[row - 1][end + 1])) {
            return true;
        }
        for (int i = start; i <= end; i++) {
            if (is_special_symbol(graph[row - 1][i])) {
                return true;
            }
        }
    }

    // check before start
    if (start > 0 && is_special_symbol(graph[row][start - 1])) {
        return true;
    }

    // check after end
    if (end < graph[row].size() - 1 && is_special_symbol(graph[row][end + 1])) {
        return true;
    }

    // check row below
    if (row < graph.size() - 1) {
        if (start > 0 && is_special_symbol(graph[row + 1][start - 1])) {
            return true;
        }
        if (end < graph[row].size() - 1 && is_special_symbol(graph[row + 1][end + 1])) {
            return true;
        }
        for (int i = start; i <= end; i++) {
            if (is_special_symbol(graph[row + 1][i])) {
                return true;
            }
        }
    }

    return false;
}

bool is_special_symbol(char c) {
    if (c >= '0' && c <= '9') return false;
    if (c == '.') return false;
    return true;
}