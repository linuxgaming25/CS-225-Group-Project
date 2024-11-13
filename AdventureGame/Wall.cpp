#include "Wall.h"
#include "Inventory.h"
#include <iostream>

using namespace std;

// Wall class constructor
Wall::Wall(const string& desc, const string& itemFound, bool door, const string& key)
    : description(desc), item(itemFound), isDoor(door), isOpen(false), requiredKey(key) {}

// Inspect the wall and show description and item if available
void Wall::inspect() {
    cout << description << endl;
    if (!item.empty()) {
        cout << "You find a " << item << " on this wall.\n";
    }
}

// Use an item on the wall for doors that need a key to unlock
void Wall::useItem(Inventory& inv) {
    if (isDoor && !isOpen) {
        if (inv.hasItem(requiredKey)) {
            isOpen = true;
            cout << "You unlocked the door and it's now open!\n";
        } else {
            cout << "You need a key to open this door.\n";
        }
    }
}

// Display ASCII art based on the wall name
void Wall::showAsciiArt(const string& wallName) const {
    if (wallName == "wall1") {
        cout << "Desk with Key:\n";
        cout << "  _______________ \n";
        cout << "  _______________ \n";
        cout << "  _______________ \n";
        cout << "  _______________ \n";
        cout << "  _________|===|_ \n";
        cout << "  __O=F____|___|_ \n";
        cout << " |         |   | | \n";
        cout << " |         |===| | \n";
        cout << " |         |   | | \n";
        cout << " ----------|---|- \n";
    }
    else if (wallName == "wall2") {
        cout << "Bookshelf with Key:\n";
        cout << "  _______________ \n";
        cout << " |              | \n";
        cout << " |__O=F_________| \n";
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
    else if (wallName == "wall3") {
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
        cout << " ||   |    |   || \n";
        cout << " --------------- \n";
    }
    else if (wallName == "wall4") {
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
        cout << " |              | \n";
        cout << " |              | \n";
        cout << " --------------- \n";
    }
    else {
        cout << "No ASCII art available for this wall.\n";
    }
}

// Overload the ostream operator to print the wall's description
ostream& operator<<(ostream& os, const Wall& wall) {
    os << "Description: " << wall.description << endl;
    if (!wall.item.empty()) {
        os << "You find a " << wall.item << " on this wall.\n";
    }
    return os;
}
