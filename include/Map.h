#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Point.h"

// 定义地图元素
#define WALL '#'
#define PATH ' '
#define PLAYER 'P'
#define TRAP 'T'
#define EXIT 'E'

class Map {
private:
    std::vector<std::vector<char>> grid;
    int rows, cols;
    Point exitPos;

public:
    Map(int r, int c);
    
    bool isWalkable(int x, int y) const;
    bool isTrap(int x, int y) const;
    bool isExit(int x, int y) const;
    
    void removeTrap(int x, int y);
    void display(const Point& playerPos) const;
};

#endif // MAP_H
