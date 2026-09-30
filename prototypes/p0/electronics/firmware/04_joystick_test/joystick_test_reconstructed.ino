/*

- RECONSTRUCTED REFERENCE FIRMWARE
-
- Based on the hardware configuration and successful physical
- test documented in DEVELOPMENT_LOG.md.
-
- This is NOT claimed to be the exact historical source file
- used during the original test.
  */

const uint8_t JOYSTICK_X_PIN = A0;
const uint8_t JOYSTICK_Y_PIN = A1;
const uint8_t JOYSTICK_SWITCH_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(JOYSTICK_SWITCH_PIN, INPUT_PULLUP);
  Serial.println(F("Joystick test ready; documented center was approximately 509-514"));
}

void loop() {
  const int x = analogRead(JOYSTICK_X_PIN);
  const int y = analogRead(JOYSTICK_Y_PIN);
  const bool pressed = digitalRead(JOYSTICK_SWITCH_PIN) == LOW;

  Serial.print(F("X: "));
  Serial.print(x);
  Serial.print(F("  Y: "));
  Serial.print(y);
  Serial.print(F("  SW: "));
  Serial.println(pressed ? F("PRESSED") : F("RELEASED"));
  delay(100);
}
