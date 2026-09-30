# Engineering Roadmap

Checkboxes indicate completion only where the development log records a physical result.

## Phase 1 — Core drive validation

- [x] Demonstrate BTS7960 control of one 12 V DC worm-geared motor
- [x] Demonstrate motor stop and opposite-direction operation
- [ ] Validate two-motor differential tracked drive on the assembled chassis
- [ ] Validate emergency-stop behavior

## Phase 2 — Wireless manual control

- [x] Bring up standard NRF24L01 modules after debugging
- [x] Receive a fixed value (`GOT: 123`) on the Mega
- [x] Transmit real joystick X/Y data from Nano to Mega
- [x] Produce physical motor movement from wireless joystick input
- [ ] Characterize packet loss, latency, and interference under motor operation

## Phase 3 — Encoder feedback

- [x] Detect pulses from the 20-slot optical encoder
- [ ] Determine correct pulses-per-revolution and edge-counting configuration
- [ ] Validate RPM against an independent reference
- [ ] Implement and validate closed-loop speed control

## Phase 4 — Controller hardware upgrade

- [ ] Install/validate the RF24 library in the ESP32 environment
- [ ] Bring up one NRF24L01+ PA/LNA module on ESP32
- [ ] Bring up the second PA/LNA module on Mega
- [ ] Repeat fixed-value and joystick-data tests
- [ ] Perform controlled line-of-sight range tests
- [ ] Integrate the 2.4-inch touch LCD

## Phase 5 — Distance sensing

- [ ] Bring up each VL53L0X independently
- [ ] Resolve multi-sensor I²C addressing and XSHUT sequencing
- [ ] Validate three-sensor obstacle measurements
- [ ] Validate proposed stop/slow-down rules before treating them as control limits

## Phase 6 — Integrated prototype

- [ ] Assemble temporary controller electronics test bench
- [ ] Assemble temporary rover electronics test bench
- [ ] Validate battery, BMS, fuse, conversion, grounding, and radio-supply stability as a system
- [ ] Integrate electronics with the tracked chassis
- [ ] Validate two-motor steering and soft acceleration

## Phase 7 — Mobility and load validation

- [ ] Structured forward/reverse and steering tests
- [ ] Measure slope performance; current ≈15° value is only a target
- [ ] Measure load performance; current up-to-≈10 kg value is only an early-test target
- [ ] Measure endurance and power consumption
- [ ] Validate stall protection and emergency-stop response

## Phase 8 — Future navigation/autonomy

- [ ] Add IMU
- [ ] Develop calibrated odometry
- [ ] Implement and validate automatic mode
- [ ] Evaluate GNSS / RTK GNSS
- [ ] Evaluate LiDAR
- [ ] Develop higher-level autonomous navigation
- [ ] Treat any approximately 200 kg platform as a separate future scale-up program requiring new mechanical, electrical, and safety validation
