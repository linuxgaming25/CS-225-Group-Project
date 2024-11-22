#include "BookcaseWall.h" // Include the BookcaseWall class definition
#include <iostream>       // For output operations

using namespace std;

// Constructor initializes the wall description and hidden item
BookcaseWall::BookcaseWall() 
    : Wall("A bookshelf on the wall.", "key to stairwell") {}

// Displays ASCII art representing the bookshelf
void BookcaseWall::showAsciiArt() const {
    cout << "Bookshelf with Key:\n";
    cout << "  _______________ \n";
    cout << " |              | \n";
    cout << " |______________| \n";
    cout << " |--------------| \n";
    cout << " |              | \n";
    cout << " |--------------| \n";
    cout << " |--------------| \n";
    cout << " |              | \n";
    cout << " |--------------| \n";
    cout << " |--------------| \n";
    cout << " |              | \n";
    cout << " |--------------| \n";
    cout << " |--------------| \n";
}
