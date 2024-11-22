#ifndef BOOKCASEWALL_H
#define BOOKCASEWALL_H

#include "Wall.h" // Include the base Wall class for inheritance

// Derived class representing a wall with a bookcase
class BookcaseWall : public Wall {
public:
    BookcaseWall(); // Constructor initializes the bookcase wall
    void showAsciiArt() const override; // Override to display ASCII art for the bookcase
};

#endif
