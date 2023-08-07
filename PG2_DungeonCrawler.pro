TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AbstractUI.cpp \
        Character.cpp \
        Dungeoncrawler.cpp \
        Floor.cpp \
        Level.cpp \
        Portal.cpp \
        Tile.cpp \
        Wall.cpp \
        GraphicalUI.cpp \
        main.cpp \
        Active.cpp \
        Passive.cpp \
        NPC.cpp \
        AbstractController.cpp \
        Door.cpp \
        Pit.cpp \
        Ramp.cpp \
        Switch.cpp \
        GuardController.cpp \
        TerminalUI.cpp \
        mainwindow.cpp


HEADERS += \
    AbstractUI.h \
    Character.h \
    Dungeoncrawler.h \
    Floor.h \
    Level.h \
    Portal.h \
    Tile.h \
    Wall.h \
    Active.h \
    Passive.h \
    NPC.h \
    AbstractController.h \
    Door.h \
    Pit.h \
    Ramp.h \
    Switch.h \
    GuardController.h \
    TerminalUI.h \
    GraphicalUI.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
