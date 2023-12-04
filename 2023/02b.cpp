#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "constants.h"

int main() {
    std::ifstream file(std::string(INPUT_DIRECTORY) + "day2a.txt");
    std::string line;

    int sum_of_products = 0;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        int colon_index = line.find(":");

        int line_index = colon_index + 2;
        int max_red = 0, max_green = 0, max_blue = 0;

        while (line_index < line.size()) {
            int start = line_index;
            while (line_index < line.size() && line[line_index] != ';') {
                line_index++;
            }

            // "18 red, 5 blue, 1 green"
            std::string cube_string = line.substr(start, line_index - start);
            std::cout << cube_string << std::endl;

            int red = 0, green = 0, blue = 0;
            int delimit_index = 0;
            int start_index;

            while (delimit_index < cube_string.size()) {
                start_index = delimit_index;
                delimit_index = cube_string.find(", ", start_index);

                // "18 red"
                std::string color_count_string = cube_string.substr(start_index, delimit_index - start_index);
                int count = std::stoi(color_count_string);
                int color_index = color_count_string.find(" ") + 1;
                std::string color = color_count_string.substr(color_index, color_count_string.size() - color_index);

                if (color == "red") {
                    red += count;
                } else if (color == "blue") {
                    blue += count;
                } else if (color == "green") {
                    green += count;
                }

                max_red = std::max(max_red, red);
                max_green = std::max(max_green, green);
                max_blue = std::max(max_blue, blue);


                if (delimit_index == std::string::npos) break;
                delimit_index += 2;
            }

            line_index += 2;
        }

        sum_of_products += max_red * max_green * max_blue;
    }

    std::cout << sum_of_products << std::endl;

    return 0;
}
