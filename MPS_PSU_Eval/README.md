# MPS PD power supply evaluation board
This is an evaluation board for MPS power delivery supply for main computer

# Overview
This board uses *MP5031* as a PD controller and *MP2491* as a step-down converter. Input voltage range is between 4-32V, and top power is 100W.
To achieve 100W PD, an external microcontroller with I2C is needed to set the registers.
The main goal of this board is to evaluate its performance as a power supply replacement, with higher stability and higher working temperature.
Components are placed on one side only, making the other side suitable for radiator placement.

# Pinout
This board uses XT60 as input and USB C as output, with additional 6 pin header for I2C and other controls.

# Pictures
![Screenshot](Images/Top.png)
![Screenshot](Images/Dimensions.png)

# Test results
TBD
