#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H



#include "Level.h"
class DungeonCrawler;

class AbstractUI
{
public:
    AbstractUI(DungeonCrawler* game);
    virtual void OnTurn() = 0;
    virtual void draw(Level* lvl) = 0;
    virtual void OnEnd() = 0;
protected:
    DungeonCrawler* game;
};

#endif // ABSTRACTUI_H
