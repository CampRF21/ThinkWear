#include<SPI.h>
#define WAKEUP  0x02
#define STANDBY 0x04
#define RESET   0x06
#define START   0x08
#define STOP    0x0A
#define RDATAC  0x10
#define SDATAC  0x11
#define RDATA   0x12

const int IPIN_PWDN = 6; //not required for TI demo kit
const int PIN_CLKSEL = 5;//6;//*optional
const int IPIN_RESET  = 9; //*optional
const int PIN_START = 7;
const int IPIN_DRDY = 8;
const int IPIN_CS = 10;//10             ss
const int PIN_DOUT = 11;//SPI out       mosi
const int PIN_DIN = 12;//SPI in         miso
const int PIN_SCLK = 13;//SPI clock     sck

SPISettings settingsA(2000000, MSBFIRST, SPI_MODE1);


void setup() {
  Serial.begin(9600);
  pinMode(IPIN_CS,  OUTPUT);
  pinMode(PIN_DOUT, OUTPUT);
  pinMode(PIN_DIN,  INPUT);
  pinMode(IPIN_DRDY, INPUT);
  pinMode(PIN_SCLK, OUTPUT);
  pinMode(IPIN_PWDN, OUTPUT);
  pinMode(PIN_START,OUTPUT);
  digitalWrite(IPIN_PWDN, HIGH);
  digitalWrite(IPIN_RESET, HIGH);
  digitalWrite(PIN_START, LOW);
  delay(500);
  SPI.begin();

  //----Set up registers------------
  SPI.beginTransaction(settingsA);
  digitalWrite(IPIN_CS, LOW);
  SPI.transfer(RESET);
  delayMicroseconds(10);
  digitalWrite(IPIN_CS,HIGH);

    //-------Enable read data continuos-----
  SPI.transfer(SDATAC);
  delayMicroseconds(4);

  //reg config 1 set for 250 SPS
  //reg config 2 set for test source driven external
  //reg CH1SET Gain 24 and open connection SRB2.
  digitalWrite(IPIN_CS,LOW);
  SPI.transfer(0x41);
  delayMicroseconds(4);
  SPI.transfer(B10110110);
  delayMicroseconds(4);
  SPI.transfer(0x42);
  delayMicroseconds(4);
  SPI.transfer(B11000010);
  delayMicroseconds(4);
  SPI.transfer(0x43);
  delayMicroseconds(4);
  SPI.transfer(B11110100);
  delayMicroseconds(4);
  SPI.transfer(0x45);
  delayMicroseconds(4);
  SPI.transfer(B01100110);
  delayMicroseconds(4);
  //turn off rest of inputs
  SPI.transfer(0x46);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);
  SPI.transfer(0x47);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);
  SPI.transfer(0x48);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);
  SPI.transfer(0x49);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);
  SPI.transfer(0x4A);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);
  SPI.transfer(0x4B);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);
  SPI.transfer(0x4C);
  delayMicroseconds(4);
  SPI.transfer(B11100000);
  delayMicroseconds(4);

  digitalWrite(IPIN_CS, HIGH);
  SPI.endTransaction();
}

void loop() {
  int n = 0;
  uint32_t reading;
  uint32_t reg;
  //while(1){
  SPI.beginTransaction(settingsA);
  digitalWrite(IPIN_CS, LOW);
  SPI.transfer(RDATAC);
  delayMicroseconds(4);
  SPI.transfer(START);
  delayMicroseconds(4);

  while(digitalRead(IPIN_DRDY)){
    
    delayMicroseconds(4);
  }
  
  reading = SPI.transfer(0);
  delayMicroseconds(4);
  digitalWrite(IPIN_CS, HIGH);
  SPI.endTransaction();
  Serial.println(reading);
  //Serial.println(reg,BIN);
  delay(100);
  //}
}
