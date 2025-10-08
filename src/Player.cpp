#include "Player.h"

Player::Player(int x, int y, int initialHp) : pos(x, y), hp(initialHp) {}

const Point& Player::getPos() const {
    return pos;
}

int Player::getHp() const {
    return hp;
}

void Player::move(int dx, int dy) {
    pos.x += dx;
    pos.y += dy;
}

void Player::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

bool Player::isDead() const {
    return hp <= 0;
}
