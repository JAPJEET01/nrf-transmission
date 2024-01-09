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
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN); // Set power level (low to minimize interference)
  radio.startListening(); // Put radio in receiving mode
}

void loop() {
  if (radio.available()) {
    char textReceived[32] = ""; // Allocate space to store received text
    radio.read(&textReceived, sizeof(textReceived)); // Read the received data
    Serial.print("Received: ");
    Serial.println(textReceived); // Print the received text
  }
}
