cmake_minimum_required(VERSION 3.16)

project(LogisticRegression)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

add_executable(logistic_regression 
    src/main.cpp
    src/logistic_regression.cpp
    src/data_loader.cpp
    )

target_include_directories(logistic_regression PRIVATE include)

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