
/*
 * @author Group02
 * @course 2IO75
 * @date 03-06-2022
 * @desc driver class for the embedded system of the course 2IO75
 */

#include <LiquidCrystal.h>

// photocell constants
int photocellPin = 0; // the photocell is situated at analog port zero
int photocellReading; // the analog reading from the analog resistor divider
int colorSensorValue = 0; // initial color sensor value
int colorSensorMinValue = 1023; // min color sensor value
int colorSensorMaxValue = 0; // max color sensor value


// led constants
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // ports needed by the LCD display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // declaration of the object lcd, an 8 x 2 LCD display


// motor constants

// Motor A connections
int enA = 9; // power of motor A
int in1 = 8; // first wire of motor A
int in2 = 7; // second wire of motor A

// Motor B connections
int enB = 3; // power of motor B
int in3 = 5; // first wire of motor B
int in4 = 4; // second wire of motor B

void setup() {
  setupMotors(); // setup motors
  calibrateLightSensor(); // calibrate light sensor
  startDisplay(); // turn on the LCD display
}

void loop() {
  // start driver function
  driver();
}

/**
 * @desc function that starts the LCD display
 * @param none
 */
void startDisplay() {
  lcd.begin(16, 2); // begin LCD display on all 16 ports
  lcd.print("Booting up"); // print the simple message
  lcd.blink(); // LCD display now blinks
  delay(2000); // for 2 seconds
}

/**
 * @desc function that calibrates the light sensor to the conditions of light present in the environment
 * @param none
 */
void calibrateLightSensor() {
    while (millis() < 3000) {
      colorSensorValue = analogRead(photocellPin);

    // record the maximum sensor value
    if (colorSensorValue > colorSensorMaxValue) {
      colorSensorMaxValue = colorSensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < colorSensorMinValue) {
        colorSensorMinValue = colorSensorValue;
      }
    }
  }
}


/**
 * @desc function that sets all the motor control pins to output and sets the initial power to zero
 * @param none
 */
void setupMotors() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}


/**
 * @desc function that starts the belt motor
 * @param direction
 * @direction = 0 --> run backwards
 * @direction = 1 --> run forwards
 */
void startBeltMotor(boolean direction) {
  if (direction) {
    analogWrite(enA, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  
  } else {
    analogWrite(enA, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
}

/**
 * @desc function that starts the push off mechanism motor
 * @param none
 */
void startPushMotor() {
    analogWrite(enB, 255);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}


/**
 * @desc function that detects the color of the disk
 * @param photocellReading --> light intensity detected by the color sensor
 */
String detectDisk(int photocellReading) {
  int lowerRangeWhiteDisk = 0; // TODO change this value
  int upperRangeWhiteDisk = 0; // TODO change this value
  int lowerRangeBlackDisk = 0; // TODO change this value
  int upperRangeBlackDisk = 0; // TODO change this value
  if (photocellReading >= lowerRangeWhiteDisk && photocellReading <= upperRangeWhiteDisk) {
    return "White Disk";
  } else if (photocellReading >= lowerRangeBlackDisk && photocellReading <= upperRangeBlackDisk) {
    return "Black Disk";
  } else {
    return "Other Color";
  }
}

/**
 * @desc function that displays text on the LCD screen
 * @param string to be printed
 */
void displayLCD(String message) {
  lcd.print(message);
}

/**
 * @desc logical main function of the program
 * @param none
 */
void driver() {
  String diskColor = detectDisk(photocellReading);
  switch (diskColor) {
    case "White Disk":
      startBeltMotor(true);
      displayLCD(diskColor);
      break;
    case "Black Disk":
      startBeltMotor(false);
      displayLCD(diskColor);
      break;
    default:
      displayLCD(diskColor);
      break;
  }
}
