
#include "globals.h"
#include "hardware.h"



uLCD_4DGL uLCD(p9,p10,p11);             // LCD Screen (tx, rx, reset)
//SDFileSystem sd(p5, p6, p7, p8, "sd");  // SD Card(mosi, miso, sck, cs)
Serial pc(USBTX,USBRX);                 // USB Console (tx, rx)
MMA8452 acc(p28, p27, 100000);        // Accelerometer (sda, sdc, rate)
DigitalIn button1(p21);                 // Pushbuttons (pin)
DigitalIn button2(p22);
DigitalIn button3(p23);
AnalogOut DACout(p18);                  // Speaker (pin)
PwmOut speaker(p25); 



GameInputs::GameInputs() {    
    // Initialize pushbuttons
    button1.mode(PullUp); 
    button2.mode(PullUp);
    button3.mode(PullUp);
}


void GameInputs::read_inputs() { // get the values of pushbuttons from the board and update variabels
    
    //update push buttons
    b1 = !button1;
    b2 = !button2;
    b3 = !button3;
    
    acc.readXYZGravity(&ax,&ay,&az); // update accelerometer readings
    
    return;
}
