#include "definitions.h"

void TW_pinInit(){ 
  //pinMode(MISO, INPUT);
  pinMode(IPIN_CS, OUTPUT);
  pinMode(IPIN_DRDY, INPUT);
  //pinMode(MOSI, OUTPUT);
  //pinMode(SCK, OUTPUT);
  pinMode(IPIN_PWDN, OUTPUT);
  pinMode(IPIN_RESET, OUTPUT);
}//end TW_pinInit()

void TW_regInit(){
  byte address = 0x01;
  byte Setup[23] = {0x96, 0xC2, 0x7E, 0x00, 0x52, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
                    0x00};

  for(int n = 0 ; n < 23 ; n++){
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
    digitalWrite(IPIN_CS, LOW);
    SPI.transfer(WREG | address);
    SPI.transfer(0x00);
    SPI.transfer(Setup[n]);
    delayMicroseconds(2);
    digitalWrite(IPIN_CS, HIGH);
    SPI.endTransaction();
    address = address + 0b00000001;
  }//end for
}//end TW_regInit()

