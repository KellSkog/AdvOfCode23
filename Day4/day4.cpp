#include<sstream>
#include<string>
#include <vector>

#include "day4.hpp"

size_t getCardValue(std::string &card) {
    auto colonAt = card.find(":");
    auto barAt = card.find("|");
    // Extract the substrings
    auto winStr = card.substr(colonAt + 1, barAt - colonAt - 1);
    auto hasStr = card.substr(barAt + 1);

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
    size_t count = 0;
    for(auto num : hasVector) {
        count += winSet.count(num);
    }
    return count;
}