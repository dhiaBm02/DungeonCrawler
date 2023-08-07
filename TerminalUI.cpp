#include "TerminalUI.h"

TerminalUI::TerminalUI(DungeonCrawler* game) : AbstractUI(game)
{
    std::cout << "Game Display ON" << std::endl;
}

void TerminalUI::draw(Level *level) {
    //std::cout << "draw in TerminalUI..." << std::endl;

    for (int y = 0; y < Level::getMaxCol(); y++) {
        for (int x = 0; x < Level::getMaxRow(); x++) {
            std::cout << level->getTile(x, y)->getTexture() << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "CharacterHP : (" << game->getPlayer()->getHp() << "/" << game->getPlayer()->getMaxHP() << ")." << std::endl;
    for (NPC* npc : game->getCurrentLvl()->getNpCs()) {
        if (!npc->isDead())
        std::cout << "NpcHP " << npc->getTexture() << " : (" << npc->getHp() << "/" << npc->getMaxHP() << ")." << std::endl;
    }
}

int TerminalUI::getInput() {
    std::cout << "7  8  9\n"
                 "4  5  6\n"
                 "1  2  3\n"
                 "0  ---> ";
    std::cin >> _input;
    return _input;
}

void TerminalUI::checkInput() {
    getInput();
    if (_input != 0) {
        game->turn(_input, game->getPlayer());
    }
    //if (_input == 0)
      //  std::cout << "Game ended" << std::endl;
}

void TerminalUI::OnTurn() {
    draw(game->getCurrentLvl());
    checkInput();
}

void TerminalUI::OnEnd() {
    draw(game->getCurrentLvl());
    if (game->getPlayer()->isDead())
        std::cout << "Ooops !! ALL PLAYERS ARE DEAD !!\nZOMBIES WON THE GAME." << std::endl;
    else if (game->isGameLooted())
        std::cout << "You have find the Loot ! Great JOB !\nPLAYERS WON THE GAME." << std::endl;
    else std::cout << "You have finished ALL lvls ! BRAVOOO !" << std::endl;
}



