const int txPin = 2;
const int rxPin = 3;
const int baudRate = 9600;
void setup() {
  pinMode(txPin, OUTPUT);
  Serial.begin(baudRate);
}
void sendByte(uint8_t data) {
   digitalWrite(txPin, LOW);
  delayMicroseconds(1000000 / baudRate);
   for (int i = 0; i < 8; i++) {
   digitalWrite(txPin, (data >> i) & 1);
   delayMicroseconds(1000000 / baudRate);
   }
  digitalWrite(txPin, HIGH);
   delayMicroseconds(1000000 / baudRate);
}
void sendData(uint8_t* dataArray, size_t dataSize) {
   for (size_t i = 0; i < dataSize; i++) {
   sendByte(dataArray[i]);
   } 
}
void loop() {
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      uint8_t data = Serial.read();
      sendByte(data);
    }
    sendByte('\n');
  }
  delay(100);
}
