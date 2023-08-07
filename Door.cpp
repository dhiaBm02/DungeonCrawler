//
// Created by dhiab on 29/11/2022.
//

#include "Door.h"

Door::Door(int row, int col) : Tile("X", nullptr, row ,col), Passive()
{
    isOpen = false;
}

Tile *Door::onEnter(Tile *fromTile, Character *who) {
    if (isOpen) {
        return this;
    }
    else {
        return nullptr;
    }
}

void Door::setDoorTexture(bool) {
    if (isOpen) {
        texture = "/";
    }
    else {
        texture = "X";
    }
}

void Door::notify(Active *) {
    isOpen = !isOpen;
    setDoorTexture(isOpen);
}

Tile *Door::onLeave(Tile *destTile, Character *who) {
    if (isOpen) {
        return this;
    }
    else {
        return nullptr;
    }
}

