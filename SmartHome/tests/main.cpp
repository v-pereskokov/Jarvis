#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Jarvis.cpp"

TEST_CASE("Jarvis parse voice", "[voice]" ) {
  REQUIRE(Jarvis::Jarvis::toArduino() == "зажигай");
}
