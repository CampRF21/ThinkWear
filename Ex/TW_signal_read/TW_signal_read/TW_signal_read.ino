#include<SPI.h>
#define WAKEUP 0x02
#define STNDBY 0x04
#define RESET  0x06
#define START  0x08
#define STOP   0x0A
#define SDATAC 0x12
#define RDATAC 0x11

const int STRT = 7;
const int PWDN = 9;
const int DRDY  = 8;
//const int SS  = 10;
uint8_t Reg1;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
  pinMode(STRT, OUTPUT);
  pinMode(PWDN, OUTPUT);
  pinMode(DRDY, INPUT);
  pinMode(SS, OUTPUT);

  digitalWrite(STRT, LOW);
  digitalWrite(SS, HIGH);
  digitalWrite(PWDN, HIGH);
//  digitalWrite(RST, HIGH);
  delay(200);

  digitalWrite(SS, LOW);
  SPI.transfer(RESET);
  delayMicroseconds(12);
  SPI.transfer(SDATAC);
  delayMicroseconds(3);
  SPI.transfer(0x41);
  delayMicroseconds(1.9);
  SPI.transfer(0x00);
  delayMicroseconds(1.9);
  SPI.transfer(0x96);
  delayMicroseconds(3);
  SPI.transfer(0x42);
  SPI.transfer(0x00);
  SPI.transfer(0xC2);
  delayMicroseconds(3);
  SPI.transfer(0x43);
  SPI.transfer(0x00);
  SPI.transfer(0x7E);
  delayMicroseconds(3);
  SPI.transfer(0x45);
  SPI.transfer(0x00);
  SPI.transfer(0x52);
  delayMicroseconds(3);
  SPI.transfer(0x46);
  SPI.transfer(0x00);
  SPI.transfer(0x80);
  delayMicroseconds(3);
  SPI.transfer(0x47);
  SPI.transfer(0x00);
  SPI.transfer(0x80);
  delayMicroseconds(3);
  SPI.transfer(0x48);
  SPI.transfer(0x00);
  SPI.transfer(0x80);
  delayMicroseconds(3);
  SPI.transfer(0x55);
  SPI.transfer(0x00);
  SPI.transfer(0x20);
  delayMicroseconds(3);
  digitalWrite(SS, HIGH);
  digitalWrite(STRT, HIGH);
}

void loop() {

  uint8_t data;
  digitalWrite(SS, LOW);
  SPI.transfer(RDATAC);
  delayMicroseconds(3);
  SPI.transfer(START);
  delayMicroseconds(3);

  while(DRDY){
    data = SPI.transfer(0);
    //data = SPI.transfer(0);
    delay(4);
  }

  //for(int i = 0; i < 24; i++){ Serial.print(data[i]);}
  //Serial.println("");
  
  digitalWrite(SS, LOW);
  SPI.endTransaction();
  Serial.println(data);
}
