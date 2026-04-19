# Mindestversion von CMake
cmake_minimum_required(VERSION 3.10)

# Projektname und Sprache
project(MeinProjekt LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Alle Quellcodes
set(SOURCES
    main.cpp
    Functions.cpp
)

# Executable erstellen
add_executable(my_program ${SOURCES})