

#include <Servo.h>

Servo Lefttop,Righttop,Leftbottom,Rightbottom;

// Face should be in front of you
/*
                 --------------- 
                |     O   O     |
                |---------------|
Lefttop =>      |               |    <= Righttop
                 --------------- 
                    ||     ||
Leftbottom =>     -----   ------     <= Rightbottom
                 |-----   ------|
*/

int pos = 90;    // variable to store the servo position
//make sure all motors are at 90 degree


void setup() {
  Lefttop.attach(8);  // attaches the servo on pin 8 to the servo object
  Righttop.attach(9);  // attaches the servo on pin 9 to the servo object
  Leftbottom.attach(10);  // attaches the servo on pin 10 to the servo object
  Rightbottom.attach(11);  // attaches the servo on pin 11 to the servo object
}

void loop() {
  
    Lefttop.write(pos);           
    Righttop.write(pos);              
    Leftbottom.write(pos);              
    Rightbottom.write(pos);              
}
