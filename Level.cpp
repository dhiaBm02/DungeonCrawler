#include "Level.h"
#include "Wall.h"
#include "Floor.h"
#include "Portal.h"
#include "Door.h"
#include "Switch.h"
#include "Pit.h"
#include "Ramp.h"
#include "Character.h"
#include "Lootchest.h"

/*
const std :: string sMap = {"##########"
                            "#O.......#"
                            "#...<....#"
                            "#..___...#"
                            "#..___...#"
                            "#........#"
                            "#######X##"
                            "#O.......#"
                            "#...?....#"
                            "##########"};
*/

Level::Level(std::string sMap) : sMap(sMap)
{
    Tile* tempTile;
    int pCnt = 0, pRow, pCol;
    for(int c = 0; c < MAX_COL; c++) {
        for(int r = 0; r < MAX_ROW; r++) {
            switch (sMap.at(10 * c + r)) {
                case '#':
                    tempTile = new Wall(r,c);
                    break;
                case '.':
                    tempTile = new Floor(r,c);
                    break;
                case 'O':
                    pCnt++;
                    if(pCnt == 2) {
                        addPairPortal(pRow, pCol, r,c);
                        pCnt = 0;
                        continue;
                    }
                    else {
                        pRow = r;
                        pCol = c;
                        tempTile = new Floor(r ,c);
                    }
                    break;
                case 'X':
                    tempTile = new Door(r,c);
                    break;
                case '?':
                    tempTile = new Switch(r,c);
                    break;
                case '_':
                    tempTile = new Pit(r,c);
                    break;
                case '<':
                    tempTile = new Ramp(r,c);
                    break;
                case '!':
                    tempTile = new Levelchanger(r, c);
                    lvlChanger = dynamic_cast<Levelchanger*> (tempTile);
                    break;
                case '=':
                    tempTile = new Lootchest(r, c);
                    break;
            }
            map.at(c).at(r) = tempTile;
        }
    }

    NPCs.push_back(new NPC("N", "55555", 100, 200));
    NPCs.push_back(new NPC("M","55555", 100, 200));
    placeCharacter(NPCs.at(0), 5, 2);
    placeCharacter(NPCs.at(1), 2, 5);

    setupSwitch(4, 8, 7, 6);
    startTile = map.at(2).at(2);
}

void Level::addPairPortal(int pRow, int pCol, int dRow, int dCol)
{
    map.at(dCol).at(dRow) = new Portal(dRow, dCol, map.at(pCol).at(pRow));
    delete map.at(pCol).at(pRow);
    map.at(pCol).at(pRow) = nullptr;
    map.at(pCol).at(pRow) = new Portal(pRow, pCol, map.at(dCol).at(dRow));
}

Tile *Level::getTile(int row, int col) const {
    return map.at(col).at(row);
}

void Level::placeCharacter(Character *c, int row, int col) {
    map.at(col).at(row)->setCharacter(c);
    c->setTile(getTile(row, col));
}

int Level::getMaxRow() {
    return MAX_ROW;
}

int Level::getMaxCol() {
    return MAX_COL;
}


NPC *Level::getNPC(const std::string& texture) const {

    for (auto npc : NPCs) {
        if (npc->getTexture() == texture)
            return npc;
    }
    return nullptr;
}


Level::~Level() {
    for(size_t j = 0; j < map.size(); j++) {
        for(size_t i = 0; i < map.at(j).size(); i++) {
            delete map.at(i).at(j);
            map.at(i).at(j) = nullptr;
        }
    }
}

void Level::setupSwitch(int sRow, int sCol, int dRow, int dCol) {
    delete map.at(sCol).at(sRow);
    map.at(sCol).at(sRow) = nullptr;
    delete map.at(dCol).at(dRow);
    map.at(dCol).at(dRow) = nullptr;
    map.at(sCol).at(sRow) = new Switch(sRow, sCol);
    map.at(dCol).at(dRow) = new Door(dRow, dCol);
    Door* _Door = dynamic_cast<Door*> (map.at(dCol).at(dRow));
    Switch* _Switch = dynamic_cast<Switch*> (map.at(sCol).at(sRow));
    _Switch->attach(_Door);
}

Levelchanger *Level::getLvlChanger() const {
    return lvlChanger;
}

Tile *Level::getStartTile() const {
    return startTile;
}

const std::vector<NPC *> &Level::getNpCs() const {
    return NPCs;
}

