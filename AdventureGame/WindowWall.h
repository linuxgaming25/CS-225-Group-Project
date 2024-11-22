#ifndef WINDOWWALL_H
#define WINDOWWALL_H

#include "Wall.h"  // Include base class Wall for inheritance

// Declaration of the WindowWall class, inheriting from Wall
class WindowWall : public Wall {
public:
    WindowWall();  // Constructor: Initializes a WindowWall object
    void showAsciiArt() const override;  // Overrides the pure virtual function in Wall
};

#endif
