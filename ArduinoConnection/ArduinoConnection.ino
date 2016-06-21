#include <SoftwareSerial.h>   //Software Serial Port
#include <IRremote.h>
#include <IRremoteInt.h>

#define RxD 2
#define TxD 3
#define IRSensor 7
#define Light 4

SoftwareSerial blueToothSerial(RxD, TxD);

int RECEIVE_PIN = 7;
IRrecv irreceiver(RECEIVE_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  blueToothSerial.begin(9600);

  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(IRSensor, INPUT);
  pinMode(4, OUTPUT);
  
  irreceiver.enableIRIn(); // Start the receiver
}

void loop()
{
  char recvChar;
  while (1)
  {
    if (irreceiver.decode(&results))
    {
      if (results.value == 1520217670)
      {
        Serial.println(results.value);
        blueToothSerial.print("You lost bitch#");

        digitalWrite(Light, HIGH);
        delay(500);
        digitalWrite(Light, LOW);

        irreceiver.resume();
      }
    }

    /*if (Serial.available())
      { //check if there's any data sent from t he local serial terminal, you can add the other applications here
      }*/

    delay(100); //NEW LINE
  }
}
