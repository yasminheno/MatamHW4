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
        Players/Player.cpp
        Players/Character.h
        Players/Character.cpp
        Players/Warrior.h
        Players/Archer.h
        Players/Magician.h
        Players/Magician.cpp
        Players/Warrior.cpp
        Players/Archer.cpp
        Events/Event.cpp
        Players/Job.h
        Events/Monster.cpp)
