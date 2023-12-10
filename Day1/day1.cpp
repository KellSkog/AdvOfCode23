#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

#include "day1.hpp"
/* The first and the last occurance in the input string of a digit is wanted.
 * It can be represented either as a digit (e.g. '1') or as a word (e.g. "one").
 * "1twothree4" -> 14.
 * "one23four" -> 14.
*/
struct Indices{
        size_t inputIndex;
        int numsIndex;
    };
// Returns the position and value of the first match from digits string in input string
auto locateFirstDigit(std::string_view str) -> std::pair<int, int>{
    // std::string digits = "0123456789";
    std::array<std::string, 10> nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    // int a = str.find_first_of(std::basic_string_view(digits, /* count= */ 1), /* pos= */ 0);
    // return std::pair<int, int>{a, std::atoi(&str[a])};
    Indices indices{str.length(), 0};
    for(int i = 0; i < nums.size(); i++) {
        int a = str.find(nums[i]);
        if( (a != std::string::npos) && (a < indices.inputIndex)) {
            indices.inputIndex = a;
            indices.numsIndex = i;
        }
    }
    if(indices.inputIndex == str.length()) {indices.inputIndex = std::string::npos;}
    return std::pair<int, int>{indices.inputIndex, indices.numsIndex};
}
// Returns the position and value of the last match from digits string in input string
auto locateLastDigit(std::string_view str) -> std::pair<int, int> {
    std::array<std::string, 10> nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    Indices indices{0, 0};
    for(int i = 0; i < nums.size(); i++) {
        int a = str.rfind(nums[i]);
        if( (a != std::string::npos) && (a > indices.inputIndex)) {
            indices.inputIndex = a;
            indices.numsIndex = i;
        }
    }
    if(indices.inputIndex == str.length()) {indices.inputIndex = std::string::npos;}
    return std::pair<int, int>{indices.inputIndex, indices.numsIndex};
}

// Finds the first digit represented as word and return its index and value
auto locateFirstWord(std::string_view str) -> std::pair<int, int> {
    // The zero gives correct index.
    std::array<std::string, 10> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    Indices indices{str.length(), 0};
    for(int i = 1; i < nums.size(); i++) { // zero not included in input!!!
        int a = str.find(nums[i]);
        if( (a != std::string::npos) && (a < indices.inputIndex)) {
            indices.inputIndex = a;
            indices.numsIndex = i;
        }
    }
    if(indices.inputIndex == str.length()) {indices.inputIndex = std::string::npos;}
    return std::pair<int, int>{indices.inputIndex, indices.numsIndex};
}
// Finds the last digit represented as word and return its index and value
auto locateLastWord(std::string_view str) -> std::pair<int, int> {
    // The zero gives correct index.
    std::array<std::string, 10> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    Indices indices{0, 0};
    for(int i = 1; i < nums.size(); i++) { // zero not included in input!!!
    // Returns position of the first character of the found substring or npos if no such substring is found. 
        int a = str.rfind(nums[i]);
        if( (a != std::string::npos) && (a > indices.inputIndex)) {
            indices.inputIndex = a;
            indices.numsIndex = i;
        }
    }
    if(indices.inputIndex == 0) {indices.inputIndex = std::string::npos;}
    return std::pair<int, int>{indices.inputIndex, indices.numsIndex};
}