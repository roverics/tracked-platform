# 04 — Joystick Characterization

- **Date:** 28–31 August 2026
- **Status:** **VERIFIED**
- **Objective:** Measure joystick center and endpoints and establish neutral handling.
- **Hardware:** Arduino Nano, analog joystick; standard NRF24L01 was wired for controller development.

## Pin mapping

| Signal | Nano |
|---|---:|
| Joystick VRx | A0 |
| Joystick VRy | A1 |
| Joystick switch | D2 |
| NRF CE | D9 |
| NRF CSN | D10 |
| NRF SCK / MOSI / MISO | D13 / D11 / D12 |

## Settings and observed result

Center measured approximately 509–514. Full forward/right measured 1023 and full backward/left measured 0. A center dead zone was defined; its exact width is not recorded.

## Known problems

No calibration across multiple joysticks, temperature, or long-term drift is recorded.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included source: [`joystick_test_reconstructed.ino`](joystick_test_reconstructed.ino), classified as **RECONSTRUCTED REFERENCE FIRMWARE**.

## Build requirements and expected output

- Board: Arduino Nano
- Libraries: Arduino core only
- Serial rate: 9600 baud
- Expected lines: `X: <raw>  Y: <raw>  SW: PRESSED|RELEASED`
- A centered physical joystick should be compared with the documented approximate 509–514 range; variation must be measured, not assumed
- Historical joystick measurements were verified; the included source is not historical
