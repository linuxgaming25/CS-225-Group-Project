#ifndef DESKWALL_H
#define DESKWALL_H

#include "Wall.h" // Include the base Wall class for inheritance

// Derived class representing a wall with a desk
class DeskWall : public Wall {
public:
    DeskWall(); // Constructor initializes the desk wall
    void showAsciiArt() const override; // Override to display ASCII art for the desk
};

#endif
