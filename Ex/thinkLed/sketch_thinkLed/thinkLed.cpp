//#include "arduino.h"
#include "thinkLed.h"

void initTeensy(){
  pinMode(turnIn, OUTPUT);  
}

void turnOn(int pulse){
  if(pulse == HIGH){
    digitalWrite(turnIn, HIGH);
    delay(1000);
    digitalWrite(turnIn, LOW);
    delay(1000);
  }
}
