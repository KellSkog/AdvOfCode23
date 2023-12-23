/*
 * Input is a file with X*X characters, sum all numbers adjacent to any of ".$%*#+-=/&@"
 */

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "day3.hpp"

int main(int argc, char **argv) {
    std::ifstream istream(argv[1]);
    std::string line;
    // using Row = std::vector<char>;
    std::vector<std::string> schematic;
    while (std::getline(istream, line)) { // A
        schematic.push_back(line);
    }
    int partNoSum = 0;
    for(size_t row = 0; row < schematic.size(); row++) { // For each row
        for (size_t start = schematic[row].find_first_of("123456789"); start != std::string::npos; start = schematic[row].find_first_of("123456789", start)) {
            Number num{.row = row, .colStart = start};
            num.colEnd = schematic[row].find_first_not_of("0123456789", start);
            num.value = std::stoi(schematic[row].substr(num.colStart, num.colEnd));
            // std::cout << "Value " << num.value << ", Row " << num.row << ", colStart " << num.colStart << ", colEnd " << num.colEnd << "\n";
            if(isPartNo(num, schematic)) {
                partNoSum += num.value;
            }
            start = num.colEnd;
        }
        
    }
    std::cout << "Sum: " << partNoSum << "\n";
}