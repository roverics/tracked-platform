/*

- RECONSTRUCTED REFERENCE FIRMWARE
-
- Based on the hardware configuration and successful physical
- test documented in DEVELOPMENT_LOG.md.
-
- This is NOT claimed to be the exact historical source file
- used during the original test.
  */

#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN
const byte ADDRESS[6] = "00001";

void setup() {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.println(F("NRF24 not detected"));
    while (true) {}
  }

  radio.setPALevel(RF24_PA_LOW);
  radio.openReadingPipe(1, ADDRESS);
  radio.startListening();
  Serial.println(F("Uno receiver ready"));
}

void loop() {
  if (radio.available()) {
    char message[32] = {};
    radio.read(&message, sizeof(message));
    Serial.print(F("Received: "));
    Serial.println(message);
  }
}
