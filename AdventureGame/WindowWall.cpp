#include "WindowWall.h"   // Include the header for the WindowWall class
#include <iostream>       // Include for input/output functionality

using namespace std;

// Constructor: Initializes WindowWall with a description, uses Wall's base constructor
WindowWall::WindowWall() 
    : Wall("A window with a sunset outside.") {}

// Displays ASCII art for the window wall
void WindowWall::showAsciiArt() const {
    cout << "Window with Sunset:\n";
    cout << "  _______________ \n";
    cout << " |              | \n";
    cout << " | ____________ | \n";
    cout << " | |          | | \n";
    cout << " | |    ~     | | \n";
    cout << " | |  ~ - ~   | | \n";
    cout << " | |~ -+++- ~ | | \n";
    cout << " | |_-++*++-__| | \n";
    cout << " | |----------| | \n";
    cout << " | |__________| | \n";
    cout << " |              | \n";
    cout << " --------------- \n";
}
