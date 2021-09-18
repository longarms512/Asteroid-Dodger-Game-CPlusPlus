#include "ScreenObject.h"
#include "globals.h"

ScreenObject::ScreenObject(int x = 0, int y = 0) {
    x_pos = x; // initialize x_pos to 0 if no value is passed
    y_pos = y; // initialize y_pos to 0 if no value is passed
    
}

void ScreenObject::draw() { // virtual draw function
    return;
}

void ScreenObject::update() { // virtual update function
    return;
}

void ScreenObject::setX(int x) { // function sets x_pos to value passed as x
    x_pos = x;
}

void ScreenObject::setY(int y) { // function sets y_pos to value passed as y
    y_pos = y;
}

int ScreenObject::getX() { // function returns x_pos 
    return x_pos;
}

int ScreenObject::getY() { // functions return y_pos
    return y_pos;
}