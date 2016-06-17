#include <SoftwareSerial.h>

int RX_PIN;
int TX_PIN;

int IRSensor;

SoftwareSerial bluetoothSerial(RX_PIN, TX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetoothSerial.begin(9600);

  pinMode(IRSensor, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetoothSerial.available()) {
    bluetoothSerial.write((Char) Serial.read());
  }
}
