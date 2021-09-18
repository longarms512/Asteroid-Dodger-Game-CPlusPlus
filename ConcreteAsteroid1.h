
#ifndef CONCRETEASTEROID1_H
#define CONCRETEASTEROID1_H
#include "AbstractAsteroid.h"

class ConcreteAsteroid1 : public AbstractAsteroid { // child of AbstractAsteroid   grandchild of ScreenObject
  
  public:
    ConcreteAsteroid1(int, int); // constructor
    void draw(); // virtual fucntion to draw the asteroid
    void update(); // update the postion of the asteroid
    void check_out_of_range(); // check to see if the asteroid is out of range
    void new_asteroid(); // create a new location of the asteroid when initialized, or if out of range
         
    
};

#endif 