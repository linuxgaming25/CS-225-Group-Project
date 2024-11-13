#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H

#include <iostream>
#include <chrono>
#include "Inventory.h"
#include "Wall.h"
#include <memory>

using namespace std;

class AdventureGame {
public:
    unique_ptr<Wall> wall1, wall2, wall3, wall4;
    bool gameOver;
    chrono::time_point<chrono::system_clock> startTime;
    int currentWall;
    Inventory inventory;

    AdventureGame();
    void start();
    void displayRoom();
    void showCurrentWall();
    void openLobby();
    void openStairwell();
    int getTimeRemaining();
    void saveGame();
    void loadGame();
};

#endif
