#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "day2.hpp"
/*
 * for each game, store each set sum the separate colors:
 * Game 94: 2 red, 1 blue; 7 red, 1 green, 1 blue; 1 blue, 5 red; 1 green, 10 red
 * 24 red, 3 blue, 2 green
 * The Elf would first like to know which games would have been possible if the bag contained only 12 red cubes, 13 green cubes, and 14 blue cubes?
 * Game 94 requires 24 red, thus not possible and 94 should not be added to the
 * sum of the IDs of possible games!
 * We need six variables; SetFail, IdSum, game, reds, blues & greens, update these for each set of each game by:
 * for each set: if(reds > 12 || greens > 13 || blues > 14) SetFail |= false
 * if(!SetFail) IdSum += game;
*/
TEST_CASE("testing") {
    

    SUBCASE("subtest") {
        std::ifstream istream("Day2/test1.txt");
        CHECK(istream.is_open());
        // std::array<std::string, 5> input{};
        std::string input;
        Day2::Game game{0, 0, 0, 0, 0, false};
        int totalSum = 0;
        // istream.getline(input, 8);
 
        while (std::getline(istream, input, ':')) { // A game
            // std::cout << input << "\n";
            while (std::getline(istream, input, ';')) { // A row of sets
            if(istream.peek() == '\n') {
                // std::cout << "End of line" << "\n";
                break;
            }
                // std::cout << input << "\n";
                totalSum++;
            }
        }
        CHECK(totalSum == 10);
        istream.close();
    }
    SUBCASE("Using std::stringstream") {
        std::ifstream istream("Day2/test1.txt");
        CHECK(istream.is_open());
        std::string line;
        while (std::getline(istream, line)) { // A line
            std::stringstream linestream(line);
            std::string game;
            std::getline(linestream, game, ':'); // A game
            int gameId = std::atoi(game.data()+5);
            std::cout << "gameId " << gameId << "\n";
            std::string set;
            while (std::getline(linestream, set, ';')) { // A set of colors
                std::map<std::string, int> cubes{{"red", 0}, {"green", 0}, {"blue", 0}};
                std::stringstream colors(set);
                std::string color;
                while (std::getline(colors, color, ',')) { // A color within a set
                    int index = Day2::startOf(color);
                    std::string cube = color.substr(index);
                    cubes[cube] += std::atoi(color.data());
                }
                for (const auto& [key, value] : cubes)
                    std::cout << '[' << key << "] = " << value << "; ";
                std::cout << "\n";
            }
        }
        istream.close();
        CHECK(!istream.is_open());
    }
}
