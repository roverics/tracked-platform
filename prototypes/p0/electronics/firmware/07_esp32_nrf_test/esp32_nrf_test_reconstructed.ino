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

const uint8_t NRF_SCK = 18;
const uint8_t NRF_MISO = 19;
const uint8_t NRF_MOSI = 23;
const uint8_t NRF_CE = 27;
const uint8_t NRF_CSN = 26;

RF24 radio(NRF_CE, NRF_CSN);
const byte ADDRESS[6] = "00001";

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("ESP32 NRF24L01+ bring-up reference");

  SPI.begin(NRF_SCK, NRF_MISO, NRF_MOSI, NRF_CSN);
  if (!radio.begin(&SPI)) {
    Serial.println("NRF24 not detected; check RF24 library, wiring, and 3.3 V supply");
    while (true) delay(1000);
  }

  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);  // Start low during bench bring-up.
  radio.openWritingPipe(ADDRESS);
  radio.stopListening();
  Serial.println("NRF24 initialized; no historical ESP32 link result is claimed");
}

void loop() {
  const uint32_t testValue = 123;
  const bool sent = radio.write(&testValue, sizeof(testValue));
  Serial.println(sent ? "Reference packet acknowledged" : "Reference packet not acknowledged");
  delay(1000);
}
