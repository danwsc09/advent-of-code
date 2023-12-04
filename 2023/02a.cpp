#include <fstream>
#include <string>
#include <iostream>
#include "constants.h"

// 12 red cubes, 13 green cubes, and 14 blue cubes
int MAX_RED = 12;
int MAX_GREEN = 13;
int MAX_BLUE = 14;

int main() {
    std::ifstream file(std::string(INPUT_DIRECTORY) + "day2a.txt");
    std::string line;

    int valid_game_id_sum = 0;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        int colon_index = line.find(":");
        int game_id = std::stoi(line.substr(5, colon_index));

        bool is_valid_game = true;
        int line_index = colon_index + 2;

        while (line_index < line.size()) {
            int start = line_index;
            while (line_index < line.size() && line[line_index] != ';') {
                line_index++;
            }
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

                if (red > MAX_RED || green > MAX_GREEN || blue > MAX_BLUE) {
                    is_valid_game = false;
                    break;
                }


                if (delimit_index == std::string::npos) break;
                delimit_index += 2;
            }

            line_index += 2;
        }

        if (is_valid_game) {
            valid_game_id_sum += game_id;
        }

    }

    std::cout << valid_game_id_sum << std::endl;

    return 0;
}
