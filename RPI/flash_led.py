# @author Group 2
# @created at 02.05.2022
# @purpose make a simple LED flash

# importing the needed RPi library
import RPi.GPIO as GPIO
from time import sleep # needed for the function sleep

# initial setup for the raspberry pi pins
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(18, GPIO.OUT) # select port 18 for the shorter leg of the LED

print("LED is now flashing....")
GPIO.output(18, GPIO.HIGH) # make the LED on port 18 flash at its highest brightness
sleep(1) # delay the program by 1 second
print("LED is now off...")
GPIO.output(18, GPIO.LOW) # make the LED on port 18 stop flashing.