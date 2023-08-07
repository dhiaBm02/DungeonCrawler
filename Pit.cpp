#include "Pit.h"

Pit::Pit(int row, int col) : Tile("_", nullptr, row, col)
{

}

Tile *Pit::onEnter(Tile *fromTile, Character *who) {
    return this;
}

Tile *Pit::onLeave(Tile *destTile, Character *who) {
    if(destTile->getTexture() == "_" or destTile->getTexture() == "<") {//typeid
        return this;
    }
    else return nullptr;
}

