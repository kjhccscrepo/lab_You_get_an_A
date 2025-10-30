#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/assignments.hpp"
assignment Lab_1("Lab - week 1", 40);
TEST_CASE( "An assignment initializes and has a name" ) {
    REQUIRE(Lab_1.getName() == "Lab - week 1");
}
TEST_CASE( "An assignment initializes and has a max score" ) {
    REQUIRE(Lab_1.value() == 40);
}
TEST_CASE( "An assignment initializes and has a no scored points" ) {
    REQUIRE(Lab_1.score() == 0);
    REQUIRE(Lab_1.score_raw() == 0);
}
TEST_CASE( "An assignment score can be updated and grabbed." ) {
    Lab_1.setScore(38);
    REQUIRE(Lab_1.score() == 95); //95%
    REQUIRE(Lab_1.score_raw() == 38);
}