#include <SPI.h>

byte CS, SECLK, MAOSI;

void setup() {

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT); 
  Serial.begin(9600);
  
}

void loop() {
  CS = digitalRead(10);
  SECLK = digitalRead(11);
  MAOSI = digitalRead(13);
  Serial.print("\t");
  Serial.print("CS: ");
  Serial.print(CS, BIN);
  Serial.print("  |  ");
  Serial.print("MOSI: ");
  Serial.print(MAOSI, BIN);
  Serial.print("  |  ");
  Serial.print("SECLK: ");
  Serial.println(SECLK, BIN);
  delay(500);
}
