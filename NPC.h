#ifndef PG2_DUNGEONCRAWLER_NPC_H
#define PG2_DUNGEONCRAWLER_NPC_H


#include "Character.h"
#include "GuardController.h"

class NPC : public Character {
public:
    explicit NPC(std::string texture, std::string movementPath, int strength, int stamina);
    bool isNPC() override {return true;}
private:
    GuardController* controller;
public:
    GuardController *getController() const;
};


#endif //PG2_DUNGEONCRAWLER_NPC_H
