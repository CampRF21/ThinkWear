#include<SPI.h>
#define WAKEUP  0x02
#define STANDBY 0x04
#define RESET   0x06
#define START   0x08
#define STOP    0x0A
#define RDATAC  0x10
#define SDATAC  0x11
#define RDATA   0x12

const int IPIN_PWDN = 2; //not required for TI demo kit
const int PIN_CLKSEL = 6;//6;//*optional
const int IPIN_RESET  = 3; //*optional
const int PIN_START = 4;
const int IPIN_DRDY = 5;
const int IPIN_CS = 10;//10             ss
const int PIN_DOUT = 11;//SPI out       mosi
const int PIN_DIN = 12;//SPI in         miso
const int PIN_SCLK = 13;//SPI clock     sck

SPISettings settingsA(2000000, MSBFIRST, SPI_MODE1);

void setup() {
  pinMode(IPIN_CS,  OUTPUT);
  pinMode(PIN_DOUT, OUTPUT);
  pinMode(PIN_DIN,  INPUT);
  pinMode(IPIN_DRDY, INPUT);
  pinMode(PIN_SCLK, OUTPUT);
  delay(500);
  SPI.begin();
}

void loop() {
  byte ID_reg;
  int count = 0;
  SPI.beginTransaction(settingsA);
  //send command routine to stop read continous data
  /* digitalWrite(IPIN_CS, LOW);
    SPI.transfer(SDATAC);
    delayMicroseconds(2);
    digitalWrite(IPIN_CS, HIGH);*/
  //--------------------------------------------------
  digitalWrite(IPIN_CS, LOW);
  SPI.transfer(RESET);
  delayMicroseconds(5);
  digitalWrite(IPIN_CS, HIGH);
  delay(5);
   digitalWrite(IPIN_CS, LOW);
  SPI.transfer(SDATAC);
  SPI.transfer(0x43);
  SPI.transfer(0x00);
  SPI.transfer(B11000111);
  delayMicroseconds(5);
  digitalWrite(IPIN_CS, HIGH);
  delay(5);
  digitalWrite(IPIN_CS, LOW);
  SPI.transfer(SDATAC);
  SPI.transfer(0x20);
  SPI.transfer(0x00);
  delayMicroseconds(5);
  digitalWrite(IPIN_CS, HIGH);
  ID_reg = SPI.transfer(PIN_DIN);
  digitalWrite(IPIN_CS, HIGH);
  SPI.endTransaction();
  Serial.begin(9600);
  Serial.println(ID_reg,BIN);
  delay(100);
}
