#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/id_maker.hpp"
ID_maker maker;
TEST_CASE( "ID maker will generate unique ID(s)" ) {
    std::vector<std::string> IDs;
    for (int i = 0; i < 10; i++) {
        IDs.push_back(maker.generateID());
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j != i) {
                REQUIRE( IDs[i] != IDs[j]);
            } else {
                REQUIRE( IDs[i] == IDs[j]);
            }
        }
    }
}