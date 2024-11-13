#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Inventory {
public:
    vector<string> items;

    Inventory();
    void addItem(const string& item);
    bool hasItem(const string& item) const;
    void display() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
