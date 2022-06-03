/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
 
For more information see http://learn.adafruit.com/photocells */
 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider
#include <LiquidCrystal.h>

int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/**
 * TSH rooms --> 32 is detected without anything --> range [28, 32]
 * --> [6, 10] --> WHITE DISK
 */
// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;


 
void setup(void) {
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
 
void loop(void) {
  lcd.setCursor(0, 1);
  delay(1000);

//  driver(returnphotocell());
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  // We'll have a few threshholds, qualitatively determined
//  if (photocellReading < 10) {
//    Serial.println(" - Dark");
//  } else if (photocellReading < 200) {
//    Serial.println(" - Dim");
//  } else if (photocellReading < 500) {
//    Serial.println(" - Light");
//  } else if (photocellReading < 800) {
//    Serial.println(" - Bright");
//  } else {
//    Serial.println(" - Very bright");
//  }
//  delay(1000);
}

boolean whiteDiskDetected(int photocellReading) { 
  if (photocellReading >= 28 && photocellReading <= 34) {
    return true;
  } else if (photocellReading >= 6 && photocellReading <= 10) {
    return false;
  } else {
    return findOtherColor();
  }
}

int returnphotocell() {
  delay(2000);
  photocellReading = analogRead(photocellPin);
  return photocellReading;
}


boolean findOtherColor() {
  return false;
}

void driver(int photocellReading) {
  boolean photocellBool = whiteDiskDetected(photocellReading);

  if (photocellReading >= 3 && photocellReading <= 6) {
    // then disk is white, run backwards:
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    lcd.print("White disk!");
  } else if(photocellReading >= 0 && photocellReading <= 2) {
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    lcd.print("Black disk!");
  } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      lcd.print("other color detected!");
  }
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  
  // Now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
//void speedControl() {
//  // Turn on motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, HIGH);
//  
//  // Accelerate from zero to maximum speed
//  for (int i = 0; i < 256; i++) {
//    analogWrite(enA, i);
//    analogWrite(enB, i);
//    delay(20);
//  }
//  
//  // Decelerate from maximum speed to zero
//  for (int i = 255; i >= 0; --i) {
//    analogWrite(enA, i);
//    analogWrite(enB, i);
//    delay(20);
//  }
//  
//  // Now turn off motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
//}
