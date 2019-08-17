#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address1[6] = "00001";
const byte address2[6] = "00002";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  
}
void loop() {
  
  radio.openReadingPipe(0, address1);
  radio.startListening();
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  else
  {
    Serial.println("No. Signal from Light SLT01");  
  }
  radio.stopListening();
  delay(1000);
  radio.openReadingPipe(0, address2);
  radio.startListening();
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  else
  {
    Serial.println("No. Signal from Light SLT02");  
  }
  radio.stopListening();
  delay(1000);
  
}
