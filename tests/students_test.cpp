#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/students.hpp"
student Mickey("Mickey Jones", "B000607");
TEST_CASE( "a student can have full name called" ) {
    REQUIRE ( Mickey.getStudentName() == "Mickey Jones" );
}
TEST_CASE( "a student can have first name called" ) {
    REQUIRE ( Mickey.getFirstName() == "Mickey" );
}
TEST_CASE( "a student can have ID called" ) {
    REQUIRE ( Mickey.getID() == "B000607" );
}
TEST_CASE( "a student can have their named changed" ) {
    Mickey.newName("Rickey \"Mickey\" Jones");
    REQUIRE ( Mickey.getFirstName() == "Rickey" );
}
// for class cross functino checking
assignment worksheet_1_1("Worksheet - Unit 1-1", 10);
TEST_CASE( "a student can have an assignment assigned" ) {
    REQUIRE ( Mickey.is_assigned(worksheet_1_1) == false );
    Mickey.newAssignment(worksheet_1_1);
    REQUIRE ( Mickey.is_assigned(worksheet_1_1) == true );
}
TEST_CASE( "a student can have an assignment graded" ) {
    REQUIRE ( Mickey.getAssignments()[0].score_raw() == 0 );
}
TEST_CASE( "a student can have an assignment graded, then scored" ) {
    Mickey.setGradeForAssignment(worksheet_1_1, 9);
    REQUIRE ( Mickey.getAssignments()[0].score_raw() == 9 );
    REQUIRE ( Mickey.getAssignments()[0].score() == 90 );
}