#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <unistd.h>

Game::Game() : player(1, 1, 10) {
    // 创建两张地图
    maps.push_back(Map(15, 30));
    maps.push_back(Map(20, 25));
    currentMapIndex = 0;
}

void Game::showMenu() {
    std::cout << "===== 迷宫游戏菜单 =====" << std::endl;
    std::cout << "1. 选择地图 1" << std::endl;
    std::cout << "2. 选择地图 2" << std::endl;
    std::cout << "请选择: ";
    
    int choice;
    std::cin >> choice;
    
    if (choice >= 1 && choice <= static_cast<int>(maps.size())) {
        currentMapIndex = choice - 1;
        player = Player(1, 1, 10); // 重置玩家位置和生命值
    } else {
        std::cout << "选择无效，使用默认地图 1" << std::endl;
        currentMapIndex = 0;
        player = Player(1, 1, 10);
    }
    
    clearScreen();
    std::cout << "按任意键开始游戏..." << std::endl;
    getch();
}

void Game::play() {
    showMenu();
    
    while (true) {
        Map& currentMap = maps[currentMapIndex];
        currentMap.display(player.getPos());
        
        std::cout << "生命值: " << player.getHp() << std::endl;
        std::cout << "使用 wasd 移动，q 退出" << std::endl;

        char input = getch();
        int dx = 0, dy = 0;
        bool quit = false;

        switch (input) {
            case 'w': dx = -1; break;
            case 's': dx = 1; break;
            case 'a': dy = -1; break;
            case 'd': dy = 1; break;
            case 'q': quit = true; break;
            default: break;
        }

        if (quit) break;

        Point newPos = player.getPos();
        newPos.x += dx;
        newPos.y += dy;

        if (currentMap.isWalkable(newPos.x, newPos.y)) {
            if (currentMap.isTrap(newPos.x, newPos.y)) {
                player.takeDamage(2);
                currentMap.removeTrap(newPos.x, newPos.y);
                
                if (player.isDead()) {
                    currentMap.display(player.getPos());
                    std::cout << "你死了！按任意键退出..." << std::endl;
                    getch();
                    break;
                }
            }
            
            player.move(dx, dy);
            
            if (currentMap.isExit(newPos.x, newPos.y)) {
                currentMap.display(player.getPos());
                std::cout << "恭喜你，成功逃出迷宫！" << std::endl;
                std::cout << "按任意键退出..." << std::endl;
                getch();
                break;
            }
        }
        
        usleep(100000); // 延迟100毫秒
    }
}
