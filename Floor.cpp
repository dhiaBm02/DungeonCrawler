#include "Floor.h"
#include "Character.h"


Floor::Floor(const int row, const int column)
        : Tile(".", nullptr, row, column)
{

}

Tile *Floor::onEnter(Tile *fromTile, Character *who)
{
    return this;
}
/*
bool Floor::moveTo(Tile *destTile, Character *who)
{
    Tile* fromTile = onLeave(destTile,who);

    if(fromTile == nullptr)
        return false;

    Tile* realDest = destTile->onEnter(fromTile,who);
    if(realDest == nullptr) {
        return false;
    }

    fromTile->setCharacter(nullptr);
    realDest->setCharacter(who);
    who->setTile(realDest);

    return true;
}
*/
