# Battery Module

## Overview
This PCB was created as an upgraded version of the battery module. It has 3 Phoenix and 1 XT60 connectors to combine power from up to 3 separate battery packs into a single power source. There are 2 available places for the XT60 connector.

In addition, the board includes an ATMEGA328P-AU microcontroller (Arduino Uno compatible) and an ADS1110A0IDBVT Analog-to-Digital Converter. These components work together to calculate the remaining battery charge, which can be displayed via an I²C-compatible display.

## Schematic
The board schematic in pdf is [here](schematic.pdf).

## Datasheets
Here are datasheets of the most important elements of the board.
- [Microcontroller ATMEGA328P-AU](https://www.mouser.pl/datasheet/2/268/Atmel_7810_Automotive_Microcontrollers_ATmega328P_-3499768.pdf)
- [ADC ADS1110A0IDBVT](https://www.ti.com/lit/ds/symlink/ads1110.pdf?ts=1750930148220)
- [Voltage Regulator TLE7274-2D](https://www.mouser.pl/datasheet/2/196/Infineon_TLE7274_2D_DataSheet_v01_02_EN-3360369.pdf)
## PCB Layout
![PCB_Layout](Images/PDB_traces.png)
## PCB Dimensions
![PCB_Dimensions](Images/PCB-dimensions.png)
## 3D View
![3D_top](Images/3D_view-top.png)

![3D_btm](Images/3D_view-bottom.png)

![3D_side](Images/3D_view-side.png)

![3D_isometric](Images/3D_view-isometric.png)
## Pinout (view from logo side)
### ICSP
| GND   | MOSI  | +5V   |
|-------|-------|-------|
| MISO  | SCK   | RESET |

### UART
| +5V   | GND   | RX    | TX    | 
|-------|-------|-------|-------|

### Display
| +5V   | GND   | SCL   | SDA   |
|-------|-------|-------|-------|

![Pinouts](Images/pinout.png)

## How to programm the board?
Since the board lacks a USB port, it must be programmed via ICSP. This means it does not require a bootloader.
1. Use an Arduino Uno as the programmer. Connect it to your computer and open the Arduino IDE.
  Go to _Tools_ > _Board_ and select Arduino Uno.
  Also set the correct Port.
2. From _File_ > _Examples_ > _11.ArduinoISP_, open and upload the ArduinoISP sketch to the Uno.
3. Select _Tools_ > _Programmer_ > _Arduino as ISP_.
4. Use jumper wires to connect the ICSP headers of the Arduino Uno and the Battery Module.
  > [!WARNING]
  > Refer to the pinout above!
    The ICSP header on the Battery Module is not identical to the one on the Uno.
    Also, connect the RESET pin of the Battery Module to pin 10 of the Arduino Uno.
5. With the Battery Module connected via ICSP, you can upload your code.
  > [!WARNING]
  > Do not use the regular _Upload_ button. Instead, go to _Sketch_ > _Upload Using Programmer_ (or use Ctrl+Shift+U).
 
## Example code
```cpp
#include "Wire.h"
#define ads1110 0x48  // ADS1110 I2C address
# include "DFRobot_LedDisplayModule.h"

float voltage, data;
byte highbyte, lowbyte, configRegister;

DFRobot_LedDisplayModule LED(&Wire, 0x48);

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(2000);
}

void loop()
{
  // Uśrednianie 1000 próbek - mniejsze wahania pomiaru
  for (int i = 0; i < 1000; i++) {
    // Request 3 bytes of data from the ADS1110
    Wire.requestFrom(0x48, 3);
    // delay(1000);
    while (Wire.available() >= 3)  // Wait for all 3 bytes
    {
      highbyte = Wire.read();      // High byte
      lowbyte = Wire.read();       // Low byte
      configRegister = Wire.read(); // Config register (not used here)
    }

    // Combine high and low bytes into a 16-bit signed integer
    data += (highbyte << 8) | lowbyte;
    if (data > 32767)  // Handle negative values (2's complement)
      data -= 65536;

  data /= 1000;

  // Convert raw data to voltage
  voltage = data * 5.064 / 1023;
  voltage = voltage * 16;


  voltage = min(29, max(21, voltage));
  x = voltage;
  // super-duper-ultra dokladny wielomian krzywej rozladowania identified by Adam Jeliński <3
  energy = (((((0.0260984200553441 * x - 3.66634249899684) * x + 213.880338245982) * x - 6631.91686689481) * x + 115288.063675547) * x - 1065412.12837601) * x + 4089490.76690438;
  
  energy = min(250, max(0, energy));

  int percent = lround(energy / 2.5);
  // Print results
  Serial.print("Raw Data >> ");
  Serial.println(data);
  Serial.print("Battery Voltage >> ");
  Serial.print(voltage, 4);  // Print with 4 decimal places
  Serial.println(" V");


  LED.print(percent);
  delay(500);
  //LED.print(voltage);

}
```

## Credits
- Designed by Piotr Kozłowski
- Substantive support by Michał Gołąb
- Graphics by Tomasz Żebrowski
