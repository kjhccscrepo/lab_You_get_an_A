cmake_minimum_required(VERSION 3.24)

project(you_get_an_a)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(id_maker_test tests/id_maker_test.cpp
        src/id_maker.cpp
)
add_executable(assignments_test tests/assignments_test.cpp
        src/assignments.cpp
)
add_executable(students_test tests/students_test.cpp
        src/students.cpp
)
add_executable(main main.cpp
        src/students.cpp
        src/assignments.cpp
        src/gradebook.cpp
        src/id_maker.cpp
)
target_link_libraries(assignments_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(students_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(id_maker_test PRIVATE Catch2::Catch2WithMain)
