//
// Created by dhiab on 29/11/2022.
//

#include "Switch.h"

Switch::Switch(int row, int col) : Tile("?", nullptr, row, col), Active()
{

}

Tile *Switch::onEnter(Tile *fromTile, Character *who) {
    active();
    return this;
}
