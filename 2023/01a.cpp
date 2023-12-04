#include <fstream>
#include <string>
#include <iostream>
#include "constants.h"

int main() {
    std::ifstream file(std::string(INPUT_DIRECTORY) + "day1a.txt");
    std::string str;

    int result = 0;
    while (std::getline(file, str)) {
        int firstDigit;
        int lastDigit;
        int i = 0;
        int n = str.size();

        while (i < n && (str[i] < '0' || str[i] > '9')) {
            i++;
        }
        firstDigit = str[i] - '0';

        i = n - 1;
        while (i >= 0 && (str[i] < '0' || str[i] > '9')) {
            i--;
        }
        lastDigit = str[i] - '0';

        result += firstDigit * 10 + lastDigit;
    }

    std::cout << result << std::endl;

    return 0;
}
