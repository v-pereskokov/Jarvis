#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/Jarvis.hpp"

TEST_CASE("Jarvis parse voice", "[voice]" ) {
  REQUIRE(Jarvis::Jarvis::getStringVoice() == "включить");
  REQUIRE(Jarvis::Jarvis::getStringVoice() == "Джарвис");
  REQUIRE(Jarvis::Jarvis::getStringVoice() == "бежать");
  REQUIRE(Jarvis::Jarvis::getStringVoice() == "дубина");
}
