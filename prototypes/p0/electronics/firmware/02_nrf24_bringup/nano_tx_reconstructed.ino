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
const char MESSAGE[] = "NRF24 TEST";

void setup() {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.println(F("NRF24 not detected"));
    while (true) {}
  }

  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(ADDRESS);
  radio.stopListening();
  Serial.println(F("Nano transmitter ready"));
}

void loop() {
  const bool sent = radio.write(&MESSAGE, sizeof(MESSAGE));
  Serial.println(sent ? F("Sent: NRF24 TEST") : F("Send failed"));
  delay(1000);
}
