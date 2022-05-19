/**
 * @file dc_motor.ino
 * @author Group 2
 * @brief make a 2 photoresistor with leds work
 * @version 0.1
 * @date 2022-05-8
 */

// declare the red led pin 
int redLED = 7;
// declare the blue led pin
int blueLED = 8;
// declare the photoresistor pin (analogue pin)
int photoresistorPIN = A0;
// initial light value detected by the color sensor
int lightValue = 0;

/**
 * @brief setup function
 * @param none
 * @details this function only runs once at the start of the program.
 */
void setup() {
    // start the leds on port 7 and 8
    pinMode(redLED, OUTPUT);
    pinMode(blueLED,OUTPUT);
    // start console with 9600 ms updates
    Serial.begin(9600);
}

/**
 * @brief setup function
 * @param none
 * @details this function runs continuously untill the end of the program.
 */
void loop(){
    // read the initial light value from the photoresistor PIN
    lightValue = analogRead(photoresistorPIN);
    Serial.println("Light value: ");
    Serial.println(lightValue);
    // check for light value less than 50, then red led
    if(lightValue < 50) {
        digitalWrite(redLED, HIGH);
    }
    // else, blue led
    else {
        digitalWrite(blueLED, HIGH);
    }

    // delay for 0.2 seconds
    delay(200);

    // close the LEDs
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
}
