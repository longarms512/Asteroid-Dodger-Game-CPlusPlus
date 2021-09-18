
#ifndef ABSTRACTASTEROID_H
#define ABSTRACTASTEROID_H
#include "ScreenObject.h"

class AbstractAsteroid : public ScreenObject { // child of Screen Object class
  
  public:
    AbstractAsteroid(int, int); // constructor
    void setDX(int); // set Delta X
    void setDY(int); // set Delta Y
    

  
  protected:
    int deltaX; // change in X value
    int deltaY; // change in Y value
         
    
};

#endif 