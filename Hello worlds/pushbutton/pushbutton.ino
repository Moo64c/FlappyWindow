/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int state = LOW;  
boolean wait = false;
int amount = 5;
int brightness = 0; 

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (!wait && buttonState == 1) {
    if (state == LOW) {
      state = HIGH;
    }
    else {
      state = LOW;
    }
    fade();
    wait = true;
  }
  else {
    wait = false;
  } 
  delay(1);        // delay in between reads for stability
}

void fade() {
  
  // set the brightness of pin 9:
  analogWrite(led, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + amount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness <= 0 || brightness >= 255) {
    amount = -amount ; 
  }
  delay(30);
}
