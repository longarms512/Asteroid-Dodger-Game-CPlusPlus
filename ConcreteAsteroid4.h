
#ifndef CONCRETEASTEROID4_H
#define CONCRETEASTEROID4_H
#include "AbstractAsteroid.h"

class ConcreteAsteroid4 : public AbstractAsteroid {
  
  public:
    ConcreteAsteroid4(int, int);
    void draw();
    void update();
    void check_out_of_range();
    void new_asteroid();

  
  private:
    
         
    
};

#endif 