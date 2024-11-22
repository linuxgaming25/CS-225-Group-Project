#ifndef DOORWALL_H
#define DOORWALL_H

#include "Wall.h" // Include the base Wall class for inheritance

// Derived class representing a wall with doors
class DoorWall : public Wall {
public:
    // Constructor initializes the door wall with a description and a required key
    DoorWall(const string& description, const string& requiredKey);

    // Override to display ASCII art for the doors
    void showAsciiArt() const override;
};

#endif
