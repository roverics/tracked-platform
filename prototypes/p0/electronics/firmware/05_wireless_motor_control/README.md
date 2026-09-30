# 05 — Wireless Joystick-to-Motor Control

- **Date:** 2–3 September 2026
- **Status:** **VERIFIED**
- **Objective:** Convert wirelessly received joystick data into physical motor motion.
- **Hardware:** Joystick, Nano, two standard NRF24L01 modules, Mega 2560, BTS7960, DC motor.

## Rover-side pin mapping

| Function | Mega pin |
|---|---:|
| Encoder signal | D2 |
| BTS7960 RPWM | D6 |
| BTS7960 LPWM | D7 |
| NRF CSN | D8 |
| NRF CE | D9 |
| SPI MISO / MOSI / SCK | D50 / D51 / D52 |
| SPI SS/master | D53 |

`REN` and `LEN` were held HIGH at 5 V during the relevant tests.

## Communication/settings

The verified radio settings were address `00001`, channel 76, and 250 kbps; successful joystick-era SPI operation was approximately 1 MHz.

## Observed result

Joystick input was transmitted, received, converted to motor commands, and produced physical motor movement through the BTS7960.

## Known problems

The test does not establish two-motor chassis steering, range, load, slope, endurance, or closed-loop speed performance.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included sources are **RECONSTRUCTED REFERENCE FIRMWARE**:

- [`controller_tx_reconstructed.ino`](controller_tx_reconstructed.ino)
- [`rover_rx_reconstructed.ino`](rover_rx_reconstructed.ino)

They are not the successful historical sketch pair. The receiver adds a 500 ms link-loss stop, gradual PWM changes, and stop-before-reverse handling as reference safety behavior. The reference dead zone is centered at 512 (inside the documented 509–514 range) with a tunable width of 25; that width was not recovered from the historical firmware and must be calibrated.

## Build requirements and expected output

- Boards: Arduino Nano controller and Arduino Mega 2560 rover receiver
- Libraries: built-in `SPI`; external `RF24` library by TMRh20
- Install RF24 from Arduino IDE Library Manager or run `arduino-cli lib install RF24`
- Controller serial: raw `X`, `Y`, and radio `TX:OK|FAIL`
- Rover serial: startup status; motor motion is the primary output
- `REN` and `LEN` must be held HIGH externally at 5 V as documented
- Historical end-to-end motor movement was verified; the included implementations have not been physically validated

The controller and rover files target different boards. Compile/upload each file individually; do not combine both into one Arduino build.
