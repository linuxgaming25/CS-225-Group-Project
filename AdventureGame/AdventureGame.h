#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H

#include "WindowWall.h" // Include class for a wall with a window
#include "DeskWall.h"   // Include class for a wall with a desk
#include "DoorWall.h"   // Include class for a wall with a door
#include "BookcaseWall.h" // Include class for a wall with a bookcase
#include <iostream>     // For input and output
#include <chrono>       // For time tracking
#include "Inventory.h"  // Include class for managing the player's inventory
#include "Wall.h"       // Base class for different types of walls
#include <memory>       // For using smart pointers

using namespace std; // Simplify usage of standard namespace

class AdventureGame {
public:
    // Smart pointers to walls, each storing different types of wall objects
    unique_ptr<Wall> wall1, wall2, wall3, wall4;
    bool gameOver; // Flag to indicate if the game is over
    chrono::time_point<chrono::system_clock> startTime; // Tracks the game's start time
    int currentWall; // Keeps track of which wall the player is interacting with
    Inventory inventory; // Holds items the player has collected

    AdventureGame(); // Initializes game state
    void start(); // Starts the game loop
    void displayRoom(); // Displays details about the room
    void showCurrentWall(); // Shows details of the current wall
    void openLobby(); // Handles actions for opening the lobby
    void openStairwell(); // Handles actions for opening the stairwell
    int getTimeRemaining(); // Calculates and returns remaining time
    void saveGame(); // Saves the current game state to a file
    void loadGame(); // Loads game state from a file
};

#endif
