#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "Tile.h"

class Floor : public Tile
{
public:
    explicit Floor(int row, int column);
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:

};

#endif // FLOOR_H
