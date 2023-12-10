/*
 * The power of a set of cubes is equal to the numbers of red, green, and blue cubes multiplied together.
 * E.g. Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
 * In game 1, the game could have been played with as few as 4 red, 2 green, and 6 blue cubes.
 * The power of the minimum set of cubes in game 1 is 4*2*6 = 48. In games 2-5 it was 12, 1560, 630, and 36, respectively.
 * Adding up these five powers produces the sum 2286.

 * For each game, find the minimum set of cubes that must have been present.
*/

#include<array>
#include <map>
#include <string>
#include <string_view>
#include <utility>

namespace Day2 {
    constexpr size_t RedMax = 12;
    constexpr size_t GreenMax = 13;
    constexpr size_t BlueMax = 14;

    constexpr std::array<std::string, 3> COL{"red", "green", "blue"};

    struct Game{
        size_t IdSum;
        size_t game;
        size_t reds;
        size_t blues;
        size_t greens;
        bool SetFail;
    };
    /*
     * Find the start of a color word in the input string
    */
    size_t startOf(std::string_view color); 

    /*
    */
   bool isNotPossible(std::map<std::string, int> &set);

   /*
   */
  void trackMin(std::map<std::string, int> &cubes, Game &minGame);
}