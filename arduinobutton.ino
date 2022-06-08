/*
  Button - Arduino 

  This prints messages in the serial monitor. Can be used later for turning on and off the motors. 

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  13;      // the number of the LED pin - uncomment if necessary

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  // pinMode(ledPin, OUTPUT); // uncomment if necessary
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    // digitalWrite(ledPin, HIGH);
    Serial.println("HIGH"); 
  } else {
    // turn LED off:
    // digitalWrite(ledPin, LOW);
    Serial.println("LOW");
  }
}
