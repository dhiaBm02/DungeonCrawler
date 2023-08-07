#ifndef PG2_DUNGEONCRAWLER_TERMINALUI_H
#define PG2_DUNGEONCRAWLER_TERMINALUI_H

#include "AbstractUI.h"
#include "Dungeoncrawler.h"
#include "Level.h"

class TerminalUI : public AbstractUI{
public:
    TerminalUI(DungeonCrawler* game);
    void draw(Level* lvl) override;
    int getInput();
    void checkInput();
    void OnTurn() override;
    void OnEnd() override;
private:
    int _input;
};


#endif //PG2_DUNGEONCRAWLER_TERMINALUI_H