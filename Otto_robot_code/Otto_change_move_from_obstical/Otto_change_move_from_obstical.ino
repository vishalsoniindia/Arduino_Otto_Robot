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
 obstacleDetector();
 
 if(obstacleDetected == true && obstacleFlag ==  true){
   Otto.playGesture(OttoConfused);
  obstacleFlag =  false;
 }

 if(obstacleDetected == false && obstacleFlag ==  false){
  move = random(1,27);
  obstacleFlag =  true;
 }
 
 switch(move){
    case 1:
    Otto.walk(2,1000,1);
    Otto.home();
    move = 0;
    break;
    case 2:
    Otto.walk(2,1000,-1);
    Otto.home();
    move = 0;
    break;
    case 3:
    Otto.turn(2,1000,1);
    Otto.home();
    move = 0;
    break;
    case 4:
    Otto.turn(2,1000,-1);
    Otto.home();
    move = 0;
    break;
    case 5:
    Otto.bend (2,500,1);
    Otto.home();
    move = 0;
    break;
    case 6:
    Otto.bend (2,2000,-1);
    Otto.home();
    move = 0;
    break;
    case 7:
    Otto.shakeLeg (2,1500, 1);
    Otto.home();
    move = 0;
    break;
    case 8:
    Otto.moonwalker(3, 1000, 25,1);
    Otto.home();
    move = 0;
    break;
    case 9:
    Otto.moonwalker(3, 1000, 25,-1);
    Otto.home();
    move = 0;
    break;
    case 10:
    Otto.crusaito(2, 1000, 20,1);
    Otto.home();
    move = 0;
    break;
    case 11:
    Otto.crusaito(2, 1000, 20,-1);
    Otto.home();
    move = 0;
    break;
    case 12:
    Otto.flapping(2, 1000, 20,1);
    Otto.home();
    move = 0;
    break;
    case 13:
    Otto.flapping(2, 1000, 20,-1);
    Otto.home();
    move = 0;
    break;
    case 14:
    Otto.swing(2, 1000, 20);
    Otto.home();
    move = 0;
    break;
    case 15:
     Otto.tiptoeSwing(2, 1000, 20);
    Otto.home();
    move = 0;
    break;
    case 16:
    Otto.jitter(2, 1000, 20); //(small T)
    Otto.home();
    move = 0;
    break;
    case 17:
    Otto.updown(2, 1500, 20);  // 20 = H "HEIGHT of movement"T 
    Otto.home();
    move = 0;
    break;
    case 18:
    Otto.ascendingTurn(2, 1000, 50);
    Otto.home();
    move = 0;
    break;
    case 19:
    Otto.jump(1,500); // It doesn't really jumpl ;P
    Otto.home();
    move = 0;
    break;
    case 20:
    Otto.playGesture(OttoSuperHappy);
    Otto.home();
    move = 0;
    break;
    case 21:
    Otto.playGesture(OttoSad);
    Otto.home();
    move = 0;
    break;
    case 22:
    Otto.playGesture(OttoVictory); 
    Otto.home();
    move = 0;
    break;
    case 23:
    Otto.playGesture(OttoAngry);
    Otto.home();
    move = 0;
    break;
    case 24:
    Otto.playGesture(OttoSleeping);
    Otto.home();
    move = 0;
    break;
    case 25:
    Otto.playGesture(OttoLove);
    Otto.home();
    move = 0;
    break;
    case 26:
    Otto.playGesture(OttoFart);
    Otto.home();
    move = 0;
    break;
    case 27:
    Otto.playGesture(OttoFail);
    Otto.home();
    move = 0;
    break;
 
 }


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
