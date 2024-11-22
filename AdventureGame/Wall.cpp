#include "Wall.h"    // Include the header file for Wall class
#include <iostream>  // For console input/output

using namespace std;

// Constructor initializes the Wall object with given description, item found, door status, and required key
Wall::Wall(const string& desc, const string& itemFound, bool door, const string& key)
    : description(desc), item(itemFound), isDoor(door), isOpen(false), requiredKey(key) {}

// Destructor for the Wall class (empty here but useful for cleanup in derived classes)
Wall::~Wall() {
    // Placeholder for dynamic resource cleanup if needed in the future
}

// Inspect the wall and display its description; informs if an item is present
void Wall::inspect() {
    cout << description << endl;
    if (!item.empty()) {
        cout << "You find a " << item << " on this wall.\n";
    }
}

// Allows a player to interact with the wall; checks if the door can be unlocked with the correct key
void Wall::useItem(Inventory& inv) {
    if (isDoor && !isOpen) { // Check if it's a door and currently locked
        if (inv.hasItem(requiredKey)) { // Check if the inventory contains the required key
            isOpen = true;
            cout << "You unlocked the door and it's now open!\n";
        } else {
            cout << "You need a key to open this door.\n";
        }
    }
}

// Overload the stream insertion operator to print Wall details
ostream& operator<<(ostream& os, const Wall& wall) {
    os << "Description: " << wall.description << endl; // Print wall description
    if (!wall.item.empty()) { // Print the item if it exists
        os << "You find a " << wall.item << " on this wall.\n";
    }
    return os;
}
