#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>

class Tile;

class Character
{
public:
    explicit Character(std::string texture, int strength, int stamina);
    const std::string &getTexture() const;
    void setTile(Tile *tile);
    //void fight(Character* defender);
    void attack(Character* defender);
    void defend(Character* attacker);
    bool isDead();
    virtual bool isNPC() { return false;}
private:
    std::string texture;
    Tile* tile = nullptr;
    int strength;
    int stamina;
    int HP;
    const int MaxHP;
public:
    Tile *getTile() const;
    int getMaxHP();
    int getHp() const;
    int getStrength() const;
};

#endif // CHARACTER_H
