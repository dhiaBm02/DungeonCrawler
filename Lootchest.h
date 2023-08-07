//
// Created by dhiab on 11/01/2023.
//

#ifndef PG2_DUNGEONCRAWLER_LOOTCHEST_H
#define PG2_DUNGEONCRAWLER_LOOTCHEST_H


#include "Tile.h"

class Lootchest : public Tile {
public:
    explicit Lootchest(int row, int col);
    Tile* onEnter(Tile *fromTile, Character *who) override;
private:
};


#endif //PG2_DUNGEONCRAWLER_LOOTCHEST_H
