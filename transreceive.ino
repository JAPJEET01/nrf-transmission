#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL);  // Set the writing pipe address
}

void loop() {
  const char textToSend[] = "Hello, Receiver!";
  
  radio.write(&textToSend, sizeof(textToSend));
  
  Serial.println("Message sent: " + String(textToSend));
  delay(1000);  // Adjust the delay based on your requirements
}






receiver




#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);  // Set the reading pipe address
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char textReceived[32] = "";
    radio.read(&textReceived, sizeof(textReceived));
    
    Serial.println("Message received: " + String(textReceived));
  }
}
