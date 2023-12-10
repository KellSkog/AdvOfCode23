#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "day1.hpp"
#include <string>

TEST_CASE("testing") {
    std::string input = "gphnqxhlhzzftghk767";
    auto s = locateFirstDigit(input);
    CHECK(s.first ==  16);
    CHECK(s.second ==  7);
    auto t = locateLastDigit(input);
    CHECK(t.first ==  18);
    CHECK(t.second ==  7);
}
