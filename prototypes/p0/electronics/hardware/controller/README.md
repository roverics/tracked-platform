# Handheld Controller Hardware

## Verified controller

The verified manual-control transmitter used an Arduino Nano, analog joystick, and standard NRF24L01.

| Signal | Nano |
|---|---:|
| Joystick VRx / VRy | A0 / A1 |
| Joystick switch | D2 |
| NRF CE / CSN | D9 / D10 |
| NRF SCK / MOSI / MISO | D13 / D11 / D12 |

Measured joystick center was approximately 509–514, with recorded axis endpoints at 0 and 1023. A neutral dead zone was defined. Wireless joystick data was successfully received by the Mega and used to move a motor.

## Upgrade hardware — not fully validated

- ESP32: available; recorded NRF compilation attempt failed because `RF24.h` was missing.
- External-antenna NRF24L01+ PA/LNA: acquired; no validated range result.
- 2.4-inch touch LCD: acquired; integration pending.
- Planned panel: approximately 20 × 14 cm with four LEDs, MANUAL/AUTO selector, joystick, emergency stop, main switch, charging port, and antenna provision.

The temporary controller test bench should validate each upgrade independently before enclosure integration.
