#include "DeskWall.h" // Include the DeskWall class definition
#include <iostream>   // For output operations

using namespace std;

// Constructor initializes the wall description and hidden item
DeskWall::DeskWall() 
    : Wall("A boss office desk and chair.", "key to lobby") {}

// Displays ASCII art representing the desk
void DeskWall::showAsciiArt() const {
    cout << "Desk with Key:\n";
    cout << "  _______________ \n";
    cout << "  _______________ \n";
    cout << "  _______________ \n";
    cout << "  _______________ \n";
    cout << "  _________|===|_ \n";
    cout << "  _________|___|_ \n";
    cout << " |         |   | | \n";
    cout << " |         |===| | \n";
    cout << " |         |   | | \n";
    cout << " ----------|---|- \n";
}
