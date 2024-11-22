#include "Inventory.h" // Include the Inventory class definition
#include <fstream>     // For file input/output
#include <iostream>    // For console output

using namespace std;

// Constructor initializes the inventory with a default item
Inventory::Inventory() {
    items.push_back("car keys");
}

// Adds an item to the inventory
void Inventory::addItem(const string& item) {
    items.push_back(item);
}

// Checks if the inventory contains a specific item
bool Inventory::hasItem(const string& item) const {
    for (const auto& i : items) { // Iterate over items
        if (i == item) return true;
    }
    return false;
}

// Displays the inventory contents
void Inventory::display() const {
    cout << "\nInventory: ";
    if (items.empty()) { // Check if inventory is empty
        cout << "Empty";
    } else {
        for (size_t i = 0; i < items.size(); ++i) { // Loop through items
            cout << items[i];
            if (i != items.size() - 1) cout << " | "; // Add separator
        }
    }
    cout << "\n";
}

// Saves the inventory contents to a file
void Inventory::saveToFile(const string& filename) const {
    ofstream outFile(filename); // Open file for writing
    if (outFile.is_open()) {    // Check if the file opened successfully
        for (const string& item : items) {
            outFile << item << endl; // Write each item to the file
        }
        outFile.close(); // Close the file
    } else {
        cout << "Unable to open file to save inventory.\n";
    }
}

// Loads inventory contents from a file
void Inventory::loadFromFile(const string& filename) {
    ifstream inFile(filename); // Open file for reading
    string item;
    while (getline(inFile, item)) { // Read each line as an item
        items.push_back(item);      // Add item to the inventory
    }
    inFile.close(); // Close the file
}
