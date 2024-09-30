# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CustomShell)

# Set the C++ standard to C++17 (or adjust if needed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable target and add all source files
add_executable(shell
    main.cpp
    Shell.cpp
)

# Include directories for headers
target_include_directories(shell PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  # This includes the current directory with header files
)

# Optionally, specify compiler options (e.g., enable warnings)
target_compile_options(shell PRIVATE -Wall -Wextra -Werror)
