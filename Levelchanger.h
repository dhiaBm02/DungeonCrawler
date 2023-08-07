#ifndef PG2_DUNGEONCRAWLER_LEVELCHANGER_H
#define PG2_DUNGEONCRAWLER_LEVELCHANGER_H


#include "Tile.h"
#include "Active.h"

class Levelchanger : public Tile, public Active {
public:
    Levelchanger(int row, int col);
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:
    Tile* destination;
public:
    void setDestination(Tile *destination);
};


#endif //PG2_DUNGEONCRAWLER_LEVELCHANGER_H
