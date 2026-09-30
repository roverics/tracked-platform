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

const uint8_t JOYSTICK_X_PIN = A0;
const uint8_t JOYSTICK_Y_PIN = A1;
const uint8_t JOYSTICK_SWITCH_PIN = 2;
const int16_t DOCUMENTED_CENTER = 512;  // Within the recorded 509-514 range.

RF24 radio(9, 10);  // CE, CSN
const byte ADDRESS[6] = "00001";

struct ControlPacket {
  uint16_t x;
  uint16_t y;
  uint8_t switchPressed;
};

void setup() {
  Serial.begin(9600);
  pinMode(JOYSTICK_SWITCH_PIN, INPUT_PULLUP);

  if (!radio.begin()) {
    Serial.println(F("NRF24 not detected"));
    while (true) {}
  }

  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(ADDRESS);
  radio.stopListening();
  Serial.println(F("Controller transmitter ready"));
  Serial.print(F("Reference center: "));
  Serial.println(DOCUMENTED_CENTER);
}

void loop() {
  ControlPacket packet;
  packet.x = analogRead(JOYSTICK_X_PIN);
  packet.y = analogRead(JOYSTICK_Y_PIN);
  packet.switchPressed = digitalRead(JOYSTICK_SWITCH_PIN) == LOW;

  const bool sent = radio.write(&packet, sizeof(packet));
  Serial.print(F("X:"));
  Serial.print(packet.x);
  Serial.print(F(" Y:"));
  Serial.print(packet.y);
  Serial.print(F(" TX:"));
  Serial.println(sent ? F("OK") : F("FAIL"));
  delay(50);
}
