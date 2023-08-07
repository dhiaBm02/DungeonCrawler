#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <array>
#include <vector>
#include "Tile.h"
#include "NPC.h"
#include "Levelchanger.h"

class Level
{
public:
    explicit Level(std::string sMap);
    void addPairPortal(int pRow, int pCol, int dRow, int dCol);
    Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
    static int getMaxRow();
    static int getMaxCol();
    NPC *getNPC(const std::string& texture) const;
    void setupSwitch(int sRow, int sCol, int dRow, int dCol);
    virtual ~Level();

private:
    //the size of a level and the list of npcs should be flexible.
    static const int MAX_ROW = 10;
    static const int MAX_COL = 10;
    std::array<std::array<Tile*, MAX_COL>, MAX_ROW> map {};
    //std::vector<Character*> Players;
    std::vector<NPC*> NPCs;
public:
    const std::vector<NPC *> &getNpCs() const;

private:
    const std::string sMap;
    Levelchanger* lvlChanger;
    Tile* startTile;
public:
    Tile *getStartTile() const;

public:
    Levelchanger *getLvlChanger() const;
};

#endif // LEVEL_H
