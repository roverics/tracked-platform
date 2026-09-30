# Rover-Side Hardware

## Verified rover-side chain

The verified chain used a standard NRF24L01 receiver, Arduino Mega 2560, BTS7960, and one 12 V DC worm-geared motor. Wireless joystick commands produced physical motor movement.

| Function | Mega pin |
|---|---:|
| Encoder | D2 |
| BTS7960 RPWM / LPWM | D6 / D7 |
| NRF CSN / CE | D8 / D9 |
| SPI MISO / MOSI / SCK | D50 / D51 / D52 |
| SPI SS/master | D53 |

`REN` and `LEN` were held HIGH at 5 V during relevant tests. Encoder pulses were detected, but the calculated RPM readings were invalid/unvalidated.

## Power architecture — integration ongoing

- 4S Li-ion battery, approximately 2200 mAh
- 14.8 V nominal and 16.8 V full
- 40 A BMS
- 20 A main fuse
- LM2596-based conversion considered/used during development
- 3.3 V NRF supply

No completed integrated power-system, endurance, or stall-protection validation is recorded.

## Pending rover hardware

- Second drive channel / complete differential tracked-drive validation
- External-antenna NRF24L01+ PA/LNA receiver and range tests
- Three VL53L0X sensors and multi-sensor addressing
- Calibrated encoder feedback and closed-loop speed control
- Final chassis integration, mobility, slope, load, E-stop, and power tests
