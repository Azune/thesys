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
    receiverMode = Serial.parseInt();
  }
  
  receiverId = analogRead(receiverPin);
  data = digitalRead(dataPin);

  switch(receiverMode) {
    case RECEIVE: receiveData(); break;
    case DISCOVER: discoverDevices(receiverId); break;
    case REGISTER: registerDevice(); break;
    default: receiverMode = 0;
             receiveData();
  }
}

void receiveData() {
  Serial.println("Receiving data...");
}

void discoverDevices(int receiverId) {
   Serial.println(receiverId);
}

void registerDevice() {
  Serial.println("Registering a device...");  
}
