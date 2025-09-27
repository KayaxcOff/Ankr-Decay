cmake_minimum_required(VERSION 4.0)
project(Ankr_Decay)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ankr_Decay main.cpp
        characters.hpp
        players/characters_heros.hpp
        players/heros.hpp
        players/heros.cpp
        villains/characters_enemies.hpp
        villains/enemies.hpp
        villains/enemies.cpp
        game_board/light_kingdom.hpp
)
