#include <iostream> // TODO: remove, debug

#include "day3.hpp"

/* There are nine searches possible
 * No edge,
 * left edge, right edge, top edge, bottom edge, 
 * top left corner, top right corner, bottom left corner, bottom right corner
 * The search must not extend beyond neighboring cells!!!!!
 */
bool isPartNo(Number const &num, std::vector<std::string> const &lines) {
// Search row above, below and char before and after
    bool found = false;
    if(num.row == 0) { // top edge
        if(num.colStart == 0) { // Nothing before, check below and right
            found = (lines[num.row + 1].substr(num.colStart, (num.colEnd - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, after
            found = (lines[num.row].substr(num.colEnd, 1).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // After
        } else if(num.colEnd == std::string::npos) { // Nothing after, check before and below
            found = (lines[num.row + 1].substr(num.colStart - 1, (num.colEnd - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, before
            found = (lines[num.row].substr(num.colStart - 1, 1).find_first_of("$%*#+-=/&@") != std::string::npos) ? true : found; //Before
        } else { // Not first or last column, check before, after and below
            found = (lines[num.row].substr(num.colStart - 1, 1).find_first_of("$%*#+-=/&@") != std::string::npos) ? true : found; //Before
            found = (lines[num.row].substr(num.colEnd, 1).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // After
            found = (lines[num.row + 1].substr(num.colStart - 1, (num.colEnd - num.colStart + 2)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, before, after
        }
    } else if(num.row == lines.size() - 1) { // Bottom edge
        if(num.colStart == 0) { // Nothing before, check above and right
            found = (lines[num.row -1].substr(num.colStart, (num.colEnd - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, after
            found = (lines[num.row].substr(num.colEnd, 1).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // After
        } else if(num.colEnd == std::string::npos) { // Nothing after, check before and above
            found = (lines[num.row - 1].substr(num.colStart - 1, (num.colEnd - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, before
            found = (lines[num.row].substr(num.colStart - 1, 1).find_first_of("$%*#+-=/&@") != std::string::npos) ? true : found; //Before
        } else { // Not first or last column, check before, after and above
            found = (lines[num.row].substr(num.colStart - 1, 1).find_first_of("$%*#+-=/&@") != std::string::npos) ? true : found; //Before
            found = (lines[num.row].substr(num.colEnd, 1).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // After
            found = (lines[num.row - 1].substr(num.colStart - 1, (num.colEnd - num.colStart + 2)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Above, before, after
        }
    } else { // Not touching top or bottom edge
        // std::cout << "Else " << lines[num.row - 1] << " colEnd, " << num.colEnd << "\n";
        if(num.colStart == 0) { // Nothing before, check above, below and after
            found = (lines[num.row - 1].substr(num.colStart, (num.colEnd - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Above, after
            found = (lines[num.row + 1].substr(num.colStart, (num.colEnd - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, after
            found = (lines[num.row].substr(num.colEnd, 1).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // After
        } else if(num.colEnd == std::string::npos) { // Nothing after, check before, below and above
            // std::cout << "npos " << num.colStart << ", " << (lines[num.row - 1].length()) <<  ", " << "\n";
            // std::cout << " Above " << (lines[num.row - 1].substr(num.colStart - 1, (lines[num.row - 1].length() - num.colStart + 1))) << "\n";
            found = (lines[num.row].substr(num.colStart - 1, 1).find_first_of("$%*#+-=/&@") != std::string::npos) ? true : found; //Before
            found = (lines[num.row - 1].substr(num.colStart - 1, (lines[num.row - 1].length() - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Above, before
            found = (lines[num.row + 1].substr(num.colStart - 1, (lines[num.row + 1].length() - num.colStart + 1)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, before
        } else { // No edges!
            // std::cout << "Else " << lines[num.row - 1] << " colEnd, " << num.colEnd << "\n";
            // size_t findFrom = =0;
            found = (lines[num.row - 1].substr(num.colStart - 1, (num.colEnd - num.colStart + 2)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Above, before, after
            found = (lines[num.row + 1].substr(num.colStart - 1, (num.colEnd - num.colStart + 2)).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // Below, before, after
            found = (lines[num.row].substr(num.colStart - 1, 1).find_first_of("$%*#+-=/&@") != std::string::npos) ? true : found; //Before
            found = (lines[num.row].substr(num.colEnd, 1).find_first_of("$%*#+-=/&@")   != std::string::npos) ? true : found; // After
        }
    }
    return found;
}