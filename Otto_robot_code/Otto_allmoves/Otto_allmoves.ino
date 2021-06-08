//----------------------------------------------------------------
//-- Otto All move test
// *******************************************************************/
//-----------------------------------------------------------------
#include <Otto9.h>
Otto9 Otto;  //This is Otto!
//----------------------------------------------------------------------
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


#define PIN_YL 8 //Left leg
#define PIN_YR 9 //Right leg
#define PIN_RL 10 //Left foot
#define PIN_RR 11 //Right foot
#define PIN_Trigger  2  //TRIGGER pin
#define PIN_Echo     3  //ECHO pin
#define PIN_Buzzer  13  //BUZZER pin

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo); //Set the servo pins and ultrasonic pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();
    delay(50);
  Otto.playGesture(OttoHappy);
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() { 
  Otto.walk(2,1000,1); //2 steps, "TIME". IF HIGHER THE VALUE THEN SLOWER (from 600 to 1400), 1 FORWARD
  Otto.walk(2,1000,-1); //2 steps, T, -1 BACKWARD 
  Otto.turn(2,1000,1);//3 steps turning LEFT
  Otto._tone(10, 3, 1);
  Otto.bendTones (100, 200, 1.04, 10, 10);
    Otto.home();
    delay(100);  
  Otto.turn(2,1000,-1);//3 steps turning RIGHT 
  Otto.bend (1,500,1); //usually steps =1, T=2000
  Otto.bend (1,2000,-1);     
  Otto.shakeLeg (1,1500, 1);
    Otto.home();
    delay(100);
  Otto.shakeLeg (1,2000,-1);
  Otto.moonwalker(3, 1000, 25,1); //LEFT
  Otto.moonwalker(3, 1000, 25,-1); //RIGHT  
  Otto.crusaito(2, 1000, 20,1);
  Otto.crusaito(2, 1000, 20,-1);
    delay(100); 
  Otto.flapping(2, 1000, 20,1);
  Otto.flapping(2, 1000, 20,-1);
    delay(100);        
  Otto.swing(2, 1000, 20);
  Otto.tiptoeSwing(2, 1000, 20);
  Otto.jitter(2, 1000, 20); //(small T)
  Otto.updown(2, 1500, 20);  // 20 = H "HEIGHT of movement"T 
  Otto.ascendingTurn(2, 1000, 50);
  Otto.jump(1,500); // It doesn't really jumpl ;P
  Otto.home();
     delay(100); 
  Otto.sing(S_cuddly);
  Otto.sing(S_OhOoh);
  Otto.sing(S_OhOoh2);
  Otto.sing(S_surprise);
  Otto.sing(S_buttonPushed);       
  Otto.sing(S_mode1);        
  Otto.sing(S_mode2);         
  Otto.sing(S_mode3);  
  Otto.sing(S_sleeping);
  Otto.sing(S_fart1);
  Otto.sing(S_fart2);
  Otto.sing(S_fart3);
  Otto.sing(S_happy);
  Otto.sing(S_happy_short);                   
  Otto.sing(S_superHappy);   
  Otto.sing(S_sad);               
  Otto.sing(S_confused);
  Otto.sing(S_disconnection);
    delay(100);  
  Otto.playGesture(OttoHappy);
  Otto.playGesture(OttoSuperHappy);
  Otto.playGesture(OttoSad);
  Otto.playGesture(OttoVictory); 
  Otto.playGesture(OttoAngry); 
  Otto.playGesture(OttoSleeping);
  Otto.playGesture(OttoFretful);
  Otto.playGesture(OttoLove);
  Otto.playGesture(OttoConfused);        
  Otto.playGesture(OttoFart);
  Otto.playGesture(OttoWave);
  Otto.playGesture(OttoMagic);
  Otto.playGesture(OttoFail);
    Otto.home();
    delay(100);  
}
