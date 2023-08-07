//
// Created by dhiab on 30/11/2022.
//

#include "Ramp.h"

Ramp::Ramp(int row, int col) : Tile("<", nullptr, row, col)
{

}

Tile *Ramp::onEnter(Tile *fromTile, Character *who) {
    return this;
}
