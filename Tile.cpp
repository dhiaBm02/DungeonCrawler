#include "Tile.h"
#include "Character.h"

Tile::Tile(std::string texture, Character *character, const int row, const int column)
        : texture(texture), character(character), row(row), col(column)
{

}

std::string Tile::getTexture() const
{
    if (character == nullptr)
        return texture;
    else return character->getTexture();
}

bool Tile::hasCharacter()
{
    if (character == nullptr)
        return false;
    else return true;
}

void Tile::setCharacter(Character *newCharacter)
{
    character = newCharacter;
}

Tile::~Tile() {
}

const int Tile::getRow() const {
    return row;
}

const int Tile::getCol() const {
    return col;
}

Character *Tile::getCharacter() const {
    return character;
}

bool Tile::moveTo(Tile *destTile, Character *who) {
    {
        Tile* fromTile = onLeave(destTile,who);

        if(fromTile == nullptr)
            return false;

        Tile* realDest = destTile->onEnter(fromTile,who);
        if(realDest == nullptr) {
            return false;
        }


        if (realDest->hasCharacter()) {
            Character* defender = realDest->getCharacter();
            if (who->isNPC() == defender->isNPC())
                return false;
            if (onFight(who, defender)) {
                //move
                fromTile->setCharacter(nullptr);
                realDest->setCharacter(who);
                who->setTile(realDest);
            }
        }
        else {
            //move
            fromTile->setCharacter(nullptr);
            realDest->setCharacter(who);
            who->setTile(realDest);
        }
        return true;
    }
}

bool Tile::onFight(Character *attacker, Character *defender) {
    attacker->attack(defender);
    if (defender->isDead()) {
        defender->getTile()->setCharacter(nullptr);
        defender->setTile(nullptr);
        return true;
    }
    defender->attack(attacker);
    if (attacker->isDead()) {
        attacker->getTile()->setCharacter(nullptr);
        attacker->setTile(nullptr);
    }
    return false;
}

