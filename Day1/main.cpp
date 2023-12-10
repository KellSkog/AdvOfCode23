#include <fstream>
#include <iostream>
#include "day1.hpp"

int main(int argc, char **argv) {
    std::ifstream file(argv[1]);
    std::string input;
    int totalSum = 0, a, b, lineCnt = 1;
    while (std::getline(file, input)) {
        auto x = locateFirstWord(input);
        auto y = locateLastWord(input);
        std::cout << "x, y " << x.second << ", " << y.second << "\n";
        auto s = locateFirstDigit(input);
        auto t = locateLastDigit(input);
        std::cout << "s, t "<< s.second << ", " << t.second << "\n";

        if(x.first !=  std::string_view::npos) {
            if(s.first !=  std::string_view::npos) {
                a = (x.first < s.first) ? x.second : s.second;
            } else {
                a = x.second;
            }
        } else {
            a = s.second;
        }
        if(y.first !=  std::string_view::npos) {
            if(t.first !=  std::string_view::npos) {
                b = (y.first > t.first) ? y.second : t.second;
            } else {
                b = y.second;
            }
        } else {
            b = t.second;
        }
        // a = ((x.first !=  std::string_view::npos) && (x.first < s.first)) ? x.second : s.second;
        // b = ((y.first !=  std::string_view::npos) && (y.first > t.first)) ? y.second : t.second;
        std::cout << "result "<< lineCnt++ << ": " << a << ", " << b << "\n";
        totalSum += a * 10 + b;
        // std::cout << a << ", " << b << "\n";
    }
    std::cout << totalSum << "\n";
    file.close();
}