#include "AdventureGame.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

AdventureGame::AdventureGame()
    : wall1(new Wall("A boss office desk and chair.", "key to lobby", false)),
      wall2(new Wall("A bookshelf on the wall.", "key to stairwell", false)),
      wall3(new Wall("Two doors on the wall.", "", true)),
      wall4(new Wall("A window with a sunset outside.", "", false)),
      gameOver(false), currentWall(1) {
    startTime = chrono::system_clock::now();
}


void AdventureGame::start() {
    string action;
    cout << "You start by facing the Desk with Key (Wall 1).\n";
    wall1->showAsciiArt("wall1");

    while (!gameOver) {
        displayRoom();
        try {
            cin >> action;
            cin.ignore();
            if (action == "l" || action == "r" || action == "w" || action == "i" || action == "e") {
            } else {
                throw invalid_argument("Invalid action. Choose from the available options.");
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }

        if (action == "l") {
            currentWall = (currentWall > 1) ? currentWall - 1 : 4;
            showCurrentWall();
        } else if (action == "r") {
            currentWall = (currentWall < 4) ? currentWall + 1 : 1;
            showCurrentWall();
        } else if (action == "w") {
            showCurrentWall();
            if (currentWall == 1) {
                wall1->inspect();
                inventory.addItem(wall1->item);
            } else if (currentWall == 2) {
                wall2->inspect();
                inventory.addItem(wall2->item);
            } else if (currentWall == 3) {
                wall3->inspect();
            } else if (currentWall == 4) {
                wall4->inspect();
            }
        } else if (action == "i") {
            inventory.display();
        } else if (action == "e") {
            if (currentWall == 3) {
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

        if (getTimeRemaining() <= 0) {
            gameOver = true;
            cout << "Time's up! You didn't escape in time.\n";
        }
    }
}

void AdventureGame::displayRoom() {
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << "TURN LEFT 'l' | TURN RIGHT 'r' | INSPECT OBJECT 'w' | OPEN INVENTORY 'i' | OPEN DOOR 'e'\n";
    cout << "TIME IS " << getTimeRemaining() << " MINUTES | YOU HAVE 3 MINUTES TO ESCAPE\n";
    cout << "--------------------------------------------------------------------------------------------------\n";
}

void AdventureGame::showCurrentWall() {
    switch (currentWall) {
        case 1: wall1->showAsciiArt("wall1"); break;
        case 2: wall2->showAsciiArt("wall2"); break;
        case 3: wall3->showAsciiArt("wall3"); break;
        case 4: wall4->showAsciiArt("wall4"); break;
    }
}

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

int AdventureGame::getTimeRemaining() {
    chrono::duration<int> duration = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - startTime);
    int timeElapsed = duration.count();
    return (3 - (timeElapsed / 60)) >= 0 ? 3 - (timeElapsed / 60) : 0;
}

void AdventureGame::saveGame() {
    inventory.saveToFile("inventory.txt");
}

void AdventureGame::loadGame() {
    inventory.loadFromFile("inventory.txt");
}
