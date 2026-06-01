

cmake_minimum_required(VERSION 3.16)

project(LogisticRegression)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

find_package(Catch2 3 REQUIRED)

enable_testing()

add_library(logic_core
    src/logistic_regression.cpp
    src/data_loader.cpp
)

target_include_directories(logic_core PUBLIC include)

add_executable(logistic_regression 
    src/main.cpp
    )

target_link_libraries(logistic_regression PRIVATE logic_core)

add_executable(unit_tests
    tests/test_data_loader.cpp
    tests/test_logistic_regression.cpp)

target_link_libraries(unit_tests PRIVATE logic_core Catch2::Catch2WithMain)

configure_file(
    ${CMAKE_SOURCE_DIR}/data/titanic_clean.csv
    ${CMAKE_BINARY_DIR}/data/titanic_clean.csv
    COPYONLY
)

configure_file(
    ${CMAKE_SOURCE_DIR}/data/blobs.csv
    ${CMAKE_BINARY_DIR}/data/blobs.csv
    COPYONLY
)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)