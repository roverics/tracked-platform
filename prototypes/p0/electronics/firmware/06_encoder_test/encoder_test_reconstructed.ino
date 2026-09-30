/*

- RECONSTRUCTED REFERENCE FIRMWARE
-
- Based on the hardware configuration and successful physical
- test documented in DEVELOPMENT_LOG.md.
-
- This is NOT claimed to be the exact historical source file
- used during the original test.
  */

const uint8_t ENCODER_PIN = 2;
const uint16_t DISK_SLOTS = 20;
const uint32_t SAMPLE_INTERVAL_MS = 1000;

// Assumption for recalibration: one RISING interrupt per slot.
// Confirm the real pulses per revolution and interrupt edge before trusting RPM.
const uint16_t ASSUMED_PULSES_PER_REVOLUTION = DISK_SLOTS;

volatile uint32_t pulseCount = 0;
uint32_t previousSampleMs = 0;

void countEncoderPulse() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600);
  pinMode(ENCODER_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), countEncoderPulse, RISING);
  previousSampleMs = millis();
  Serial.println(F("Encoder recalibration reference; RPM output is NOT validated"));
}

void loop() {
  const uint32_t now = millis();
  const uint32_t elapsedMs = now - previousSampleMs;
  if (elapsedMs < SAMPLE_INTERVAL_MS) return;

  noInterrupts();
  const uint32_t pulses = pulseCount;
  pulseCount = 0;
  interrupts();

  const float revolutions = (float)pulses / ASSUMED_PULSES_PER_REVOLUTION;
  const float rpm = revolutions * (60000.0f / elapsedMs);

  Serial.print(F("Pulses: "));
  Serial.print(pulses);
  Serial.print(F("  Unvalidated RPM: "));
  Serial.println(rpm, 2);
  previousSampleMs = now;
}
