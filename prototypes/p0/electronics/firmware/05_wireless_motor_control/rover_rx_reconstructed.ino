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

const uint8_t RPWM_PIN = 6;
const uint8_t LPWM_PIN = 7;
const int16_t JOYSTICK_CENTER = 512;  // Within recorded center range 509-514.
const int16_t REFERENCE_DEAD_ZONE = 25;  // Reference value; calibrate on the actual joystick.
const uint16_t RADIO_TIMEOUT_MS = 500;
const uint8_t RAMP_STEP = 5;
const uint16_t RAMP_INTERVAL_MS = 20;

RF24 radio(9, 8);  // CE, CSN
const byte ADDRESS[6] = "00001";

struct ControlPacket {
  uint16_t x;
  uint16_t y;
  uint8_t switchPressed;
};

int16_t targetPwm = 0;
int16_t currentPwm = 0;
uint32_t lastPacketMs = 0;
uint32_t lastRampMs = 0;

int16_t joystickToSignedPwm(uint16_t raw) {
  const int16_t lowEdge = JOYSTICK_CENTER - REFERENCE_DEAD_ZONE;
  const int16_t highEdge = JOYSTICK_CENTER + REFERENCE_DEAD_ZONE;
  if (raw > highEdge) {
    return map(raw, highEdge, 1023, 0, 255);
  }
  if (raw < lowEdge) {
    return -map(raw, lowEdge, 0, 0, 255);
  }
  return 0;
}

int16_t approachValue(int16_t current, int16_t target, uint8_t step) {
  if (current < target) {
    const int16_t next = current + step;
    return next > target ? target : next;
  }
  if (current > target) {
    const int16_t next = current - step;
    return next < target ? target : next;
  }
  return current;
}

void driveMotor(int16_t command) {
  if (command > 0) {
    analogWrite(LPWM_PIN, 0);
    analogWrite(RPWM_PIN, command);
  } else if (command < 0) {
    analogWrite(RPWM_PIN, 0);
    analogWrite(LPWM_PIN, -command);
  } else {
    analogWrite(RPWM_PIN, 0);
    analogWrite(LPWM_PIN, 0);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(53, OUTPUT);  // Keep the Mega in SPI master mode.
  pinMode(RPWM_PIN, OUTPUT);
  pinMode(LPWM_PIN, OUTPUT);
  driveMotor(0);

  // BTS7960 REN and LEN are documented as held HIGH externally at 5 V.
  if (!radio.begin()) {
    Serial.println(F("NRF24 not detected; motor held stopped"));
    while (true) { driveMotor(0); }
  }

  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.openReadingPipe(1, ADDRESS);
  radio.startListening();
  Serial.println(F("Rover receiver ready"));
}

void loop() {
  if (radio.available()) {
    ControlPacket packet;
    while (radio.available()) radio.read(&packet, sizeof(packet));
    targetPwm = joystickToSignedPwm(packet.y);
    lastPacketMs = millis();
  }

  if (millis() - lastPacketMs > RADIO_TIMEOUT_MS) targetPwm = 0;

  if (millis() - lastRampMs >= RAMP_INTERVAL_MS) {
    lastRampMs = millis();
    // Ramp fully to zero before reversing direction.
    const bool reversing = (currentPwm > 0 && targetPwm < 0) ||
                           (currentPwm < 0 && targetPwm > 0);
    const int16_t safeTarget = reversing ? 0 : targetPwm;
    currentPwm = approachValue(currentPwm, safeTarget, RAMP_STEP);
    driveMotor(currentPwm);
  }
}
