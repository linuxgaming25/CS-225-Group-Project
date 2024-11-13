#include "Inventory.h"
#include <fstream>
#include <iostream>

using namespace std;

Inventory::Inventory() {
    items.push_back("car keys");
}

void Inventory::addItem(const string& item) {
    items.push_back(item);
}

bool Inventory::hasItem(const string& item) const {
    for (const auto& i : items) {
        if (i == item) return true;
    }
    return false;
}

void Inventory::display() const {
    cout << "\nInventory: ";
    if (items.empty()) {
        cout << "Empty";
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i];
            if (i != items.size() - 1) cout << " | ";
        }
    }
    cout << "\n";
}

void Inventory::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const string& item : items) {
            outFile << item << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open file to save inventory.\n";
    }
}

void Inventory::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    string item;
    while (getline(inFile, item)) {
        items.push_back(item);
    }
    inFile.close();
}
