#ifndef WALL_H
#define WALL_H

#include <string>
#include "Inventory.h"

using namespace std;

class Wall {
public:
    string description;
    string item;
    bool isDoor;
    bool isOpen;
    string requiredKey;

    Wall(const string& desc, const string& itemFound = "", bool door = false, const string& key = "");
    void inspect();
    void useItem(Inventory& inv);
    void showAsciiArt(const string& wallName) const;
    friend ostream& operator<<(ostream& os, const Wall& wall);
};

#endif
