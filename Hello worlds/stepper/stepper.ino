#include <Stepper.h>
 
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

const int VERT = A0; // analog
const int HORIZ = A1; // analog

Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
 
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened

  Serial.begin(9600);
  motor.setSpeed(50);
}
 
void loop()
{
   
  int vertical = analogRead(VERT); // will be 0-1023
  Serial.println(vertical);
  
  motor.step(map(vertical, 0, 1023, -20, 20));
  delay(10);
  
}
