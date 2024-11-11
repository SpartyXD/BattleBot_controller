#include <Arduino.h>
#include <RF24.h>

//============================
//PINS
const int leftPin;
const int rightPin;
const int ledPin;

const int CEPin;
const int CSNPin;



//============================
//GLOBALS
RF24 radio(CEPin, CSNPin);
const byte address[6] = "00001";

//============================

void setup(){
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop(){
  const char message[] = "Beep beep";
  bool success = radio.write(&message, sizeof(message));

  Serial.println(success);
  delay(1000);
}
