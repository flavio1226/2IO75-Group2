/**
 * @file dc_motor.ino
 * @author Group 2
 * @brief make an LCD display work
 * @version 0.1
 * @date 2022-05-4
 */

// include the library code
#include <LiquidCrystal.h>

// declare the object lcd with the needed ports
LiquidCrystal lcd(11, 12, 5, 4, 3, 2);

/**
 * @brief setup function
 * @param none
 * @details this function only runs once at the start of the program.
 */
void setup() {
  lcd.begin(16, 2); // LCD parameters here
  lcd.setCursor(0,1); // set the text alignment                   
  lcd.print("it works!"); // actual text to display

} 

/**
 * @brief setup function
 * @param none
 * @details this function runs continuously untill the end of the program.
 */
void loop() {
}
