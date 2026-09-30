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
const int16_t TEST_VALUE = 123;

void setup() {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.println(F("NRF24 not detected"));
    while (true) {}
  }

  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(ADDRESS);
  radio.stopListening();
  Serial.println(F("Nano fixed-value transmitter ready"));
}

void loop() {
  const bool sent = radio.write(&TEST_VALUE, sizeof(TEST_VALUE));
  Serial.println(sent ? F("Sent: 123") : F("Send failed"));
  delay(500);
}
