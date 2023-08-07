//
// Created by dhiab on 30/11/2022.
//

#ifndef PG2_DUNGEONCRAWLER_RAMP_H
#define PG2_DUNGEONCRAWLER_RAMP_H


#include "Tile.h"

class Ramp : public Tile {
public:
    explicit Ramp(int row, int col);
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:
};


#endif //PG2_DUNGEONCRAWLER_RAMP_H
