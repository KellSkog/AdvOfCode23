#include "dayxx.hpp"

int main(int argc, char **argv) {
    std::ifstream istream(argv[1]);
    std::string line;
    // using Row = std::vector<char>;
    std::vector<std::string> schematic;
    while (std::getline(istream, line)) { // A
        schematic.push_back(line);
    }
}