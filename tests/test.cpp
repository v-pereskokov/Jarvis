#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/Jarvis.hpp"

TEST_CASE("Jarvis parse voice", "[voice]" ) {
  REQUIRE(Jarvis::Jarvis::smartHome("Jarvis") == "Jarvis");
  REQUIRE(Jarvis::Jarvis::smartHome("Jarvis1") != "Jarvis");
}
