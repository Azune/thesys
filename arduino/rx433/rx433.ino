#define receiverPin A0
#define dataPin 13

enum Modes {RECEIVE, DISCOVER, REGISTER};
const unsigned int maxDevices = 10;

byte data = 0;
unsigned int serialData = 0;
unsigned int receiverId = 0;
unsigned int devices[maxDevices];
Modes receiverMode = RECEIVE;

void setup() {
  pinMode(dataPin, INPUT);
  Serial.begin(9600);
  Serial.println("Arduino started.");
}

void loop() {
  if (Serial.available() > 0) {
    Serial.println("Waiting for input...");
    receiverMode = Serial.read();
  }
  
  receiverId = analogRead(receiverPin);
  data = digitalRead(dataPin);

  Serial.print("Executing mode ");
  Serial.println(receiverMode);

  switch(receiverMode) {
    case RECEIVE: receiveData(); break;
    case DISCOVER: discoverDevices(); break;
    case REGISTER: registerDevice(); break;
  }

  delay(1000);
}

void receiveData() {
  Serial.println("Receiving data...");
}

void discoverDevices() {
   Serial.println("Discovering data ...");
}

void registerDevice() {
  Serial.println("Registering a device...");  
}
