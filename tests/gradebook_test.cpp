#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/gradebook.hpp"

TEST_CASE( "you can grade a students assignment and check it" ) {
    gradebook my_gb;
    my_gb.add_new_student("Sara J Smith", "D300612");
    my_gb.add_assignment("Worksheet 1a", 20);
}