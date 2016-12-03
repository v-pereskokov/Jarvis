#include "../include/Jarvis.hpp"
#include "catch.hpp"

TEST_CASE("Jarvis parse voice", "[voice]" ) {
  REQUIRE(Jarvis::Jarvis::toArduino() == "привет");
}
