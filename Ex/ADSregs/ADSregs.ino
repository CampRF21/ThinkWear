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

int n = 0;

void setup() {

  pinMode(PIN_CS, OUTPUT);
  pinMode(PIN_START, OUTPUT);
  pinMode(PIN_PWDN, OUTPUT);
  pinMode(PIN_DIN, INPUT);
  pinMode(PIN_DOUT, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  digitalWrite(PIN_PWDN, HIGH);
  digitalWrite(PIN_RESET, HIGH);
  digitalWrite(PIN_START, LOW);
  Serial.begin(9600);
  SPI.begin();
  delay(500);

  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  digitalWrite(PIN_CS, LOW);
  delayMicroseconds(4);
  SPI.transfer(SDATAC);
  delayMicroseconds(4);
  SPI.transfer(RESET);
  delayMicroseconds(20);
  digitalWrite(PIN_CS, HIGH);
  SPI.endTransaction();

}

void loop() {
  uint8_t reg;
  uint8_t reg_c;
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
  digitalWrite(PIN_CS, LOW);
  delayMicroseconds(4);
  //SPI.transfer(SDATAC);
  SPI.transfer(0x41);
  delayMicroseconds(4);
  SPI.transfer(0x00);
  delayMicroseconds(4);
  SPI.transfer(B10010110);
  delayMicroseconds(4);
  SPI.transfer(0x21);
  delayMicroseconds(4);
  SPI.transfer(0x00);
  delayMicroseconds(4);
  reg_c = SPI.transfer(0);
  delayMicroseconds(10);
  digitalWrite(PIN_CS, HIGH);
  SPI.endTransaction();

  Serial.println(reg_c, BIN);
  delay(100);
}
