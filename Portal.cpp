#include "Portal.h"
#include "Character.h"

Portal::Portal(const int row, const int column, Tile *destination)
        : Tile("O", nullptr, row, column), destination(destination)
{

}

Tile *Portal::onEnter(Tile *fromTile, Character *who)
{
    return destination;
}