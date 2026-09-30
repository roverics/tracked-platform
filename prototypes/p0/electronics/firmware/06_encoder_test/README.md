# 06 — Optical Encoder Test

- **Date:** 3 September 2026
- **Status:** **PARTIALLY VERIFIED**
- **Objective:** Detect motor rotation pulses and estimate RPM.
- **Hardware:** Arduino Mega 2560, optical encoder, 20-slot disk.

## Pin mapping and calculation

| Signal | Mega pin |
|---|---:|
| Encoder output | D2 |

Attempted calculation: `RPM = (pulses / 20) × 60`.

## Observed result

Pulse detection was verified. With joystick X approximately 1023 and PWM ramping approximately 60 → 180, reported values included 117, 342, 507, 600, 540, 474, 702, and 531 RPM.

## Known problems

Those RPM readings are **invalid/unvalidated** because they exceed the motor's stated approximately 260 RPM maximum. Candidate causes include edge counting, pulses-per-revolution assumptions, noise, interrupt configuration, signal conditioning, and disk alignment.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included source: [`encoder_test_reconstructed.ino`](encoder_test_reconstructed.ino), classified as **RECONSTRUCTED REFERENCE FIRMWARE**. It assumes one rising-edge pulse per disk slot solely as a recalibration starting point. That assumption must be checked against the physical sensor and disk.

## Build requirements and expected output

- Board: Arduino Mega 2560
- Libraries: Arduino core only
- Serial rate: 9600 baud
- Expected lines: `Pulses: <count>  Unvalidated RPM: <value>`
- Historical status: pulse detection verified; RPM accuracy not verified
- The output of this reconstructed sketch must not be treated as accurate until compared with an independent RPM reference
