
#define len 8

byte Star = 0x01;
byte finsh = 0x00;
int n = 0;

void printArray(byte a){
    Serial.print(B0);
    Serial.println(a, BIN);
}

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);

}

void loop() {
  printArray(Star);
  printArray(finsh);
  finsh = Star << n;
  (finsh == 0x01)? digitalWrite(10, HIGH) : digitalWrite(14, HIGH);
  (finsh == 0x02)? digitalWrite(11, HIGH) : digitalWrite(14, HIGH);
  (finsh == 0x04)? digitalWrite(12, HIGH) : digitalWrite(14, HIGH);
  (finsh == 0x08)? digitalWrite(13, HIGH) : digitalWrite(14, HIGH);
  Serial.println("-------------------------");
  n++;
  if(n == 4){
    finsh = 0x00;
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if(n == 8){
    n = 0;
    digitalWrite(14, LOW);
  }
  delay(1000);

}
