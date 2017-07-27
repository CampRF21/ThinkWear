#include "definitions.h"

 uint8_t Address = 0x00;
 uint32_t Content;

void setup() {

  Serial.begin(9600);
  SPI.begin();
  TW_pinInit();
  digitalWrite(IPIN_PWDN, HIGH);
  digitalWrite(IPIN_RESET, HIGH);
  delay(100);
  digitalWrite(IPIN_CS, HIGH);
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
  
  digitalWrite(IPIN_RESET, LOW);
  digitalWrite(IPIN_RESET, HIGH);
  delay(1);
  
  digitalWrite(IPIN_CS, LOW);
  SPI.transfer(SDATAC);
  delayMicroseconds(2);
  digitalWrite(IPIN_CS, HIGH);
  SPI.endTransaction();
  delay(500);
  TW_regInit();

}

void loop() {
 
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
  byte add = RREG | Address;
  digitalWrite(IPIN_CS, LOW);
  Content = SPI.transfer(add);
  SPI.transfer(0);
  //Content = SPI.transfer(0);
  delayMicroseconds(2);
  digitalWrite(IPIN_CS, HIGH);
  SPI.endTransaction();

  if(Address == 23)
    Address = 0;
  
  Serial.print("\t");
  Serial.print("Register: ");
  Serial.print(Content, BIN);
  Serial.print("  |  Address = ");
  Serial.println(Address, HEX);
  Address = Address + B00000001;
  delay(500);

}
