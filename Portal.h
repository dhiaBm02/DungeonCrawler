#ifndef PORTAL_H
#define PORTAL_H

#include "Tile.h"

class Portal : public Tile
{
public:
    explicit Portal(int row, int column, Tile* destination);
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:
    Tile* destination;
};

#endif // PORTAL_H
