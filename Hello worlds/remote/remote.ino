
#include <IRremote.h>

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int RECV_PIN = 2;
int lastAction = -1;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

void loop() {

  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
    translate(results.value);
    if (lastAction == 1) {
      digitalWrite(led, HIGH);
    }
    else if (lastAction == 2) {
       digitalWrite(led, LOW);
    }
  }
}

void translate(int value) {
  // Maps YES remotes' volume up/down.
  switch (value) {
    case 557606043:
      lastAction = 1;
      break;
      case 557638683:
      lastAction = 2;
      break;
  } 
}
