/*
 * That's the right answer! You are one gold star closer to restoring snow operations.
 * You have completed Day 2!
 */

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "day2.hpp"

int main(int argc, char **argv) {
    std::ifstream istream(argv[1]);
    std::string input;
    int idSum = 0;
    int powerSum = 0;
    while (std::getline(istream, input)) { // A 
        std::stringstream linestream(input);
        std::string game;
        std::getline(linestream, game, ':'); // A game
        int gameId = std::atoi(game.data()+5);
        Day2::Game minGame{0}; // Track the minimum set for part 2
        std::string set;
        bool gameFail = false;
        bool setFail = false;
        while (std::getline(linestream, set, ';')) { // A set of colors
            std::map<std::string, int> cubes{{"red", 0}, {"green", 0}, {"blue", 0}};
            std::stringstream colors(set);
            std::string color;
            while (std::getline(colors, color, ',')) { // A color within a set
                int index = Day2::startOf(color);
                std::string cube = color.substr(index);
                cubes[cube] += std::atoi(color.data());
            }
            if(Day2::isNotPossible(cubes)) {
                setFail = true;
            }
            trackMin(cubes, minGame);
        }
        gameFail = setFail ? true : false;
        if(!gameFail) {
            idSum += gameId;
        }
        powerSum += minGame.reds * minGame.blues * minGame.greens;
    }
    istream.close();
    std::cout << idSum << "\n";
    std::cout << powerSum << "\n";
}