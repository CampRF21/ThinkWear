#include<SPI.h>
#define WAKEUP  0x02
#define STANDBY 0x04
#define RESET   0x06
#define START   0x08
#define STOP    0x0A
#define RDATAC  0x10
#define SDATAC  0x11
#define RDATA   0x12

const int PIN_PWDN = 7; //not required for TI demo kit
const int PIN_CLKSEL = 5;//6;//*optional
const int PIN_RESET  = 9; //*optional
const int PIN_START = 6;
const int PIN_DRDY = 8;
const int PIN_CS = 10;//10             ss
const int PIN_DOUT = 11;//SPI out       mosi
const int PIN_DIN = 12;//SPI in         miso
const int PIN_SCLK = 13;//SPI clock     sck



void setup() {
  SPI.begin();
  delay(500);
  
}

void loop() {
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
  SPI.transfer(0x41);
  SPI.transfer(B11110000);
  SPI.endTransaction();
  delay(1000);
  
}
