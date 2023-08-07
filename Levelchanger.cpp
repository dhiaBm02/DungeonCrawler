//
// Created by dhiab on 04/01/2023.
//

#include "Levelchanger.h"

Levelchanger::Levelchanger(int row, int col) : Tile("!", nullptr, row, col), Active()
{

}

Tile *Levelchanger::onEnter(Tile *fromTile, Character *who) {
    active();
    return destination;
}

void Levelchanger::setDestination(Tile *destination) {
    Levelchanger::destination = destination;
}
