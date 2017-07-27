#include<SPI.h>

#define CS    (10)
#define MO_SI (11)
#define MI_SO (12)
#define SRCLK (13)

 byte Pass = 0x00;
 
void setup() {

  pinMode(CS, OUTPUT);
  pinMode(MO_SI, OUTPUT);
  pinMode(MI_SO, INPUT);
  pinMode(SRCLK, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  digitalWrite(SS, HIGH);

}

void loop() {

  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE1));
  digitalWrite(CS, LOW);
  SPI.transfer(Pass);
  digitalWrite(CS, HIGH);
  SPI.endTransaction();
  Pass++;
  if(Pass == 0xFF)
    Pass = 0x0;
  delay(500);

}
