# 01 — Initial Motor Test

- **Date:** 20 August 2026
- **Status:** **VERIFIED**
- **Objective:** Verify BTS7960 control of the 12 V DC worm-geared motor.
- **Hardware:** Arduino Uno, BTS7960, motor, external motor supply.

## Pin mapping

| BTS7960 | Uno |
|---|---|
| RPWM | D5 |
| LPWM | D6 |
| R_EN | D7 |
| L_EN | D8 |
| VCC | 5 V |
| GND | Common GND |

Motor supply connected to `B+ / B-`; motor connected to `M+ / M-`.

## Settings and observed result

The test used PWM approximately 80 and commanded run, stop, and opposite direction. The motor responded correctly.

## Known problems

No failure is recorded for this test. Load, endurance, current, stall, and complete two-motor behavior were not validated by it.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included source: [`motor_test_reconstructed.ino`](motor_test_reconstructed.ino), classified as **RECONSTRUCTED REFERENCE FIRMWARE**. It implements the documented PWM ≈80 forward/stop/reverse sequence and is not the original verified sketch.

## Build requirements and expected output

- Board: Arduino Uno
- Libraries: Arduino core only
- Serial output: none; observe the motor sequence directly on a safely secured bench setup
- Historical hardware result: verified on 20 August 2026
- Included source validation: compilation may be checked, but it has not thereby been physically validated
