#ifndef ScreenObject_H
#define ScreenObject_H

class ScreenObject {
    
    public:
        ScreenObject(int x, int y); // constructor
        virtual void draw(); // main base class virtual draw function -> draws the object
        virtual void update(); // main base class virtual update function -> updates the position of the object
        void setX(int); // function to set the X coordinate of an object in space
        void setY(int); // function to set the Y coordinate of an object in space
        int getX(); // function to get the X coordinate of an object
        int getY(); // function to get the Y coordinates of an object in space 
    protected:
        int x_pos; // X position of an object. only accessible to derived classes of ScreenObject
        int y_pos; // Y position of an object. only accessible to derived classes of ScreenObject
    
};

#endif