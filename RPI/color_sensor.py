# @author Group 2
# @created at 02.05.2022
# @purpose make a simulation for the color sensor that we will need later 

# import the needed library gpiozero
# @cloned from https://github.com/raspberrypilearning/physical-computing-with-python/blob/master/ldr.md
from gpiozero import LightSensor

ldr = LightSensor(18) # the light sensor is present on port 18 on the raspberry pi

while True:
    print(ldr.value) # this value will represent the level of brightness that the phototransistor given in the kit will absorb