# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BShell)

# Set the C++ standard to C++17 (or adjust if needed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Specify directories for source and header files
set(SOURCES 
    src/main.cpp
    src/Shell.cpp
)

include_directories(include)

# Specify the executable target and add all source files
add_executable(bshell ${SOURCES})

# Optionally, specify compiler options (e.g., enable warnings)
target_compile_options(bshell PRIVATE -Wall -Wextra -Werror)
