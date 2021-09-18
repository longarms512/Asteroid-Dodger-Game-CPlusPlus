#ifndef HARDWARE_H
#define HARDWARE_H


class GameInputs {
    public:
        GameInputs();
        void read_inputs(); // update the variables from the board
        
        int b1, b2, b3;     // Button presses
        double ax, ay, az;  // Accelerometer readings
};





#endif // HARDWARE_H