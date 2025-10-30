#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/students.hpp"

TEST_CASE( "a student can have full name called" ) {
    student Mickey("Mickey Jones", "B000607");
    REQUIRE ( Mickey.getFirstName() == "Mickey Jones" );
}
TEST_CASE( "a student can have first name called" ) {
    student Mickey("Mickey Jones", "B000607");
    REQUIRE ( Mickey.getFirstName() == "Mickey" );
}
TEST_CASE( "a student can have ID called" ) {
    student Mickey("Mickey Jones", "B000607");
    REQUIRE ( Mickey.getFirstName() == "B000607" );
}

