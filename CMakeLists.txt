cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(optionplot)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(
	${PROJECT_NAME} 
	# src/main.cpp
	${SRC_FILES}
)

# Matplot++

set(MATPLOTPP_BUILD_EXAMPLES OFF CACHE BOOL "Build examples")
set(MATPLOTPP_BUILD_TESTS OFF CACHE BOOL "Build tests")
add_subdirectory(external/matplotplusplus)

# JSON
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(external/json)

target_link_libraries(
	${PROJECT_NAME} 
	matplot
	nlohmann_json::nlohmann_json
	curl
)

# Testing
enable_testing()

list(FILTER SRC_FILES EXCLUDE REGEX ".*main\\.cpp$")
# message("${SRC_FILES}")
file(GLOB_RECURSE TEST_FILES test/*.cpp)
add_executable(
	optionplot_test
	${TEST_FILES}
	${SRC_FILES}
)
target_include_directories(optionplot_test
  PUBLIC
    src/
  )

target_link_libraries(
	optionplot_test
	matplot
	nlohmann_json::nlohmann_json
	GTest::gtest_main
	curl
)

include(GoogleTest)
gtest_discover_tests(optionplot_test)