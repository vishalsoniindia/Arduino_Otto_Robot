

#include <Servo.h>

Servo servo1,servo2;  

int pos = 90;    // variable to store the servo position

void setup() {
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    servo2.write(pos);

                  
}
