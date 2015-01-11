#include <Servo.h> 

#define DIR_PIN 2
#define STEP_PIN 3
#define SERVO_PIN 9

Servo pendulumSwinger;  // create servo object to control a servo 
float pos = 0;    // variable to store the servo position
float delayTime = 0;
int delayHigh = 20;

void setup() {
  Serial.begin(57600); 
  //  pinMode(DIR_PIN, OUTPUT); 
  //  pinMode(STEP_PIN, OUTPUT);
  //  digitalWrite(DIR_PIN, LOW);
  //  digitalWrite(STEP_PIN, LOW);
  pendulumSwinger.attach(9);

} 

void loop(){ 
  //rotate(3200, .1);
  swingPendulum();
  //  digitalWrite(STEP_PIN, HIGH);
  //  delay(135);
  //  digitalWrite(STEP_PIN, LOW);
  //  delay(135);

}

void swingPendulum() {

  for(pos = 0; pos <= 180; pos += 1)  
  {                                  
    pendulumSwinger.write(pos);
    delay(sin(delayTime) * 15);
    delayTime = float(pos);
    delayTime = map(delayTime, 0.0, 180, 0.0, PI);
    Serial.print("delayTime = ");
    Serial.println(delayTime);
    Serial.print("pos = ");
    Serial.println(pos);    
  }


  //  FUNCTIONING BUT NOT VERY CLEAN 
  //  delay(delayHigh);
  //  for(pos = 0; pos < 90; pos += 1)  
  //  {                                  
  //    pendulumSwinger.write(pos);
  //    delay(map(pos, 0, 89, delayHigh, 0));                
  //  }
  //  for(pos = 90; pos < 180 ; pos += 1)  
  //  {                                  
  //    pendulumSwinger.write(pos);
  //    delay(map(pos, 90, 179, 1, delayHigh));                
  //  }
  //  delay(delayHigh);
  //  for(pos = 180; pos > 90; pos -= 1)  
  //  {                                  
  //    pendulumSwinger.write(pos);
  //    delay(map(pos, 180, 91, delayHigh, 0));                
  //  }
  //  for(pos = 90; pos >= 1; pos -= 1)  
  //  {                                  
  //    pendulumSwinger.write(pos);
  //    delay(map(pos, 90, 1, 0, delayHigh));                
  //  }
}


void rotate(int steps, float speed){ 
  //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);

  digitalWrite(DIR_PIN,dir); 

  float usDelay = (1/speed) * 70;
  Serial.println(usDelay);
  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(6750); 

    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(6750); 
  } 
} 












