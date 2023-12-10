#include <string_view>
#include <utility>
auto locateFirstDigit(std::string_view str) -> std::pair<int, int>;
auto locateLastDigit(std::string_view str) -> std::pair<int, int>;
auto locateFirstWord(std::string_view str) -> std::pair<int, int>;
auto locateLastWord(std::string_view str) -> std::pair<int, int>;