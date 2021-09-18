
#ifndef SPACESHIPEARTH_H
#define SPACESHIPEARTH_H
#include "ScreenObject.h"

class SpaceShipEarth : public ScreenObject { // child of Screen Object class
  
  public:
    SpaceShipEarth(int, int); // constructor
    
    void player_moveUp(void); // move the player up
    void player_moveDown(void); // move the player down
    void player_moveLeft(void); // moves the player left
    void player_moveRight(void); // moved the player right
    
    void draw(); // uses virtual function from ScreenObject draw() to draw an earth 
    void update(float, float); // update the x and y positions of the earth after taking in ax and ay as parameters from the accelerometer
    
    void printtime(int); // print the time remaining at the bottom of the screen as a status bar
    
    
    void game_over(void); // print the game over screen
    void game_won(void); // print the game won screen

    void clearscrn(void); // clear the entire screen
     
    
};

#endif 