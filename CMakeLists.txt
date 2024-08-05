cmake_minimum_required(VERSION 3.27)
project(MatamHW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Events)
include_directories(Players)

add_executable(MatamHW4
        Events/Event.h
        Players/Player.h
        main.cpp
        MatamStory.cpp
        MatamStory.h
        Utilities.cpp
        Utilities.h
        Monsters/Monster.h
        Players/Player.cpp
        Monsters/Monster.cpp
        Monsters/Monster.cpp
        Players/Charachter.h
        Players/Charachter.cpp
        Players/Warrior.h
        Players/Archer.h
        Players/Magician.h
        Players/Magician.cpp
        Players/Warrior.cpp
        Players/Archer.cpp)
