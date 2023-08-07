//
// Created by dhiab on 30/11/2022.
//

#ifndef PG2_DUNGEONCRAWLER_GUARDCONTROLLER_H
#define PG2_DUNGEONCRAWLER_GUARDCONTROLLER_H

#include <string>
#include "AbstractController.h"

class GuardController : public AbstractController {
public:
    explicit GuardController(std::string movementPath);
    int move() override;
private:
    std::string movementPath;
    int index;
};


#endif //PG2_DUNGEONCRAWLER_GUARDCONTROLLER_H
