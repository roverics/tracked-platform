# Engineering Test Results

| Date | Test | Hardware | Status | Key Result | Remaining Issue |
|---|---|---|---|---|---|
| 20 Aug 2026 | Initial motor-driver test | Uno, BTS7960, 12 V motor | VERIFIED | Motor ran, stopped, and operated in the opposite direction at PWM ≈80 | Original sketch is not archived; broader load testing remains |
| 21 Aug 2026 | NRF24L01 bring-up | Nano, Uno, standard NRF24L01 modules | VERIFIED AFTER DEBUGGING at module/communication-development level | Bring-up achieved after wiring, power, decoupling, CE/CSN, and SPI work | Early instability; one suspicious hot module; exact sketch unavailable |
| 28–31 Aug 2026 | Joystick characterization | Nano, analog joystick | VERIFIED | Center ≈509–514; each axis endpoints recorded at 0 and 1023; dead zone defined | Final dead-zone value not recorded |
| 31 Aug–3 Sep 2026 | Fixed-value wireless link | Nano, Mega 2560, standard NRF24L01 modules | VERIFIED | Mega received `GOT: 123` | Exact historical firmware unavailable |
| 31 Aug–3 Sep 2026 | Joystick data link | Nano, Mega 2560, standard NRF24L01 modules, joystick | VERIFIED | Real joystick X/Y values received by Mega | Range, loss, and latency not characterized |
| 2–3 Sep 2026 | Wireless motor control | Above link, BTS7960, DC motor | VERIFIED | Joystick command produced physical motor movement | Exact integrated sketch pair unavailable; two-motor chassis behavior not recorded |
| 3 Sep 2026 | Encoder integration | Mega 2560, 20-slot optical encoder | PARTIALLY VERIFIED | Pulse detection worked | Reported 117–702 RPM values conflict with stated ≈260 RPM maximum and are invalid/unvalidated |
| Sep 2026 | ESP32 NRF attempt | ESP32, NRF test configuration | DEBUGGING / ATTEMPTED | Pin configuration recorded | Compilation failed because `RF24.h` was missing; no radio result |
| By 10 Sep 2026 | PA/LNA and VL53L0X acquisition | PA/LNA NRF pair, 3 × VL53L0X | HARDWARE ACQUIRED | Components available | No validated range or sensor integration |
| Sep 2026 | Touch LCD acquisition | 2.4-inch touch LCD | HARDWARE ACQUIRED | Component available | Integration pending |

Power-system architecture and the temporary test-bench approach are documented development activities, but no completed integrated-system test result is recorded for them.
