#include <SPI.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available from Serial monitor
    String input = Serial.readString(); // Read the data from Serial monitor
    const char* textToSend = input.c_str(); // Convert String to const char*
    
    radio.write(textToSend, strlen(textToSend)); // Send the message
    Serial.println("Message Sent: " + input);
  }
}
