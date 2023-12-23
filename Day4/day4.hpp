/*
* As far as the Elf has been able to figure out, you have to figure out which of the numbers you have appear in the list of winning numbers. 
* The first match makes the card worth one point and each match after the first doubles the point value of that card.
* Make Cunt equal how many of your numbers are winning numbers. A cards value is 2^(Count - 1)
* E.g. Count 0 => 0, Count 1 = 1, Count 2 = 2, Count 3 = 4, Count 4 = 8
* Sum the value of all cards
*/

#include <set>
#include <string_view>

size_t getCardValue(std::string &card);