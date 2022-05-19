/**
 * @file dc_motor.ino
 * @author Group 2
 * @brief make a DCMotor work
 * @version 0.1
 * @date 2022-05-2
 */

// include the needed library --> AdaFruit Motor
#include <AFMotor.h>

AF_DCMotor motor(1);

/**
 * @brief setup function
 * @param none
 * @details this function only runs once at the start of the program.
 */
void setup() {
    // set initial dcmotor speed to 200 and direction RELEASE
    motor.setSpeed(200);
    motor.run(RELEASE);
}

/**
 * @brief setup function
 * @param none
 * @details this function runs continuously untill the end of the program.
 */
void loop() {
    // stop motor
    motor.setSpeed(0);
    // make the motor run BACKWARD
    motor.run(BACKWARD);
    // delay for 5000 ms == 5 s
    delay(5000);
    // make the motor run FORWARD
    motor.run(FORWARD);
    // set the new power
    motor.setSpeed(200);
}
