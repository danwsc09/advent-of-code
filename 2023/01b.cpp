#include <fstream>
#include <string>
#include <iostream>
#include "constants.h"

int find_first_digit(std::string str);
int find_last_digit(std::string str);
int find_digit_at_index(std::string str, int index);

std::unordered_map<std::string, int> map = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
};

int main() {
    std::ifstream file(std::string(INPUT_DIRECTORY) + "day1a.txt");
    std::string str;

    int result = 0;
    while (std::getline(file, str)) {
        int first_digit = find_first_digit(str);
        int last_digit = find_last_digit(str);

        std::cout << first_digit << " " << last_digit << ": " << str << std::endl;

        result += first_digit * 10 + last_digit;
    }

    std::cout << result << std::endl;

    return 0;
}

int find_first_digit(std::string str) {
    int n = str.size();
    for (int i = 0; i < n; i++) {
        int digit = find_digit_at_index(str, i);
        if (digit != 0) {
            return digit;
        }
    }
    return 0;
}

int find_last_digit(std::string str) {
    int n = str.size();
    for (int i = n-1; i >= 0; i--) {
        int digit = find_digit_at_index(str, i);
        if (digit != 0) {
            return digit;
        }
    }
    return 0;
}

int find_digit_at_index(std::string str, int index) {
    std::string substring = str.substr(index, str.size());
    char c = substring[0];
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    for (const auto& pair : map) {
        std::string digit_str = pair.first;
        int digit_value = pair.second;

        if (substring.substr(0, digit_str.size()) == digit_str) {
            return digit_value;
        }
    }

    return 0;
}