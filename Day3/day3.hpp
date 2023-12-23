/* In a two dimensional array of chars
 * numbers of 1, 2 or 3 characters are located
 * If a number is adjacent to any symbol of "$%*#+-=/&@", it is classified as a "part number"
 */

#include <string>
#include <string_view>
#include <vector>

// using strsze_t = std::string::size_type;
struct Number{
    int value;
    size_t row;
    size_t colStart;
    size_t colEnd;
};


/* Check if adjacent to any symbol of "$%*#+-=/&@"*/
bool isPartNo(Number const &num, std::vector<std::string> const &lines);