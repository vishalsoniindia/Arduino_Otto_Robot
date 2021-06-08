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
///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
int distance; // variable to store distance read from ultrasonic range finder module
bool obstacleDetected = false; // logic state for when object detected is at the distance we set
bool obstacleFlag = true; 
//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movements
int move = 0;
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(19200);
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo); //Set the servo pins and ultrasonic pins and Buzzer pin
  //Otto wake up!
  Otto.sing(S_connection);// Otto makes a sound
  Otto.home(); // Otto moves to its ready position
  delay(500); // wait for 500 milliseconds to allow Otto to stop
}

void loop() {
//  Otto.playGesture(OttoHappy);
//  Otto.playGesture(OttoSuperHappy);
//  Otto.playGesture(OttoSad);
//  Otto.playGesture(OttoVictory); 
//  Otto.playGesture(OttoAngry); 
//  Otto.playGesture(OttoSleeping);
//  Otto.playGesture(OttoFretful);
//  Otto.playGesture(OttoLove);
//  Otto.playGesture(OttoConfused);        
  Otto.playGesture(OttoFart);
//  Otto.playGesture(OttoWave);
//  Otto.playGesture(OttoMagic);
//  Otto.playGesture(OttoFail);
    Otto.home();
  delay(500); // wait for 500 milliseconds to allow Otto to stop
}

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
