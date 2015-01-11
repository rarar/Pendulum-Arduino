#include <Servo.h> 

#define SERVO_PIN 9
#define RAD2GRAD 57.295779513

Servo pendulumSwinger;  // create servo object to control a servo 
float  angle = 0;
float  sen = 0;
float degree = 0;

void setup() {
  Serial.begin(57600); 

  pendulumSwinger.attach(9);

} 

void loop(){ 

  swingPendulum();

}

void swingPendulum() {
  for (int i = 0; i < 360; i++) {
    angle = i;
    sen = sin((angle/RAD2GRAD));
    Serial.print("sin of angle = ");
    Serial.println(sen);
    degree = ((sen * 80) + 90);
    Serial.print("degree of angle = ");
    Serial.println(degree);
    pendulumSwinger.write(degree);
  }

}






