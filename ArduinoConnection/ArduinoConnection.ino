#include <SoftwareSerial.h>

int RX_PIN = 3;
int TX_PIN = 2;
int data = 0;

int IRSensor = 13;

SoftwareSerial bluetoothSerial(RX_PIN, TX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetoothSerial.begin(9600);

  pinMode(IRSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetoothSerial.available()) {

    data = digitalRead(IRSensor);
    
    bluetoothSerial.write((Char) Serial.read());
  }
}
