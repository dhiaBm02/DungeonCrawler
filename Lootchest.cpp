//
// Created by dhiab on 11/01/2023.
//

#include "Lootchest.h"

Lootchest::Lootchest(int row, int col) : Tile("=", nullptr, row, col) {

}

Tile *Lootchest::onEnter(Tile *fromTile, Character *who) {
    return this;
}
