#include "day4.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    std::ifstream istream(argv[1]);
    std::string line;
    // using Row = std::vector<char>;
    std::vector<std::string> cards;
    while (std::getline(istream, line)) { // A
        cards.push_back(line);
    }
    size_t wurth = 0;
    for(auto card : cards) {
        auto value = getCardValue(card);
        wurth += (value == 0) ? 0 : 1 << (value - 1);
    }
    std::cout << "Wurth: " << wurth << "\n";
}