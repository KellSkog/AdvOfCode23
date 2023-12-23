#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "day3.hpp"
/*

*/

TEST_CASE("testing") {
    SUBCASE("Using Day3/test1.txt") {
        std::ifstream istream("Day3/test1.txt");
        CHECK(istream.is_open());
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(istream, line)) {
            lines.push_back(line);
        }
        CHECK(lines[1][3] == '*');

        int partNoSum = 0;
        for(size_t row = 0; row < lines.size(); row++) { // For each row
            for (size_t start = lines[row].find_first_of("123456789"); start != std::string::npos; start = lines[row].find_first_of("123456789", start)) {
                Number num{.row = row, .colStart = start};
                num.colEnd = lines[row].find_first_not_of("0123456789", start);
                // std::cout << ", Start " << num.colStart << ", substr " << lines[row].substr(num.colStart, num.colEnd) << ", colEnd " << num.colEnd << "\n";
                num.value = std::stoi(lines[row].substr(num.colStart, num.colEnd));
                // std::cout << "Value " << num.value << ", Row " << num.row << ", colStart " << num.colStart << ", colEnd " << num.colEnd << "\n";
                if(isPartNo(num, lines)) {
                    partNoSum += num.value;
                    // std::cout << "Value " << num.value << "\n";
                }
                start = num.colEnd;
            }
            
        }
        istream.close();
        CHECK(!istream.is_open());
        CHECK(partNoSum == 4361);
        CHECK(467+35+633+617+592+755+664+598 == 4361);
        std::cout << "PartNoSum " << partNoSum << "\n";
    }
    SUBCASE("Test isPartNo") {
        std::ifstream istream("Day3/test2.txt");
        CHECK(istream.is_open());
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(istream, line)) {
            lines.push_back(line);
        }

/* struct Number{
    int value;
    size_t row;
    size_t colStart;
    size_t colEnd;
};*/

        Number num633{633, 2, 6, 9};
        auto res = isPartNo(num633, lines);
        CHECK(res);

        Number num666{666, 1, 7, std::string::npos};
        CHECK(isPartNo(num666, lines));

        Number num35{35, 2, 2, 4};
        CHECK(isPartNo(num35, lines));

        Number num58{58, 5, 7, 9};
        CHECK_FALSE(isPartNo(num58, lines));

        Number num592{592, 6, 2, 5};
        CHECK(isPartNo(num592, lines));

        Number num467{467, 0, 0, 3};
        CHECK(isPartNo(num467, lines));

        Number num617{617, 4, 0, 3};
        CHECK(isPartNo(num617, lines));
    }
}
/* A gear is any * symbol that is adjacent to exactly two part numbers. Its gear ratio is the result of multiplying those two numbers together.
 * Find the gear ratio of every gear and add them all up.
 * In the known input, there are no stars at the edges!*/
TEST_CASE("Gears") {
    SUBCASE("Day3/test1.txt") {
        std::ifstream istream("Day3/test1.txt");
        CHECK(istream.is_open());
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(istream, line)) {
            lines.push_back(line);
        }
        // For every star, search for adjacent digits from different numbers, if two are found: it's a gear!
        for(auto line : lines) {
            line.fin
        }
        // 489*540, 906*634....
        istream.close();
        CHECK(!istream.is_open());
    }
}