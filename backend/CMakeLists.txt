cmake_minimum_required(VERSION 3.10)
project(cncsharp_backend LANGUAGES CXX)

# Use C++17 for modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the backend library
add_library(cncsharp_backend
    src/generator.cpp
    src/marlin_commands.cpp
    src/communication.cpp
)

# Ensure the compiler uses at least C++17
target_compile_features(cncsharp_backend PUBLIC cxx_std_17)

# Expose the include directory to consumers of this library
# This makes headers in `include/` available to downstream targets
# via `target_link_libraries` or `find_package` usage.
target_include_directories(cncsharp_backend PUBLIC include)
