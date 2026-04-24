# Mindestversion von CMake
cmake_minimum_required(VERSION 3.10)

# Projektname und Sprache
project(SearchEngine LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Alle Quellcodes
set(SOURCES
    main.cpp
    webResource.cpp
    )

# Executable erstellen
add_executable(SearchEngine ${SOURCES})