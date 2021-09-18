
#ifndef CONCRETEASTEROID3_H
#define CONCRETEASTEROID3_H
#include "AbstractAsteroid.h"

class ConcreteAsteroid3 : public AbstractAsteroid { // child of AbstractAsteroid  grandchild of ScreenObject
  
  public:
    ConcreteAsteroid3(int, int); // onstructor
    void draw(); // virtual function to draw the asteroid
    void update(); // virtual function to update the position of the asteroid
    void check_out_of_range(); // check to see if the asteroid is off the screen
    void new_asteroid(); // create a new location and dX and dY of the asteroid

    
};

#endif 