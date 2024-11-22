#ifndef WALL_H
#define WALL_H

#include <string>        // For using std::string
#include "Inventory.h"   // Include Inventory class for interaction
#include <iostream>      // For console input/output

using namespace std;

// Wall class definition
class Wall {
public:
    string description;   // Text description of the wall
    string item;          // Item available on the wall (if any)
    bool isDoor;          // Indicates if the wall is a door
    bool isOpen;          // Indicates if the door is open (applies only to doors)
    string requiredKey;   // Key required to open the door (if applicable)

    // Constructor initializes wall attributes with optional default values
    Wall(const string& desc, const string& itemFound = "", bool door = false, const string& key = "");

    virtual ~Wall(); // Virtual destructor ensures proper cleanup in derived classes

    virtual void inspect();  // Displays the wall description and any items found
    virtual void useItem(Inventory& inv); // Allows interaction, such as unlocking a door
    virtual void showAsciiArt() const = 0; // Pure virtual function for rendering ASCII art for the wall

    // Overloads the stream insertion operator to print wall details
    friend ostream& operator<<(ostream& os, const Wall& wall);
};

#endif
