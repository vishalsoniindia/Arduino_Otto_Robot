#include <Otto9.h> //-- Otto Library version 9
Otto9 Otto;  //This is Otto!
//---------------------------------------------------------
// Face should be in front of you
/*
                 --------------- 
                |     O   O     |
                |---------------|
Left leg =>     |               |    <= Right leg
                 --------------- 
                    ||     ||
Left foot =>     -----   ------     <= Right foot
                 |-----   ------|
*/
// SERVO PINs //////////////////////////////////////////////////////////////////////////////
#define PIN_YL 8 //servo[0]  left leg
#define PIN_YR 9 //servo[1]  right leg
#define PIN_RL 10 //servo[2]  left foot
#define PIN_RR 11 //servo[3]  right foot
// ULTRASONIC PINs /////////////////////////////////////////////////////////////////////////
#define PIN_Trigger  2  //TRIGGER pin (2)
#define PIN_Echo     3  //ECHO pin (3)
// BUZZER PIN //////////////////////////////////////////////////////////////////////////////
#define PIN_Buzzer  13 //BUZZER pin (13)
// SERVO ASSEMBLY PIN   /////////////////////////////////////////////////////////////////////
// to help assemble Otto's feet and legs - wire link between pin 7 and GND
#define PIN_ASSEMBLY    7   //ASSEMBLY pin (7) LOW = assembly    HIGH  = normal operation
///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
int distance; // variable to store distance read from ultrasonic range finder module
bool obstacleDetected = false; // logic state for when object detected is at the distance we set
//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movements
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(19200);
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo); //Set the servo pins and ultrasonic pins and Buzzer pin
  pinMode(PIN_ASSEMBLY,INPUT_PULLUP); // - Easy assembly pin - LOW is assembly Mode
  //Otto wake up!
  Otto.sing(S_connection);// Otto makes a sound
  Otto.home(); // Otto moves to its ready position
  delay(500); // wait for 500 milliseconds to allow Otto to stop
// if Pin 7 is LOW then place OTTO's servos in home mode to enable easy assembly, 
// when you have finished assembling Otto, remove the link between pin 7 and GND
  while (digitalRead(PIN_ASSEMBLY) == LOW) {
    Otto.home();// Otto moves to its ready position
    Otto.sing(S_happy_short);   // sing every 5 seconds so we know OTTO is still working
    delay(5000);// wait for 5 seconds
  }
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
 if (obstacleDetected) { // if there is an object closer than 15cm then we do the following
        Otto.sing(S_surprise); // sound a surprise
        Otto.jump(5, 500); // Otto jumps
        Otto.sing(S_cuddly); // sound 
        //Otto takes three steps back
        for (int i = 0; i < 3; i++) Otto.walk(1, 1300, -1); //repeat  three times the walk back command
        delay(50);// small delay to allow Otto to settle
        //Otto turns left 3 steps
        for (int i = 0; i < 3; i++) { //repeat  three times 
            Otto.turn(1, 1000, 1); // the walk left command
            delay(50);// small delay to allow Otto to settle
            obstacleDetector(); 
            }  
          }    
          else { // if nothing in front then walk forward
        Otto.walk(1, 1000, 1); //Otto walk straight
        obstacleDetector(); // call the function to check the ultrasonic range finder for an object closer than 15cm
        }
      
}  
//////////////////////////////////////////////////////////////////////////////////
//-- Function to read distance sensor & to actualize obstacleDetected variable //
/////////////////////////////////////////////////////////////////////////////////
void obstacleDetector() {
  int distance = Otto.getDistance(); // get the distance from the ultrasonic range finder
  if (distance < 15) obstacleDetected = true; // check to see if this distance is closer than 15cm, true if it is
  else obstacleDetected = false;// false if it is not
   Serial.print(distance);
  Serial.println("cm");
 if(distance<15){
          obstacleDetected = true;
          Serial.println ("Obstacle Detected! Avoid collision");
        }else{
          obstacleDetected = false;
          Serial.println ("No Obstacle detected! - Keep on walking");
        }
}
