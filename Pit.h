#ifndef PG2_DUNGEONCRAWLER_PIT_H
#define PG2_DUNGEONCRAWLER_PIT_H


#include "Tile.h"

class Pit : public Tile {
public:
    explicit Pit(int row, int col);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
private:
};


#endif //PG2_DUNGEONCRAWLER_PIT_H
