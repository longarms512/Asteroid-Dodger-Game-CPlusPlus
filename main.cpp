
#include <stdlib.h>
#include "globals.h"
#include "hardware.h"
#include "wave_player.h"
#include "SDFileSystem.h"
#include "Speaker.h"
#include <string>


Speaker mySpeaker1(p25); 

#include "SpaceShipEarth.h"
#include "ConcreteAsteroid1.h"
#include "ConcreteAsteroid2.h"
#include "ConcreteAsteroid3.h"
#include "ConcreteAsteroid4.h"


DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

SDFileSystem sd(p5, p6, p7, p8, "sd");

bool overlap(ScreenObject& objectA, ScreenObject& objectB);// function to check asteroid contact with the earth

void draw_explosion(int x, int y); // draw an explosion

void playSoundEnter(); // play a sound
void playSoundLost(); // play a sound
void playSoundWon(); // play a sound

bool did_lose = false; // boolean that checks to see if player has lost


int main() // start main
{
    
    uLCD.baudrate(300000);
    wait(0.2);
    
    srand(time(NULL));
    GameInputs inputs; // inputs from accelerometer and buttons
    SpaceShipEarth ship(64, 64); // earth ship object
    int time = 0; // timer 
    
    //initialize all asteroid obejects
    ConcreteAsteroid1 ast1(0, 0);
    ConcreteAsteroid2 ast2(0, 0);
    ConcreteAsteroid3 ast3(0, 0);
    ConcreteAsteroid4 ast4(0, 0);
    ConcreteAsteroid1 ast5(0, 0);
    ConcreteAsteroid2 ast6(0, 0);
    
    // enter asteroids into activeasteroid list as pointers to ScreenObjects
    ScreenObject* ActiveAsteroids[6] = {&ast1, &ast2, &ast3, &ast4, &ast5, &ast6};

    
    
    // while loop to start the game 
    uLCD.printf("Push any button to start.\n");
    while(1){
      inputs.read_inputs();
      if (inputs.b1 || inputs.b2 || inputs.b3) break;
    }
    uLCD.cls();
    playSoundEnter();      
    
    while(1) // begin main game while loop
    {
        
        ship.printtime((time/3)); // print the timer to the bottom of the screen
        
        ship.update(inputs.ax, inputs.ay); // continuously update the coordinates of the earth
        ship.draw(); // draw the earth ship
        
        for(int i = 0; i < 3; i++) {
            ActiveAsteroids[i]->draw(); // draw the first three asteroid
        }
        
        
        ship.printtime((time/3)); // update the timer graphic at the bottom of the screen
        
        for (int i = 0; i < 6; i++) {
            if (overlap(ship, *ActiveAsteroids[i]) == true) { // check to see if there is any overlap between the ship and any asteroid
                did_lose = true; // if overlap, set game lose to true and break loop
                break;
            }   
        }
        ship.update(inputs.ax, inputs.ay); // continuously update the coordinates of the earth
        ship.draw(); // draw the earth ship
        
        for(int i = 3; i < 6; i++) {        
            ActiveAsteroids[i]->draw(); // draw the last 3 asteroids 
        }
        
        
        for (int i = 0; i < 6; i++) {
            ActiveAsteroids[i]->update(); // update the coordinates of the first asteroid
        }
        
        ast1.check_out_of_range(); // check to see if the first asteroid has left the screen
        ast2.check_out_of_range(); // check to see if the second asteroid has left the screen
        ast3.check_out_of_range(); // check to see if the third asteroid has left the screen
        ast4.check_out_of_range(); // check to see if the fourth asteroid has left the screen
        ast5.check_out_of_range(); // check to see if the fifth asteroid has left the screen
        ast6.check_out_of_range(); // check to see if the sixth asteroid has left the screen
        
        
        
        
        inputs.read_inputs(); // get inputs from the board 

        
        for (int i = 0; i < 6; i++) {
            if (overlap(ship, *ActiveAsteroids[i]) == true) { // check for overlap between the ship and any asteroid
                did_lose = true; // if overlap, set did_lose to true
                break;
            }   
        }
        
        
        if (did_lose == true || (time/3) >= 30) { // if did_lose is true of time has reached 60seconds, leave the while loop
            break;
        }
        
        
        /*
        if (inputs.b1 && inputs.b2) {
            ship.pause();
            wait(1);
            while(1){
                inputs.read_inputs();
                if (inputs.b1) {
                    break;
                }
            }
            ship.clearscrn();
        }
        */
        
        time++; // increase time by 1, ~1 second since last time increase
        
    }
    
    if (did_lose == false) { 
        playSoundWon();
        ship.game_won(); // if the player has made it to 60 seconds, print game won
    }
    else {
        playSoundLost();
        ship.game_over(); // if the player has hit an asteroid, print game over
    }
    
    
    
    return 0;
    
}

// fucntion to check to see if earth has hit an object in space .. 
// return true if collision
// return false if no collision
bool overlap(ScreenObject& objectA, ScreenObject& objectB) { // collision detection
    
    if (objectA.getX() >= objectB.getX() && // if top left corner of earth has hit an asteroid
        objectA.getX() <= objectB.getX() + 11 && 
        objectA.getY() >= objectB.getY() && 
        objectA.getY() <= objectB.getY() + 15) { 
        draw_explosion(objectA.getX(), objectA.getY());
        
        return true;
    }
    
    else if (objectA.getX() + 10 >= objectB.getX() &&  // if top right corner of earth has hit an asteroid
             objectA.getX() + 10 <= objectB.getX() + 11 && 
             objectA.getY() >= objectB.getY() && 
             objectA.getY() <= objectB.getY() + 15) {
             draw_explosion(objectA.getX()+10, objectA.getY());
             
             return true;
    }
    
    else if (objectA.getX() >= objectB.getX() &&  // if bottom left corner of earth has hit an asteroid
             objectA.getX() <= objectB.getX() + 11 && 
             objectA.getY() + 10  >= objectB.getY() && 
             objectA.getY() + 10 <= objectB.getY() + 15) {
             draw_explosion(objectA.getX(), objectA.getY()+10);
            
             return true;
    }
    
    else if (objectA.getX() + 10 >= objectB.getX() &&  // if bottom right corner of earth has hit an asteroid
             objectA.getX() + 10 <= objectB.getX() + 11 && 
             objectA.getY() + 10 >= objectB.getY() && 
             objectA.getY() + 10 <= objectB.getY() + 15) {
             draw_explosion(objectA.getX()+10, objectA.getY()+10);
             
             return true;
    }
    
    else {
        return false; // if earth has not hit an asteroid, return false
    }
}

void draw_explosion(int x, int y) { // draw an explosion where the collision happens
    uLCD.filled_rectangle(y-5, x-5, y-2, x-2, RED);
    uLCD.filled_rectangle(y-5, x+2, y-2, x+2, RED);
    uLCD.filled_rectangle(y+2, x-5, y+5, x-2, RED);
    uLCD.filled_rectangle(y+2, x+2, y+5, x+5, RED);
}

void playSoundEnter() { // game entry noise
    mySpeaker1.PlayNote(262.0,0.25,0.1);
    wait(.25);
    mySpeaker1.PlayNote(294.0,0.12,0.1);
    wait(.12);
    mySpeaker1.PlayNote(329.0,0.12,0.1);
    wait(.12);
    mySpeaker1.PlayNote(262.0,0.12,0.1);
    wait(.12);
    mySpeaker1.PlayNote(392.0,0.5,0.1);
    return;
}

void playSoundLost() { // game lost music
    mySpeaker1.PlayNote(523.0,0.1,0.1);
    wait(.1);
    mySpeaker1.PlayNote(587.0,0.1,0.1);
    wait(.25);
    
    mySpeaker1.PlayNote(494.0,0.15,0.1);
    wait(.15);
    
    mySpeaker1.PlayNote(699.0,0.15,0.1);
    wait(.15);
    mySpeaker1.PlayNote(699.0,0.15,0.1);
    wait(.15);
    mySpeaker1.PlayNote(699.0,0.15,0.1);
    wait(.15);
    
    mySpeaker1.PlayNote(659.0,0.15,0.1);
    wait(.15);
    mySpeaker1.PlayNote(587.0,0.15,0.1);
    wait(.15);
    mySpeaker1.PlayNote(523.0,0.15,0.1);
    wait(.15);
    
    mySpeaker1.PlayNote(330.0,0.15,0.1);
    wait(.15);
    mySpeaker1.PlayNote(330.0,0.1,0.1);
    wait(.1);
    
    mySpeaker1.PlayNote(261.0,0.25,0.1);
    wait(.25);
    
    return;
}

void playSoundWon() { // game won music
    mySpeaker1.PlayNote(261.0,0.25,0.1);
    mySpeaker1.PlayNote(330.0,0.25,0.1);
    mySpeaker1.PlayNote(392.0,0.25,0.1);
    wait(.25);
    
    mySpeaker1.PlayNote(311.0,0.25,0.1);
    mySpeaker1.PlayNote(392.0,0.25,0.1);
    mySpeaker1.PlayNote(466.0,0.25,0.1);
    wait(.25);
    
    mySpeaker1.PlayNote(466.0,0.25,0.1);
    mySpeaker1.PlayNote(587.0,0.25,0.1);
    mySpeaker1.PlayNote(698.0,0.25,0.1);
    wait(.25);
    
    mySpeaker1.PlayNote(370.0,0.25,0.1);
    mySpeaker1.PlayNote(466.0,0.25,0.1);
    mySpeaker1.PlayNote(554.0,0.25,0.1);
    wait(.25);
    
    mySpeaker1.PlayNote(277.0,0.25,0.1);
    mySpeaker1.PlayNote(349.0,0.25,0.1);
    mySpeaker1.PlayNote(415.0,0.25,0.1);
    wait(.25);
    
    mySpeaker1.PlayNote(523.0,0.25,0.1);
    mySpeaker1.PlayNote(659.0,0.25,0.1);
    mySpeaker1.PlayNote(784.0,0.25,0.1);
    wait(.25);
    
    
    return;
}







