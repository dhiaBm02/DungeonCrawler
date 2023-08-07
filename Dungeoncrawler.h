#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#include "Tile.h"
#include "Level.h"
#include "Character.h"
#include "NPC.h"
#include "AbstractUI.h"
#include "Passive.h"
#include "List.h"



class DungeonCrawler : public Passive
{
public:
    explicit DungeonCrawler(std::vector<std::string> sMaps);
    //void turn(int movingDir);
    void turn(int movingDir, Character* who);
    void turnNPC(int movingDir, NPC* who);
    void start();
    void notify(Active*) override;
    bool isGameLooted();
protected:
    AbstractUI* ui;
    List<Level*> lvls;
    std::vector<std::string> sMaps;
    List<Level*>::iterator it;
    Level* currentLvl;
    Character* player = new Character("C", 100, 200);
    bool isLooted = false;
    bool isEnd = false;
public:
    Character *getPlayer() const;
    Level *getCurrentLvl() const;
};

#endif // DUNGEONCRAWLER_H
