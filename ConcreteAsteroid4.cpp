
#include "ConcreteAsteroid4.h"
#include "globals.h"
/*
int asteroid_sprite_1[ASTEROID_HEIGHT * ASTEROID_WIDTH] = { // image of the asteroid
_,_,_,X,X,X,X,X,X,X,X,_,_,_,_,
_,_,_,X,_,_,_,_,_,_,,X,_,_,_,
_,_,X,X,X,_,_,_,_,_,_,X,_,_,_,
_,X,_,_,_,_,_,_,_,_,_,_,X,X,_,
X,_,_,_,_,_,_,_,_,_,_,_,_,_,X,
_,X,_,_,_,_,_,_,_,_,_,_,_,_,X,
_,X,_,_,_,_,_,_,_,_,_,X,X,_,X,
_,X,_,_,_,_,_,_,_,_,_,X,_,X,X,
_,_,X,_,_,_,_,_,_,_,X,_,_,_,_,
_,_,_,X,_,_,_,_,_,_,X,_,_,_,_,
_,_,_,_,X,_,_,_,_,_,X,_,_,_,_,
_,_,_,_,_,X,X,X,X,X,X,_,_,_,_,
};
*/
ConcreteAsteroid4::ConcreteAsteroid4(int x = 0, int y = 0):AbstractAsteroid(x, y) { // constructor 
    new_asteroid(); // create a new location and dx and dy of the asteroid
}

void ConcreteAsteroid4::draw() { // draw the asteroid
    
    uLCD.filled_rectangle(y_pos-6, x_pos-6, y_pos+21, x_pos+21, 000000); // clear the old asteroid
    
    
    uLCD.line(y_pos + 0, x_pos + 3,  y_pos + 0, x_pos + 10, X);
    uLCD.line(y_pos + 0, x_pos + 10,  y_pos + 2, x_pos + 11, X);
    uLCD.line(y_pos + 2, x_pos + 11,  y_pos + 4, x_pos + 14, X);
    uLCD.line(y_pos + 4, x_pos + 14,  y_pos + 7, x_pos + 14, X);
    uLCD.line(y_pos + 7, x_pos + 14,  y_pos + 6, x_pos + 11, X);
    
    uLCD.line(y_pos + 6, x_pos + 11,  y_pos + 11, x_pos + 10, X);
    uLCD.line(y_pos + 11, x_pos + 10,  y_pos + 11, x_pos + 5, X);
    uLCD.line(y_pos + 11, x_pos + 5,  y_pos + 7, x_pos + 1, X);
    uLCD.line(y_pos + 7, x_pos + 1,  y_pos + 4, x_pos + 0, X);
    uLCD.line(y_pos + 4, x_pos + 0,  y_pos + 2, x_pos + 4, X);
    uLCD.line(y_pos + 2, x_pos + 4,  y_pos + 0, x_pos + 3, X);
    
  
    
    /*
    for (int i = 0; i < ASTEROID_HEIGHT; i++) {
        for (int j = 0; j < ASTEROID_WIDTH; j++) {
            uLCD.pixel(x_pos + i, y_pos +j,  asteroid_sprite_1[(i*15) + j]);
        }
    }
    */
}

void ConcreteAsteroid4::update() { // update the position of the asteroid
    setX(x_pos + deltaX);
    setY(y_pos + deltaY);
}

void ConcreteAsteroid4::check_out_of_range() { // check to see if the asteroid is out of range
    if (x_pos > 132 || y_pos > 132 || x_pos < -17 || y_pos < -15) {
        
        new_asteroid(); // create a new location of the asteroid if it is out of range
    
    }
}

void ConcreteAsteroid4::new_asteroid() { // create a new location of the asteroid 
    
    int side = (rand()%8); // get a random number for the side
    
    if (side == 0 || side == 6) { // creates an asteroid starting at the top of the screen
        setX(0);
        setY(rand()%118);
    }
    
    else if (side == 1 || side == 4) { // creates an asteriod starting on the right side of the screen
        setX(rand()%118);
        setY(118);
    }
    
    else if (side == 2 || side == 7) { // creates an asteroid starting at the bottom of the screen
        setX(118);
        setY(rand()%118);
    }
    
    else if (side == 3 || side == 5) { // creates an asteroid starting on the left side of the screen
        setX(rand()%118);
        setY(0);
    }
    
    // set deltaX and deltaY depending on where the asteroid starts at on the screen so the asteroid
    // moves towards the center of the screen to the earth.
    
    if (x_pos <= 64 && y_pos <= 64) { 
        setDX((rand()%3)+1);
        setDY((rand()%3)+1);
    }
    
    else if (x_pos <= 64 && y_pos > 64) {
        setDX((rand()%3)+1);
        setDY(-((rand()%3)+1));
    }
    
    else if (x_pos > 64 && y_pos <= 64) {
        setDX(-((rand()%3)+1));
        setDY((rand()%3)+1);
    }
    
    else if (x_pos > 64 && y_pos > 64) {
        setDX(-((rand()%3)+1));
        setDY(-((rand()%3)+1));
    }
}