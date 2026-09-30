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

RF24 radio(9, 8);  // CE, CSN
const byte ADDRESS[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(53, OUTPUT);  // Keep the Mega in SPI master mode.

  if (!radio.begin()) {
    Serial.println(F("NRF24 not detected"));
    while (true) {}
  }

  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.openReadingPipe(1, ADDRESS);
  radio.startListening();
  Serial.println(F("Mega fixed-value receiver ready"));
}

void loop() {
  if (radio.available()) {
    int16_t value = 0;
    radio.read(&value, sizeof(value));
    Serial.print(F("GOT: "));
    Serial.println(value);
  }
}
