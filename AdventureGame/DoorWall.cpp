#include "DoorWall.h" // Include the DoorWall class definition
#include <iostream>   // For output operations

using namespace std;

// Constructor initializes the wall with a description, no hidden item, lock status, and a required key
DoorWall::DoorWall(const string& description, const string& requiredKey)
    : Wall(description, "", true, requiredKey) {}

// Displays ASCII art representing two doors
void DoorWall::showAsciiArt() const {
    cout << "Two Doors:\n";
    cout << "  _______________ \n";
    cout << " |  Two Doors   | \n";
    cout << " |              | \n";
    cout << " |_____    _____| \n";
    cout << " ||   |    |   || \n";
    cout << " ||   |    |   || \n";
    cout << " ||   |    |   || \n";
    cout << " ||   |    |   || \n";
    cout << " ||  O|    |  O|| \n";
    cout << " ||   |    |   || \n";
    cout << " ||   |    |   || \n";
    cout << " --------------- \n";
}
