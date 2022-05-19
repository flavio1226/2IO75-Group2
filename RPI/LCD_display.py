# @author Group 2
# @created at 02.05.2022
# @purpose make the LCD display work for the extra challenge

# import the needed library RPi.GPIO
import RPi.GPIO as GPIO
# import the needed library to make the LCD display work
from RPLCD.gpio import CharLCD

GPIO.setwarnings(False) # we do not need any warnings

# declaring the lcd objects with the required pins
# we are working with an 8 x 2 LCD display (16 pins)
lcd = CharLCD(pin_rs = 15, pin_rw = 18, pin_e=16, pins_data=[21, 22, 23, 24],
            numbering_mode = GPIO.BOARD, cols = 16, ros = 2, dotsize = 8)

lcd.clear() # clear any text that was present before printing something else

lcd.write_string("Current state of the machine: idle") # initial state of the embedded system written on the LCD display
