//
// Created by dhiab on 30/11/2022.
//

#include "GuardController.h"

GuardController::GuardController(std::string movementPath) : movementPath(movementPath)
{
    index = 0;
}

int GuardController::move() {
    return movementPath.at(index++ % movementPath.size()) - '0';
}
