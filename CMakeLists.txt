cmake_minimum_required(VERSION 3.23)
project(PG2_DungeonCrawler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PG2_DungeonCrawler
        AbstractUI.cpp
        AbstractUI.h
        Character.cpp
        Character.h
        Dungeoncrawler.cpp
        Dungeoncrawler.h
        Floor.cpp
        Floor.h
        Level.cpp
        Level.h
        main.cpp
        Portal.cpp
        Portal.h
        Tile.cpp
        Tile.h
        Wall.cpp
        Wall.h TerminalUI.cpp TerminalUI.h Passive.cpp Passive.h Active.cpp Active.h Door.cpp Door.h Switch.cpp Switch.h Pit.cpp Pit.h Ramp.cpp Ramp.h NPC.cpp NPC.h AbstractController.cpp AbstractController.h GuardController.cpp GuardController.h Levelchanger.cpp Levelchanger.h List.cpp List.h Lootchest.cpp Lootchest.h Graph.cpp Graph.h)
