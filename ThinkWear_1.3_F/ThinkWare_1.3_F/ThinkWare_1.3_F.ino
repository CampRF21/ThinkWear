#include <SPI.h>
#include "definitions.h"

SPISettings settingsA(2000000, MSBFIRST, SPI_MODE1);

void setup() {

  Serial.begin(9600);
  pinMode(IPIN_PWDN, OUTPUT);
  pinMode(IPIN_RESET, OUTPUT);
  pinMode(IPIN_DRDY, INPUT);
  pinMode(PIN_SCLK, OUTPUT);

  digitalWrite(IPIN_PWDN, HIGH);
  digitalWrite(IPIN_RESET, HIGH);
  delayMicroseconds(12);
  delay(500);
  SPI.begin();
  SPI.beginTransaction(settingsA);
  digitalWrite(IPIN_CS, LOW);
  init_ThinkWear();
  digitalWrite(IPIN_CS, HIGH);
  SPI.endTransaction();
}

void loop() {
  
  uint8_t Address = 0x00;
  uint8_t Content;
  
  for(int j = 0; j < 18; j++){
    SPI.beginTransaction(settingsA);
    digitalWrite(IPIN_CS, LOW);
    SPI.transfer(RREG | Address);
    //SPI.transfer(0);
    Content = SPI.transfer(0);
    Content = SPI.transfer(0);
    delayMicroseconds(4);
    digitalWrite(IPIN_CS, HIGH);
    SPI.endTransaction();
    
    Serial.print("Register: ");
    Serial.print(Content);
    Serial.print(" ");
    Serial.print(Content, HEX);
    Serial.print("  |  Address = ");
    Serial.print(Address, HEX);
    Serial.print("  |  RREG = ");
    Serial.print(RREG, HEX);
    Serial.print("  |  RREG | Address = ");
    Serial.println((RREG | Address), HEX);
    //delay(1000);
    
    Address = Address + B00000001;
  }
  
  Serial.println(" END");
}
