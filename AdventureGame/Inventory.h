#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>   // For the std::vector container
#include <string>   // For the std::string type
#include <iostream> // For console I/O operations

using namespace std;

// Class to manage player inventory
class Inventory {
public:
    vector<string> items; // Stores a list of inventory items

    Inventory(); // Constructor to initialize the inventory
    void addItem(const string& item); // Adds an item to the inventory
    bool hasItem(const string& item) const; // Checks if an item exists in the inventory
    void display() const; // Displays the inventory contents
    void saveToFile(const string& filename) const; // Saves inventory to a file
    void loadFromFile(const string& filename); // Loads inventory from a file
};

#endif
