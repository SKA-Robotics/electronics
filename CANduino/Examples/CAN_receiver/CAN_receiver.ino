#include <SPI.h>

const int CAN_INT_PIN = 2;

#include <mcp2515.h>
MCP2515 CAN(10);
struct can_frame canMsg;

const uint8_t canId = 0x70; // TU USTAWIAMY CAN ID

void setup() {
    Serial.begin(9600);
    while(!Serial); // ZAKOMENTUJ JEŻELI NIE DEBUGUJESZ PRZEZ USB
  
    while (!(CAN.reset() == MCP2515::ERROR_OK
          && CAN.setBitrate(CAN_1000KBPS, MCP_16MHZ) == MCP2515::ERROR_OK
          && CAN.setNormalMode() == MCP2515::ERROR_OK )) {

        // OBSŁUGA BŁĘDU INICJALIZACJI KOMUNIKACJI CAN
        Serial.println("CAN ERROR");
    }

    Serial.println("CAN OK");
}

    
void loop() {
    if (CAN.readMessage(&canMsg) == MCP2515::ERROR_OK) {
      if ((canMsg.can_id >> 5) == canId && (canMsg.can_id & 0b11111) == 0x0) {
          // OBSŁUGA ODBIORU DANYCH

          Serial.print("Got ");
          Serial.print(canMsg.can_dlc);
          Serial.print("bytes: ");

          for (int i = 0; i<canMsg.can_dlc; i++)  {
            Serial.print(canMsg.data[i],HEX);
            Serial.print(" ");
          }
        
          Serial.println();

      }  
    }
}
