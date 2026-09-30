# 07 — ESP32 NRF Test Attempt

- **Date:** September 2026
- **Status:** **DEBUGGING / ATTEMPTED — NOT VALIDATED**
- **Objective:** Begin migrating the controller radio interface from Nano to ESP32.
- **Hardware:** ESP32 and NRF test configuration. The source record does not establish a successful PA/LNA radio test.

## Pin mapping

| Function | ESP32 pin |
|---|---:|
| SCK | GPIO18 |
| MISO | GPIO19 |
| MOSI | GPIO23 |
| NRF CE | GPIO27 |
| NRF CSN | GPIO26 |

## Communication/settings

No successful radio settings or over-air result were validated for the ESP32 attempt.

## Observed result

Compilation failed because `RF24.h` was missing. No valid radio hardware result was recorded.

## Known problems

RF24 library setup must be resolved before fixed-value, joystick, PA/LNA, or range testing. The verified radio architecture remains Nano → standard NRF24L01 → Mega.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included source: [`esp32_nrf_test_reconstructed.ino`](esp32_nrf_test_reconstructed.ino), classified as **RECONSTRUCTED REFERENCE FIRMWARE**. The recorded historical configuration belongs to a failed compile attempt, not verified firmware.

## Build requirements and RF24 installation

- Board platform: ESP32 Arduino core
- Libraries: built-in `SPI`; external `RF24` library by TMRh20
- Arduino IDE: open Library Manager, search for `RF24`, install the TMRh20 library, and select the correct ESP32 board and port
- Arduino CLI, when available: install the ESP32 platform and run `arduino-cli lib install RF24`
- Use a stable 3.3 V supply appropriate for the PA/LNA module and local decoupling; do not power it from 5 V

## Expected serial output

At 115200 baud, the sketch reports initialization success/failure and whether each reference packet was acknowledged. An acknowledgment requires a compatible receiver; it is not evidence that the historical ESP32 attempt succeeded.

Historical status remains **DEBUGGING / ATTEMPTED — NOT VALIDATED**. This included sketch has not been physically validated.
