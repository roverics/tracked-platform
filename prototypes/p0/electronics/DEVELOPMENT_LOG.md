# Tracked Rover Prototype — Development and Test Log

**Development period:** August–September 2026  
**Log version:** 1.0  
**Current status date:** 30 September 2026  
**Purpose:** Technical development record

> This record separates verified physical results from partial tests, debugging, acquired hardware, and plans. Exact historical firmware is not treated as archived unless the original source file is available.

## Status legend

| Status | Meaning |
|---|---|
| **VERIFIED** | Demonstrated on physical hardware |
| **PARTIALLY VERIFIED** | Some functions worked; calibration or validation remains |
| **DEBUGGING / ATTEMPTED** | Attempted without a validated result |
| **HARDWARE ACQUIRED** | Purchased or available but not fully integrated |
| **PLANNED** | Future development only |

## Project scope

The project is a modular tracked rover prototype for validating mobility, remote control, sensing, feedback, and future autonomous-navigation functions. The current prototype is approximately 25 × 25 cm. An early load-test target of up to approximately 10 kg and a slope-test target of approximately 15° have not been recorded as achieved.

A future platform with payload on the order of 200 kg has been discussed. It is a scale-up objective, not a capability of the current prototype.

## 1. Initial BTS7960 motor test

- **Date:** 20 August 2026
- **Status:** **VERIFIED**
- **Objective:** Validate basic operation of the selected motor and driver before adding radio or sensors.
- **Hardware:** Arduino Uno, BTS7960, 12 V DC worm-geared motor, external motor power source.
- **Motor data used during development:** stated maximum speed ≈260 RPM; nominal current ≈1.6 A; stall current ≈8 A.
- **Wiring:**

  | Function | Arduino Uno |
  |---|---|
  | RPWM | D5 |
  | LPWM | D6 |
  | R_EN | D7 |
  | L_EN | D8 |
  | Logic VCC | 5 V |
  | GND | Common GND |

  Motor power connected to `B+ / B-`; motor connected to `M+ / M-`.
- **Procedure:** Apply PWM ≈80; command run, stop, and opposite direction.
- **Result:** Motor responded correctly to PWM/direction commands.
- **Engineering conclusion:** Retain the BTS7960 motor-driver architecture.
- **Next step:** Add wireless command input and later validate the complete drive system.
- **Firmware provenance:** Pins and behavior are known, but the exact original `.ino` text is not archived.

## 2. NRF24L01 bring-up

- **Date:** 21 August 2026
- **Status:** **VERIFIED AFTER DEBUGGING at module/communication-development level**
- **Objective:** Establish a standard NRF24L01 radio-only bench setup before reconnecting joystick, display, or motor hardware.
- **Hardware:** Arduino Nano transmitter, Arduino Uno receiver during early testing, standard NRF24L01 modules.
- **Wiring:**

  | NRF24L01 | Nano / Uno |
  |---|---|
  | VCC | 3.3 V |
  | GND | GND |
  | CE | D9 |
  | CSN | D10 |
  | SCK | D13 |
  | MOSI | D11 |
  | MISO | D12 |
  | IRQ | Not connected |

  A 10–47 µF capacitor near the radio supply was used/recommended.
- **Procedure:** Verify wiring, CE/CSN, 3.3 V supply, local decoupling, lower SPI speed, and modules individually. Approximately 4 MHz SPI was used during stabilization.
- **Result:** Bring-up progressed after repeated `NRF not found` / unstable behavior. At least one suspicious module became abnormally hot.
- **Engineering conclusion:** Radio power, wiring, and conservative SPI configuration require explicit attention.
- **Next step:** Prove a fixed-value end-to-end link and then transmit joystick data.
- **Firmware provenance:** Exact historical source is not archived.

## 3. Controller joystick characterization

- **Date:** 28–31 August 2026
- **Status:** **VERIFIED**
- **Objective:** Characterize joystick endpoints and neutral behavior for controller commands.
- **Hardware:** Arduino Nano, analog joystick; standard NRF24L01 wiring present.
- **Wiring:** VRx A0, VRy A1, switch D2; radio CE D9, CSN D10, SCK D13, MOSI D11, MISO D12.
- **Procedure:** Read both axes at center and full travel; define a center dead zone.
- **Result:** Center ≈509–514; full forward 1023; full backward 0; full left 0; full right 1023.
- **Engineering conclusion:** Inputs covered the expected ADC endpoints; a neutral dead zone is required.
- **Next step:** Transmit real X/Y values to the rover receiver.
- **Firmware provenance:** Exact historical source is not archived.

## 4. Nano-to-Mega wireless link

- **Date:** 31 August–3 September 2026
- **Status:** **VERIFIED**
- **Objective:** Demonstrate fixed-value and joystick-data transfer from the Nano controller to the Mega receiver.
- **Hardware:** Arduino Nano, Arduino Mega 2560, two standard NRF24L01 modules, analog joystick for the later stage.
- **Configuration:** Address `00001`; channel 76; 250 kbps; successful joystick-era RF24 SPI operation ≈1 MHz. Earlier stabilization used ≈4 MHz.
- **Mega wiring:** CE D9, CSN D8, MISO D50, MOSI D51, SCK D52, SS/master configuration D53, VCC 3.3 V, common GND.
- **Procedure:** Send a known value, confirm reception, then repeat with live joystick X/Y values.
- **Result:** Mega output included `GOT: 123`; real joystick values were subsequently received.
- **Engineering conclusion:** The Nano → standard NRF24L01 → Mega data path was physically demonstrated.
- **Next step:** Convert received commands into BTS7960 motor actuation.
- **Firmware provenance:** Exact historical transmitter and receiver files are not archived.

## 5. Wireless joystick-to-motor control

- **Date:** 2–3 September 2026
- **Status:** **VERIFIED**
- **Objective:** Demonstrate end-to-end manual motor control over the verified radio link.
- **Hardware:** Joystick, Nano, two standard NRF24L01 modules, Mega 2560, BTS7960, DC motor.
- **Rover configuration:** Encoder D2; BTS7960 RPWM D6 and LPWM D7; radio CSN D8 and CE D9; SPI D50–D52; SS/master D53. `REN` and `LEN` held HIGH at 5 V for the relevant tests.
- **Procedure:** Read joystick input, transmit it, receive it on Mega, convert it to motor commands, and apply those through the BTS7960.
- **Result:** Joystick input produced physical motor movement.
- **Engineering conclusion:** The complete manual-control signal chain was demonstrated for the tested motor setup.
- **Next step:** Add calibrated feedback and validate integrated two-motor/chassis behavior.
- **Firmware provenance:** The exact successful `.ino` pair is not archived and no reconstruction is presented as verified firmware.

## 6. Optical encoder integration

- **Date:** 3 September 2026
- **Status:** **PARTIALLY VERIFIED**
- **Objective:** Detect rotation pulses and evaluate an initial RPM calculation.
- **Hardware:** Arduino Mega 2560, optical encoder, 20-slot disk; signal on D2.
- **Calculation attempted:** `RPM = (pulses / 20) × 60`.
- **Procedure:** Observe pulse-derived RPM while joystick X was ≈1023 and PWM ramped ≈60 → 180.
- **Result:** Pulse detection worked. Reported readings included 117, 342, 507, 600, 540, 474, 702, and 531 RPM.
- **Engineering conclusion:** Because the motor's stated maximum is ≈260 RPM, these readings are **invalid/unvalidated**. Possible causes include transition counting, pulses-per-revolution assumptions, noise, interrupt-edge configuration, signal conditioning, or geometry/alignment.
- **Next step:** Calibrate against an independent RPM reference before closed-loop control.
- **Firmware provenance:** Partial logic/settings are known; no exact verified source file is archived.

## 7. Power-system development

- **Date:** August–September 2026 (no more specific date recorded)
- **Status:** **PARTIALLY VERIFIED / ARCHITECTURE DEFINED; INTEGRATION ONGOING**
- **Objective:** Define battery, protection, conversion, and distribution for the rover.
- **Hardware/configuration:** 4S Li-ion battery, ≈2200 mAh, 14.8 V nominal, 16.8 V full; 40 A BMS; 20 A main fuse; LM2596-based conversion considered/used; NRF supply 3.3 V; battery-divider monitoring considered in broader display work.
- **Result:** Architecture was defined; no completed integrated-system validation is recorded.
- **Engineering conclusion:** Protection and conversion components must be validated under the final electrical load.
- **Next step:** Test grounding, rail stability, fuse/BMS behavior, radio supply, endurance, and power consumption on the bench.
- **Firmware provenance:** Not applicable. BTS7960 current-sense pins were identified, but validated stall protection was not completed.

## 8. Controller HMI and mechanical layout

- **Date:** September 2026
- **Status:** **PLANNED / LAYOUT DEFINED**
- **Objective:** Define a handheld controller panel.
- **Configuration:** Approximate 20 × 14 cm panel; planned 2.4-inch touch LCD, four status LEDs, MANUAL/AUTO selector, joystick, emergency stop, main switch, charging port, and external antenna provision.
- **Result:** Layout defined; functional integration not recorded.
- **Next step:** Build the temporary controller test bench and validate each element.

## 9. NRF24L01+ PA/LNA external-antenna upgrade

- **Date:** Hardware purchased by 10 September 2026
- **Status:** **HARDWARE ACQUIRED — RANGE VALIDATION PENDING**
- **Objective:** Prepare an external-antenna radio upgrade.
- **Hardware:** Pair of NRF24L01+ PA/LNA modules.
- **Result:** No validated long-range result is recorded.
- **Engineering conclusion:** No range claim can be made.
- **Next step:** Measure line-of-sight range, packet loss, latency, motor/driver interference, and supply stability.
- **Firmware provenance:** No validated PA/LNA test firmware is archived.

## 10. ESP32 controller upgrade

- **Date:** September 2026
- **Status:** **DEBUGGING / ATTEMPTED — NOT VALIDATED**
- **Objective:** Begin moving the handheld controller from Nano to ESP32.
- **Hardware/configuration:** ESP32; SCK GPIO18, MISO GPIO19, MOSI GPIO23, CE GPIO27, CSN GPIO26.
- **Procedure:** Compile the NRF test in the ESP32 development environment.
- **Result:** Compilation failed because `RF24.h` was missing; no radio hardware result was obtained.
- **Engineering conclusion:** The last verified wireless architecture remains Nano → standard NRF24L01 → Mega.
- **Next step:** Install/validate the RF24 library and repeat a fixed-value test before joystick integration.
- **Firmware provenance:** Configuration is recorded; no successful firmware exists for this attempt.

## 11. 2.4-inch touch LCD

- **Date:** September 2026
- **Status:** **HARDWARE ACQUIRED — INTEGRATION PENDING**
- **Objective:** Add controller HMI for battery, mode, link, sensor, rover-state, and warning information.
- **Result:** Purchased; no integration result is recorded.
- **Next step:** Identify the exact module/interface and validate it independently.

## 12. VL53L0X time-of-flight sensors

- **Date:** Purchased by 10 September 2026
- **Status:** **HARDWARE ACQUIRED — INTEGRATION PENDING**
- **Objective:** Prepare three-sensor short-range obstacle/distance sensing.
- **Hardware:** 3 × VL53L0X.
- **Result:** No validated three-sensor integrated test is recorded.
- **Next step:** Test each sensor, then resolve multi-sensor I²C addressing/XSHUT sequencing.

Proposed control targets of emergency stop below 20 cm and slowing to approximately 20 RPM from 20–100 cm remain **unvalidated control targets**.

## 13. Mechanical and mobility context

- Current prototype footprint: approximately 25 × 25 cm.
- Two-motor differential tracked drive is the intended configuration.
- Early load test up to approximately 10 kg and slope test around 15° are targets, not recorded results.
- Earlier V0 design inputs included ≈5 kg base mass, two motors, ≈56 mm drive sprocket, ≈3 km/h target speed, and a 15° slope case. These are calculations/design inputs, not measurements.
- Approximately 200 kg payload belongs only to a future scale-up concept.

## 14. Temporary test-bench strategy

- **Date:** Late September 2026
- **Status:** **PLANNED / IMPLEMENTATION DECISION**
- **Objective:** Prevent mechanical fabrication from blocking electronics work.
- **Plan:** Build one controller-side and one rover-side model-card/mock-up bench for radio, ESP32, LCD, ToF, encoder, motor, power, and firmware work.
- **Next step:** Assemble and document both benches before final packaging.

## Current verification summary

| Category | Items |
|---|---|
| Verified | BTS7960 motor drive; motor direction; standard NRF24L01 bring-up after debugging; Nano-to-Mega reception; joystick characterization; wireless joystick-to-motor control; encoder pulse detection |
| Partially verified | Encoder RPM calculation and feedback architecture |
| Acquired / pending | NRF24L01+ PA/LNA pair; ESP32; 2.4-inch touch LCD; 3 × VL53L0X |
| Planned | Encoder calibration; closed-loop speed; multi-ToF sensing; range validation; IMU; odometry; automatic mode; GNSS/RTK evaluation; later LiDAR; autonomy |

## Firmware evidence register

| Test | Exact historical source recovered? | Hardware result | Publication status |
|---|---|---|---|
| Initial BTS7960 motor test | No | Verified | Document result only; reconstruction must be labeled |
| Early Nano-to-Uno NRF stage | No | Development/debugging evidence | Do not overstate |
| Nano-to-Mega fixed-value link | No | Verified: `GOT: 123` | Document verified result |
| Joystick characterization | No | Verified measurements | Document verified result |
| Wireless joystick-to-motor | No | Verified architecture/result | Document verified result |
| Encoder integration | Partial logic/settings | Pulses detected; RPM invalid | Partial only |
| ESP32 NRF attempt | Configuration only | Compile failure; no radio result | Attempted only |

## Change log

### v1.0 — 30 September 2026

- Consolidated the August–September 2026 history.
- Preserved dated results, wiring, failures, partial tests, and firmware provenance.
- Kept acquired and future hardware separate from demonstrated functions.
