#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 2
#define TxD 3

int IRSensor = 13;

SoftwareSerial blueToothSerial(RxD, TxD);

void setup()
{
  Serial.begin(9600);
  blueToothSerial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(IRSensor, INPUT)
}

void loop()
{

  char recvChar;
  while (1)
  {
    println(digitalRead(IRSensor));
    
    if (Serial.available())
    { //check if there's any data sent from t he local serial terminal, you can add the other applications here
      recvChar  = Serial.read();
      blueToothSerial.print(recvChar);
    }
  }
}
