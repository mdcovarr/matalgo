cmake_minimum_required(VERSION 3.10)

# Set project name
project(MatrixAlgo)

# Set project version
project(MatrixAlgo VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(config/MatrixAlgoConfig.h.in MatrixAlgoConfig.h)

add_executable(MatrixAlgo MatrixAlgo.cpp)

add_subdirectory(utils)

target_link_libraries(MatrixAlgo PUBLIC Matrix)

target_include_directories(MatrixAlgo PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/utils")

