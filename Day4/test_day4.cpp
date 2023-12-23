#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <array>
#include<iostream>
#include <sstream>

#include "day4.hpp"
#include "doctest.h"
/*

*/

TEST_CASE("testing") {
    SUBCASE("Test spliting") {
        std::string card{"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53"};// Extract winningNums and hadNums
        // std::cout << "Card 1 value: " << card.find(":") << "\n";

        auto colonAt = card.find(":");
        auto barAt = card.find("|");
        // Extract the substrings
        std::string winStr = card.substr(colonAt + 1, barAt - colonAt - 1);
        std::string hasStr = card.substr(barAt + 1);

        // Use a stringstream to split the substrings
        std::istringstream winStream(winStr);
        std::istringstream hasStream(hasStr);
        std::string token;
        std::vector<std::string> tokens;
        std::set<std::string> winSet;
        std::vector<std::string> hasVector;

        // Insert the numbers into the set
        while (winStream >> token) {
            winSet.insert(token);
        }

        // Insert the numbers into the vector
        while (hasStream >> token) {
            hasVector.push_back(token);
        }

        // for (const auto& token : winSet) {
        //     std::cout << token << "\n";
        // }
        // std::cout << "\n";
        // for (const auto& token : hasVector) {
        //     std::cout << token << "\n";
        // }
        int count = 0;
        for(auto num : hasVector) {
            count += winSet.count(num);
        }

            CHECK_EQ(count, 4);
    }
    SUBCASE("Test set") {
        std::set<std::string> card{"41", "48", "83", "86", "17"};// | 83 86  6 31 17  9 48 53}
        std::array<std::string, 8> nums{"83", "86", "6", "31", "17", "9", "48", "53"};
        int count = 0;
        for(auto num : nums) {
            count += card.count(num);
        }

            CHECK_EQ(count, 4);
    }
    SUBCASE("Test getCardValue") {
        std::string card{"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53"};// Extract winningNums and hadNums
        size_t count = getCardValue(card);
        CHECK_EQ(count, 4);
    }
    SUBCASE("Test powers") {
        CHECK_EQ(1 << (1 - 1), 1);
        CHECK_EQ(1 << (2 - 1), 2);
        CHECK_EQ(1 << (3 - 1), 4);
        CHECK_EQ(1 << (4 - 1), 8);
    }
}