# Hardware Inventory

Status reflects evidence recorded through 30 September 2026. Specifications below are included only where the development log provides them.

## 1. Verified hardware

| Component | Known specification or configuration | Verified use |
|---|---|---|
| Arduino Uno | 5 V logic board | Initial BTS7960 motor test; early NRF receiver bench work |
| Arduino Nano | Joystick on A0/A1; switch on D2; NRF CE D9, CSN D10 | Controller input and verified wireless link |
| Arduino Mega 2560 | NRF CE D9, CSN D8, SPI D50–D52, SS D53 | Verified wireless receiver and rover controller |
| BTS7960 | Initial Uno pins RPWM D5, LPWM D6, R_EN D7, L_EN D8; later Mega RPWM D6, LPWM D7 | Motor speed/direction actuation |
| 12 V DC worm-geared motor | Stated maximum ≈260 RPM; nominal current ≈1.6 A; stall current ≈8 A | Physical forward/stop/reverse response and wireless actuation |
| Standard NRF24L01 modules | 3.3 V; address `00001`; channel 76; 250 kbps | Nano-to-Mega data link after debugging |
| Analog joystick | Center ≈509–514; axes measured from 0 to 1023 | Controller input characterization |
| 20-slot optical encoder | Signal connected to Mega D2 | Pulse detection only; RPM accuracy not verified |

## 2. Hardware used during earlier development

| Component or arrangement | Recorded use |
|---|---|
| Arduino Uno receiver | Radio-only Nano-to-Uno bench stage before the Mega receiver architecture |
| External motor power source | Powered `B+ / B-` during the initial motor-driver test |
| 10–47 µF radio-supply capacitor | Used/recommended near standard NRF24L01 supply for stability |
| LM2596-based DC-DC conversion | Considered/used during power-system development; final integration is not documented as validated |

At least one standard NRF24L01 module was considered suspicious after becoming abnormally hot during debugging.

## 3. Hardware acquired and awaiting integration

| Component | Known detail | Evidence boundary |
|---|---|---|
| ESP32 | Test wiring: SCK GPIO18, MISO GPIO19, MOSI GPIO23, CE GPIO27, CSN GPIO26 | Development environment reached; radio result not obtained because `RF24.h` was missing |
| NRF24L01+ PA/LNA pair | External-antenna modules, purchased by 10 Sep 2026 | No validated range or completed link test |
| 2.4-inch touch LCD | Intended handheld-controller HMI | Purchased; integration pending |
| 3 × VL53L0X | Short-range time-of-flight sensors, purchased by 10 Sep 2026 | No validated three-sensor integration |
| 4S Li-ion battery | ≈2200 mAh, 14.8 V nominal, 16.8 V full | Power architecture defined; integrated-system validation not recorded |
| 40 A BMS | Battery protection component | Integration ongoing; no standalone validation result recorded |
| 20 A main fuse | Main protection component | Integration ongoing; no standalone validation result recorded |

## 4. Future or planned hardware

- IMU
- Improved odometry / odometry wheel
- GNSS or RTK GNSS evaluation
- LiDAR at a later stage
- Final mechanical controller panel, approximately 20 × 14 cm, with four status LEDs, MANUAL/AUTO selector, joystick, emergency stop, main switch, charging port, and antenna provision
- Larger platform discussed around a future approximately 200 kg payload objective; this is not a demonstrated specification

The BTS7960 `R_IS` and `L_IS` feedback pins were identified, but validated stall protection was not completed.
