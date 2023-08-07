#include "Character.h"
#include "Tile.h"

Character::Character(std::string texture, int strength, int stamina) : texture(texture), strength(strength), stamina(stamina), MaxHP(getMaxHP()), HP(getMaxHP()){

}

const std::string &Character::getTexture() const {
    return texture;
}

void Character::setTile(Tile* tile) {
    this->tile = tile;
}

Tile *Character::getTile() const {
    return tile;
}

int Character::getMaxHP() {
    return stamina * 5 + 20;
}

int Character::getHp() const {
    return HP;
}

int Character::getStrength() const {
    return strength;
}

/*
void Character::fight(Character *defender) {
        attack(defender);
    if (!defender->isDead())
        defender->defend(this);
}
*/

void Character::attack(Character *defender) {
    defender->HP -= strength;
}

void Character::defend(Character *attacker) {
    attacker->HP -= strength;
}

bool Character::isDead() {
    return HP <= 0;
}
