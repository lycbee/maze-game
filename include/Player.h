#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player {
private:
    Point pos;
    int hp;

public:
    Player(int x, int y, int initialHp);
    
    const Point& getPos() const;
    int getHp() const;
    
    void move(int dx, int dy);
    void takeDamage(int damage);
    bool isDead() const;
};

#endif // PLAYER_H
