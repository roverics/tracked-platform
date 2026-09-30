/*

- RECONSTRUCTED REFERENCE FIRMWARE
-
- Based on the hardware configuration and successful physical
- test documented in DEVELOPMENT_LOG.md.
-
- This is NOT claimed to be the exact historical source file
- used during the original test.
  */

const uint8_t RPWM_PIN = 5;
const uint8_t LPWM_PIN = 6;
const uint8_t R_EN_PIN = 7;
const uint8_t L_EN_PIN = 8;
const uint8_t TEST_PWM = 80;

void stopMotor() {
  analogWrite(RPWM_PIN, 0);
  analogWrite(LPWM_PIN, 0);
}

void setup() {
  pinMode(RPWM_PIN, OUTPUT);
  pinMode(LPWM_PIN, OUTPUT);
  pinMode(R_EN_PIN, OUTPUT);
  pinMode(L_EN_PIN, OUTPUT);

  stopMotor();
  digitalWrite(R_EN_PIN, HIGH);
  digitalWrite(L_EN_PIN, HIGH);
}

void loop() {
  // Forward bench test.
  analogWrite(LPWM_PIN, 0);
  analogWrite(RPWM_PIN, TEST_PWM);
  delay(2000);

  stopMotor();
  delay(1000);

  // Reverse bench test. Stop first so both PWM inputs are never driven together.
  analogWrite(RPWM_PIN, 0);
  analogWrite(LPWM_PIN, TEST_PWM);
  delay(2000);

  stopMotor();
  delay(2000);
}
