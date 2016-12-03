#include "../src/Jarvis.cpp"
#include "catch.hpp"

TEST_CASE("Jarvis parse voice", "[voice]" ) {
  REQUIRE(Jarvis::Jarvis::toArduino() == "привет");
}
