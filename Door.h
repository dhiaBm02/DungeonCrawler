#ifndef PG2_DUNGEONCRAWLER_DOOR_H
#define PG2_DUNGEONCRAWLER_DOOR_H


#include "Tile.h"
#include "Passive.h"
#include "Floor.h"
#include "Wall.h"

class Door : public Tile, public Passive {
public:
    explicit Door(int row, int col);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    void notify(Active*) override;
protected:
    bool isOpen;
    void setDoorTexture(bool);
};


#endif //PG2_DUNGEONCRAWLER_DOOR_H
