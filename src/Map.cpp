#include "Map.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Map::Map(int r, int c) : rows(r), cols(c) {
    grid.resize(rows, std::vector<char>(cols, PATH));
    
    // 初始化墙壁
    for (int i = 0; i < rows; i++) {
        grid[i][0] = WALL;
        grid[i][cols - 1] = WALL;
    }
    for (int j = 0; j < cols; j++) {
        grid[0][j] = WALL;
        grid[rows - 1][j] = WALL;
    }
    
    // 随机生成一些墙壁
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (rand() % 4 == 0) {
                grid[i][j] = WALL;
            }
        }
    }
    
    // 设置出口
    exitPos = Point(rows - 2, cols - 2);
    grid[exitPos.x][exitPos.y] = EXIT;
    
    // 设置一些陷阱
    int trapCount = 5;
    while (trapCount > 0) {
        int x = rand() % (rows - 2) + 1;
        int y = rand() % (cols - 2) + 1;
        if (grid[x][y] == PATH) {
            grid[x][y] = TRAP;
            trapCount--;
        }
    }
}

bool Map::isWalkable(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols && 
           (grid[x][y] == PATH || grid[x][y] == EXIT || grid[x][y] == TRAP);
}

bool Map::isTrap(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == TRAP;
}

bool Map::isExit(int x, int y) const {
    return x == exitPos.x && y == exitPos.y;
}

void Map::removeTrap(int x, int y) {
    if (isTrap(x, y)) {
        grid[x][y] = PATH;
    }
}

void Map::display(const Point& playerPos) const {
    clearScreen();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == playerPos.x && j == playerPos.y) {
                std::cout << PLAYER;
            } else {
                std::cout << grid[i][j];
            }
        }
        std::cout << std::endl;
    }
}
