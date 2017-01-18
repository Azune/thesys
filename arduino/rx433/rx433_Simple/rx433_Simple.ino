#define receiverPin A0
#define dataPin 13

byte data = 0;
unsigned int receiverId = 0;

void setup() {
  pinMode(dataPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  receiverId = analogRead(receiverPin);
  Serial.write(0x0a);
  Serial.write(receiverId);
  Serial.write(0x0d);
  //data = digitalRead(dataPin);
}
