#include <SPI.h>

const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;

#include <mcp2515.h>
MCP2515 CAN(SPI_CS_PIN); // Set CS pin
struct can_frame canMsg;

#define BLUE_LAMP 2
#define GREEN_LAMP 3
#define YELLOW_LAMP 0
#define RED_LAMP 1
#define BUZZER 4

const uint8_t canId = 0x32;

const long int timeout_time = 3000;
long int latestCommandTime = 0;
bool isTimedOut = true;

const uint32_t canMask = 0b111111 << 5;

void setup() {
    Serial.begin(9600);
    // while(!Serial);

    pinMode(BLUE_LAMP, OUTPUT);
    pinMode(GREEN_LAMP, OUTPUT);
    pinMode(RED_LAMP, OUTPUT);
    pinMode(YELLOW_LAMP, OUTPUT);
    pinMode(BUZZER, OUTPUT);
  
    while (!(CAN.reset() == MCP2515::ERROR_OK
          && CAN.setBitrate(CAN_1000KBPS, MCP_16MHZ) == MCP2515::ERROR_OK
          && CAN.setNormalMode() == MCP2515::ERROR_OK
        )) {

        digitalWrite(RED_LAMP, HIGH);
        digitalWrite(BUZZER, HIGH);
        delay(200);
        digitalWrite(BUZZER, HIGH);
        delay(1000);
        Serial.println("CAN ERROR");
    }

    Serial.println("CAN OK");

    digitalWrite(RED_LAMP, LOW);
    digitalWrite(GREEN_LAMP, LOW);
    digitalWrite(YELLOW_LAMP, LOW);
    digitalWrite(BLUE_LAMP, LOW);
    
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
}

    
void loop() {
    uint8_t result = CAN.readMessage(&canMsg);
    if (result == MCP2515::ERROR_OK) {
      // Serial.println("Heard msg");
      if ((canMsg.can_id >> 5) == canId) {
          if ((canMsg.can_id & 0b11111) == 0x0) {
              isTimedOut = false;
              latestCommandTime = millis();  
              Serial.println("Got msg");
              digitalWrite(BUZZER, canMsg.data[4]);
              digitalWrite(RED_LAMP, canMsg.data[3]);
              digitalWrite(YELLOW_LAMP, canMsg.data[2]);
              digitalWrite(GREEN_LAMP, canMsg.data[1]);
              digitalWrite(BLUE_LAMP, canMsg.data[0]);
              Serial.print(canMsg.data[4]);
              Serial.print(canMsg.data[3]);
              Serial.print(canMsg.data[2]);
              Serial.print(canMsg.data[1]);
              Serial.print(canMsg.data[0]);
              Serial.println();
          }
      }  
    }
    if (latestCommandTime + timeout_time < millis()) {
      if (!isTimedOut) {
        Serial.println("Timeout");
        digitalWrite(RED_LAMP, 0);
        digitalWrite(YELLOW_LAMP, 0);
        digitalWrite(GREEN_LAMP, 0);
        digitalWrite(BLUE_LAMP, 0);
        digitalWrite(BUZZER, 1);
        delay(500);
        digitalWrite(BUZZER, 0);
      }
      isTimedOut = true;
    }
}
