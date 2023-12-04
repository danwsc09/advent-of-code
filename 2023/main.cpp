#include <fstream>
#include <string>
#include <iostream>
#include "constants.h"

int main() {
    std::ifstream file(std::string(INPUT_DIRECTORY) + "day1a.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}
