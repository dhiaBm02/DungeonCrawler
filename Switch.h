#ifndef PG2_DUNGEONCRAWLER_SWITCH_H
#define PG2_DUNGEONCRAWLER_SWITCH_H


#include "Floor.h"
#include "Active.h"

class Switch : public Tile , public Active
{
public:
    explicit Switch(int row, int col);
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:

};

#endif //PG2_DUNGEONCRAWLER_SWITCH_H
