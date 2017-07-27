#include "SPI.h"

int Signal;

void setup() {

Serial.begin(9600);
pinMode(13, OUTPUT);  
pinMode(14, OUTPUT); 

}

void loop() {

//analogWrite(13, 30);

for(int i=0 ; i < 2000000 ; i++){
  if(i%2 == 0){
    digitalWrite(14, HIGH);
    Signal = digitalRead(14);
    Serial.println(Signal);
    delay(500);
  }
  else{
    digitalWrite(14, LOW);
    Signal = digitalRead(14);
    Serial.println(Signal);
    delay(500);
  }
}

}
