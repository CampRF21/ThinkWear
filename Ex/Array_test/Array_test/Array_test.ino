
byte Setups[10] = {0x00, 0x96, 0xC2, 0x7E, 0x52, 0x80, 0x20};

void setup() {
  
  Serial.begin(9600);
  pinMode(12, OUTPUT);

}

void loop() {

  for(int i=0 ; i<7 ; i++){
    Serial.print("\t");
    Serial.print(Setups[i], BIN);
    Serial.print("  |  ");
  }
  Serial.print("\n");
  delay(500);
}
