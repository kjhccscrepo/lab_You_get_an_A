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
TEST_CASE( "An assignment score can be put back to 0." ) {
    Lab_1.setScore(0);
    REQUIRE(Lab_1.score() == 0);
    REQUIRE(Lab_1.score_raw() == 0);
}
TEST_CASE( "An assignment score can be put over 100% for extra credit" ) {
    Lab_1.setScore(42);
    REQUIRE(Lab_1.score() == 105); //105%
    REQUIRE(Lab_1.score_raw() == 42);
}
TEST_CASE( "decimal values work" ) {
    assignment big_final ("Final Essay", 300);
    REQUIRE(big_final.score() == 0);
    REQUIRE(big_final.score_raw() == 0);
    big_final.setScore(293);
    constexpr float expected_score = 97.666664124; // this is a result of c++ implicit conversion math rip.
    REQUIRE(big_final.score() == expected_score);
    REQUIRE(big_final.score_raw() == 293);
}