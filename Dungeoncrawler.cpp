#include "Dungeoncrawler.h"
#include "TerminalUI.h"
#include "Character.h"

DungeonCrawler::DungeonCrawler(std::vector<std::string> sMaps) : sMaps(sMaps)
{
    for (std::string s : sMaps) {
        lvls.push_back(new Level(s));
    }
    it = lvls.begin();
    currentLvl = *it;
    currentLvl->getLvlChanger()->attach(this);
    currentLvl->placeCharacter(player, 8, 7);
    ui = new TerminalUI(this);
}

void DungeonCrawler::turn(int movingDir, Character *who) {
    Tile* fromTile = who->getTile();
    int tRow = fromTile->getRow();
    int tCol = fromTile->getCol();

    switch (movingDir) {
        case 8:
            tCol--;
            break;
        case 2:
            tCol++;
            break;
        case 6:
            tRow++;
            break;
        case 4:
            tRow--;
            break;
        case 9:
            tRow++;
            tCol--;
            break;
        case 7:
            tRow--;
            tCol--;
            break;
        case 3:
            tRow++;
            tCol++;
            break;
        case 1:
            tRow--;
            tCol++;
            break;
        default:
            break;
    }
    Tile* destTile = currentLvl->getTile(tRow, tCol);
    if (destTile->getTexture() == "=") {
        isLooted = true;
        std::cout << "is looted ****************" << std::endl;
    }
    fromTile->moveTo(destTile, who);


    if (destTile->getTexture() != "!" and destTile->getTexture() != "=") {
        NPC* npc1 = currentLvl->getNPC("N");
        if (!npc1->isDead()) {
            int npc1dir = npc1->getController()->move();
            if (npc1dir != 0 and npc1dir != 5) {
                turnNPC(npc1dir, npc1);
            }
        }

        NPC* npc2 = currentLvl->getNPC("M");
        if (!npc2->isDead()) {
            int npc2dir = npc2->getController()->move();
            if (npc2dir != 0 and npc2dir != 5) {
                turnNPC(npc2dir, npc2);
            }
        }
    }

    // it's better to create another attribute isAllPlayersDead to deal with the display output.
    // there is two cases how a game can end.
    // that should be happened when a creat a list of players in the game.
    if (who->isDead())
        isEnd = true;

    if (isEnd or isLooted)
        ui->OnEnd();
    else ui->OnTurn();
}

Character *DungeonCrawler::getPlayer() const {
    return player;
}

Level *DungeonCrawler::getCurrentLvl() const {
    return currentLvl;
}

void DungeonCrawler::turnNPC(int movingDir, NPC *who) {
    Tile* fromTile = who->getTile();
    int tRow = fromTile->getRow();
    int tCol = fromTile->getCol();

    switch (movingDir) {
        case 8:
            tCol--;
            break;
        case 2:
            tCol++;
            break;
        case 6:
            tRow++;
            break;
        case 4:
            tRow--;
            break;
        case 9:
            tRow++;
            tCol--;
            break;
        case 7:
            tRow--;
            tCol--;
            break;
        case 3:
            tRow++;
            tCol++;
            break;
        case 1:
            tRow--;
            tCol++;
            break;
        default:
            break;
    }
    Tile* destTile = currentLvl->getTile(tRow, tCol);
    fromTile->moveTo(destTile, who);
}

void DungeonCrawler::start() {
    ui->OnTurn();
}

void DungeonCrawler::notify(Active *) {
    Levelchanger* currentLvlChanger = currentLvl->getLvlChanger();
    ++it;
    if (it == lvls.end()) {
        currentLvlChanger->setDestination(currentLvlChanger);
        isEnd = true;
        return;
    }
    currentLvl = *it;
    currentLvlChanger->setDestination(currentLvl->getStartTile());
    currentLvl->getLvlChanger()->attach(this);
}

bool DungeonCrawler::isGameLooted() {
    return isLooted;
}


