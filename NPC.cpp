//
// Created by dhiab on 30/11/2022.
//

#include "NPC.h"

NPC::NPC(std::string texture, std::string movementPath, int strength, int stamina) : Character(texture, strength, stamina)
{
    controller = new GuardController(movementPath);
}

GuardController *NPC::getController() const {
    return controller;
}
