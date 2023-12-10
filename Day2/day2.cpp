#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

#include "day2.hpp"
/* 
*/
namespace Day2 {
    size_t startOf(std::string_view color) {
        for(auto s : COL) {
            if(int index = color.find(s); index !=std::string::npos) {
                return index;
            }
        }
        std::cout << "ERROR " << color << "\n";
        return 0;
    }
    bool isNotPossible(std::map<std::string, int> &set) {
        return (set["red"] > RedMax) || (set["green"]> GreenMax) || (set["blue"] > BlueMax);
    }

    void trackMin(std::map<std::string, int> &cubes, Game &minGame) {
        if(minGame.greens < cubes["green"]) {minGame.greens = cubes["green"];}
        if(minGame.reds < cubes["red"]) {minGame.reds = cubes["red"];}
        if(minGame.blues < cubes["blue"]) {minGame.blues = cubes["blue"];}
    }
}