
#include "SpaceShipEarth.h"
#include "globals.h"

SpaceShipEarth::SpaceShipEarth(int x = 64, int y = 64):ScreenObject(x, y) {   //constructor initiazes the x_pos and y_pos to 64 (center of the screen)

}



void SpaceShipEarth::player_moveUp(void) {  // moves the player up 5 pixels
    if (x_pos > 10) {
        x_pos -= 5;
    }
    
    return; 
    
}

void SpaceShipEarth::player_moveDown(void) {  // moves the player down 5 pixels
    if (x_pos < 110) {
        x_pos += 5;
    }
    
    return;
    
}

void SpaceShipEarth::player_moveLeft(void) {  // moves the player left 5 pixels
    if (y_pos > 0) {
        y_pos -= 5;
    }
    return;
}

void SpaceShipEarth::player_moveRight(void) {  // moves the player right 5 pixels
    if (y_pos < 128) {
        y_pos += 5;
    }
    return;
}

void SpaceShipEarth::draw() { // draws the earth 

    // replace the old positon of earth with black
    uLCD.filled_rectangle(y_pos-5, x_pos-5, y_pos+15, x_pos, 000000);
    uLCD.filled_rectangle(y_pos-5, x_pos+10, y_pos+15, x_pos+15, 000000);
    uLCD.filled_rectangle(y_pos-5, x_pos, y_pos, x_pos+10, 000000);
    uLCD.filled_rectangle(y_pos+10, x_pos, y_pos+15, x_pos+10, 000000);
    
    //draw the blue earth
    uLCD.filled_rectangle(y_pos+1, x_pos+1, y_pos+9, x_pos+9, BLUE);
    uLCD.filled_rectangle(y_pos+2, x_pos, y_pos+8, x_pos, BLUE);
    uLCD.filled_rectangle(y_pos+2, x_pos+10, y_pos+8, x_pos+10, BLUE);
    uLCD.filled_rectangle(y_pos, x_pos+2, y_pos, x_pos+8, BLUE);
    uLCD.filled_rectangle(y_pos+10, x_pos+2, y_pos+10, x_pos+8, BLUE);
    
    // draw the green land on earth
    uLCD.filled_rectangle(y_pos+2, x_pos+2, y_pos+5, x_pos+5, GREEN);
    uLCD.filled_rectangle(y_pos+4, x_pos+6, y_pos+8, x_pos+8, GREEN);
    uLCD.filled_rectangle(y_pos+4, x_pos+5, y_pos+4, x_pos+5, GREEN);
    
}

void SpaceShipEarth::update(float ax, float ay) { // takes in ax and ay from the inputs in main to update the positon of earth
    if (ay>=0.3) player_moveUp(); // calls the move player up function            
    if (ay<= -0.3) player_moveDown(); // calls the move player down function            
    if (ax<= -0.3) player_moveLeft(); // calls the move player left function            
    if (ax>= 0.3) player_moveRight(); // calls the move player right function            
    
}




void SpaceShipEarth::game_over(void) { // prints the game is over with red screen
    uLCD.filled_rectangle(0, 0, 127, 127, RED);
    uLCD.printf("\n\n\n\n    Game Over \n\n\n\n\n\n\n\n\n\n\n\n");
}

void SpaceShipEarth::game_won(void) { // prints game won with green screen
    uLCD.filled_rectangle(0, 0, 127, 127, GREEN);
    uLCD.printf("\n\n\n\n    Game WON! \n\n\n\n\n\n\n\n\n\n\n\n");
}



void SpaceShipEarth::clearscrn(void) { // clears the screen
    uLCD.filled_rectangle(0, 0, 127, 127, 0);
    return;
}
void SpaceShipEarth::printtime(int time) { // prints a time progress bar at the bottom of the screen
    
    uLCD.filled_rectangle(3, 120, 124, 125, WHITE);
    uLCD.filled_rectangle(3, 121, 123, 124, 000000);
    uLCD.filled_rectangle(3, 121, 123 - (time * 4), 124, GREEN);
    
    //uLCD.printf("\n\n\n\n %d \n\n\n\n\n\n\n\n\n\n\n\n", time);
    
}


