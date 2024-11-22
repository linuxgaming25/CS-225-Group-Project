#include "AdventureGame.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <memory> // For std::unique_ptr and make_unique

// Define make_unique for C++11 compatibility
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

using namespace std;

// Constructor initializes game state and room walls
AdventureGame::AdventureGame() 
    : wall1(make_unique<DeskWall>()),     // Wall 1 is a DeskWall
      wall2(make_unique<BookcaseWall>()), // Wall 2 is a BookcaseWall
      wall3(make_unique<DoorWall>("A set of sturdy doors.", "key")), // Wall 3 is a DoorWall
      wall4(make_unique<WindowWall>()),  // Wall 4 is a WindowWall
      gameOver(false), 
      currentWall(0) {                   // Start at the first wall
    startTime = chrono::system_clock::now(); // Record the game's start time
}

// Main game loop
void AdventureGame::start() {
    string action;
    bool ready = false;

    // Prompt the player to start the game
    do {
        cout << "Are you ready to begin the adventure? (yes/no): ";
        cin >> action;
        if (action == "yes") {
            ready = true;
        } else if (action == "no") {
            cout << "Take your time to prepare.\n";
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'.\n";
        }
    } while (!ready);
    
    cout << "You start by facing the Desk with Key.\n";
    wall1->showAsciiArt();  // Display the ASCII art for Wall 1

    // Game loop runs until gameOver is true
    while (!gameOver) {
        displayRoom();  // Display room status and options
        try {
            cin >> action;
            cin.ignore();
            if (action == "l" || action == "r" || action == "w" || action == "i" || action == "e") {
                // Valid actions
            } else {
                throw invalid_argument("Invalid action. Choose from the available options.");
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl; // Handle invalid input
        }

        // Handle user actions
        if (action == "l") {
            currentWall = (currentWall > 1) ? currentWall - 1 : 4; // Rotate left
            showCurrentWall();
        } else if (action == "r") {
            currentWall = (currentWall < 4) ? currentWall + 1 : 1; // Rotate right
            showCurrentWall();
        } else if (action == "w") {
            showCurrentWall();  // Show current wall
            if (currentWall == 1) {
                wall1->inspect();  // Inspect DeskWall
                if (!wall1->item.empty()) {
                    inventory.addItem(wall1->item); // Add item to inventory
                }
            } else if (currentWall == 2) {
                wall2->inspect(); // Inspect BookcaseWall
                if (!wall2->item.empty()) {
                    inventory.addItem(wall2->item);
                }
            } else if (currentWall == 3) {
                wall3->inspect(); // Inspect DoorWall
            } else if (currentWall == 4) {
                wall4->inspect(); // Inspect WindowWall
            }
        } else if (action == "i") {
            inventory.display(); // Display inventory
        } else if (action == "e") {
            if (currentWall == 3) { // DoorWall interactions
                cout << "You are facing two doors. Choose:\n";
                cout << "a) Open the Lobby Door\nb) Open the Stairwell Door\n";
                string doorChoice;
                cin >> doorChoice;

                if (doorChoice == "a") {
                    if (inventory.hasItem("key to lobby")) {
                        openLobby();
                    } else {
                        cout << "The Lobby door is locked.\n";
                    }
                } else if (doorChoice == "b") {
                    if (inventory.hasItem("key to stairwell")) {
                        openStairwell();
                    } else {
                        cout << "The Stairwell door is locked.\n";
                    }
                }
            }
        }

        // Check if time has run out
        if (getTimeRemaining() <= 0) {
            gameOver = true;
            cout << "Time's up! You didn't leave in time.\n";
        }
    }
}

// Displays the current room status and actions
void AdventureGame::displayRoom() {
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << "TURN LEFT 'l' | TURN RIGHT 'r' | INSPECT OBJECT 'w' | OPEN INVENTORY 'i' | OPEN DOOR 'e'\n";
    cout << "TIME IS " << getTimeRemaining() << " MINUTES | YOU HAVE 3 MINUTES TO LEAVE THE OFFICE\n";
    cout << "--------------------------------------------------------------------------------------------------\n";
}

// Show the current wall's ASCII art
void AdventureGame::showCurrentWall() {
    switch (currentWall) {
        case 1: wall1->showAsciiArt(); break;
        case 2: wall2->showAsciiArt(); break;
        case 3: wall3->showAsciiArt(); break;
        case 4: wall4->showAsciiArt(); break;
    }
}

// Handles Lobby Door interactions
void AdventureGame::openLobby() {
    cout << "You enter the lobby and meet the security guard!\n";
    cout << "What will you say?\n";
    cout << "a) 'I work here!'\nb) 'I'm lost.'\nc) 'I was just visiting.'\n";

    string choice;
    cin >> choice;

    if (choice == "a") {
        cout << "The security guard escorts you out.\n";
    } else if (choice == "b") {
        cout << "He calls the police and they arrest you.\n";
    } else if (choice == "c") {
        cout << "You successfully leave the building.\n";
    } else {
        cout << "Invalid choice.\n";
    }
    gameOver = true;
}

// Handles Stairwell Door interactions
void AdventureGame::openStairwell() {
    cout << "You open the stairwell door.\n";
    cout << "Do you go up or down?\n";
    cout << "a) Go up\nb) Go down\n";
    
    string stairChoice;
    cin >> stairChoice;

    if (stairChoice == "a") {
        cout << "You bump into your boss and they fire you.\n";
    } else if (stairChoice == "b") {
        cout << "You reach the parking garage and get in your car to drive away.\n";
    } else {
        cout << "Invalid choice.\n";
    }
    gameOver = true;
}

// Calculate remaining time (3 minutes total)
int AdventureGame::getTimeRemaining() {
    chrono::duration<int> duration = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - startTime);
    int timeElapsed = duration.count();
    return (3 - (timeElapsed / 60)) >= 0 ? 3 - (timeElapsed / 60) : 0;
}

// Save inventory to file
void AdventureGame::saveGame() {
    inventory.saveToFile("inventory.txt");
}

// Load inventory from file
void AdventureGame::loadGame() {
    inventory.loadFromFile("inventory.txt");
}
