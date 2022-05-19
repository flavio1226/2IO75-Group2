# @author Group 2
# @created at 09.05.2022
# @purpose connect and work with the L293D arduino motor controller

#importing the needed AMSpi library for controlling the motors
from AMSpi import AMSpi

with AMSpi() as amspi:
    amspi.set_74HC595_pins(21, 20, 16) # set the pins of the 74HC595 motor shield
    asmpi.set_L293D_pins(5, 6, 13, 19) # set the pins of the L293D motor shield
    asmpi.run_dc_motors(asmpi.DC_Motor_1, asmpi.DC_Motor_2, asmpi.DC_Motor_3, asmpi.DC_Motor_4) # make the motors on ports M1, M2, M3, M4 start running at full speed