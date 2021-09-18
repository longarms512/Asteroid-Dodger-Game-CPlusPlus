
#include "AbstractAsteroid.h"
#include "globals.h"

AbstractAsteroid::AbstractAsteroid(int x = 0, int y = 0):ScreenObject(x, y) { // constructor   
    
}

void AbstractAsteroid::setDX(int dX) { // set the delta X to a value specified
    deltaX = dX;
}

void AbstractAsteroid::setDY(int dY) { // set the delta Y to a value specified
    deltaY = dY;
}

