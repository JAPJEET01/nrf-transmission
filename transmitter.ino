#include <SPI.h>
#include <RF24.h>

// NRF24L01 pins on Arduino
#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN); // Create an instance of the radio

const byte address[6] = "00001"; // Address for the communication channel

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); // Set power level (low to minimize interference)
  radio.stopListening(); // Put radio in sending mode
}

void loop() {
  const char textToSend[] = "Hello, Receiver!"; // Text message to send
  radio.write(&textToSend, sizeof(textToSend)); // Send the message
  Serial.println("Message Sent!");
  delay(1000); // Wait for a moment before sending the next message
}
