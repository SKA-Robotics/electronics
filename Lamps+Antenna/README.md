## Short description
This board contains three parts:
- 24V Step-Up/Step-Down voltage regulator
- LED signal tower controller
- POE injector

## Schematic
The full schematic is available at [schematic.pdf](schematic.pdf)

## Pcb layout
Board dimensions: 100m x 80mm

![PCBTraces](Images/PCB%20-%20traces.png)

### 3D view
![Isometric](Images/3D%20view%20-%20isometric.png)
![Top](Images/3D%20view%20-%20top.png)
![Bottom](Images/3D%20view%20-%20bottom.png)
![Side](Images/3D%20view%20-%20side.png)

### Components list
- [CANduino](https://github.com/SKA-Robotics/electronics/tree/main/CANduino)
- [Pololu 24V Step-Up/Step-Down Voltage Regulator](https://www.pololu.com/product/2582)
- [Transistor BC546B](https://www.tme.eu/pl/details/bc546b-dio/tranzystory-npn-tht/diotec-semiconductor/bc546b/)
- [Transformator unsoldered from MikroTik POE injector](https://mikrotik.com/product/RBGPOE)
> In transformator pins 1-2 and 5-6 should be switched respectively before soldering

# Inputs & Outputs

Inputs
-

|Name|Connector|Note|
|-  |-      |-  |
|Power|XT60PW-M|The power connector should be soldered on a different side of the PCB than the rest of the components / voltage 3 V – 30 V (tested 21-29V)|
|CAN|Molex Micro-Fit 3.0|[SKAR CAN connector standard](https://github.com/SKA-Robotics/electronics/tree/main/Manipulator%20Harness#4-pin-connector)|
|USB|USB-C|Used only for CANduino programming and debugging|
|DATA|RJ-45|Data input for antenna ${\color{red}DO\quad NOT\quad CONNECT\quad TO\quad POE}$|

Outputs
-

|Name|Connector|Note|
|-  |-      |-  |
|Lamps|Phoenix 6pins female|Open-collector output for LED signal tower|
|POE|RJ-45|POE output for antenna / 24 V ${\color{red}DO\quad NOT\quad CONNECT\quad TO\quad NON-POE}$|

# Lamps controller - Arduino code
[Arduino code for contolling lamps](lamps.ino)

# Credits
Designed by Selim Mucharski in 2025.