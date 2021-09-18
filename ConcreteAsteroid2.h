
#ifndef CONCRETEASTEROID2_H
#define CONCRETEASTEROID2_H
#include "AbstractAsteroid.h"

class ConcreteAsteroid2 : public AbstractAsteroid { // child of AbstractAsteroid   grandchild of ScreenObjectx
  
  public:
    ConcreteAsteroid2(int, int); // constructor
    void draw(); // virtual function to draw the asteroid
    void update(); // virtual function to update the location of the asteroid
    void check_out_of_range(); // check to see if the asteroid is out of range
    void new_asteroid(); // create a new location of the asteroid if it is initiallized or out of range

  
  private:
    
         
    
};

#endif 