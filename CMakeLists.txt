cmake_minimum_required(VERSION 3.28)
project(sfmlCodingProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(src/headers
        src/classes)

add_executable(main src/main.cpp
        src/classes/Logger.cpp
        src/classes/Options.cpp
        src/classes/Object.cpp
        src/classes/Button.cpp
        src/classes/Level.cpp
        src/classes/GameManager.cpp
        src/classes/Label.cpp
        src/classes/TexturedObject.cpp
        src/classes/AnimatedObject.h
        src/classes/AnimatedObject.cpp
)
target_compile_features(main PRIVATE cxx_std_23)
target_link_libraries(main PRIVATE SFML::Graphics)