#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Map.h"
#include "Player.h"

class Game {
private:
    std::vector<Map> maps;
    int currentMapIndex;
    Player player;

public:
    Game();
    
    void showMenu();
    void play();
};

#endif // GAME_H
