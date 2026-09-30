# P0 Development Progress Report

- **Project:** Roverics tracked rover platform
- **Prototype:** P0 reduced-scale engineering prototype
- **Report status:** Living permanent record
- **Current through:** 1 October 2026
- **Canonical summary:** This document

This report records the development of P0 in two parts: electronics and mechanics. It is intended to remain accurate as the project progresses. Detailed source records remain in the electronics, CAD, firmware, test, and export directories linked below.

P0 is a mainly 3D-printed learning platform. It is not R1, not a production vehicle, and not evidence of a manufactured or load-rated full-size platform.

## How to read and maintain this report

Use the following evidence terms consistently:

| Status | Meaning |
| --- | --- |
| **CAD** | Geometry or an assembly exists in a model. Fabrication and operation are not implied. |
| **Slicer artifact** | A 3MF or related setup records a meaningful slicing iteration. A completed print is not implied unless recorded separately. |
| **Hand-fit** | Physical parts were manually checked together without powered operation. |
| **Bench verified** | A physical subsystem operated under the documented bench conditions. |
| **Partially verified** | Part of the intended function worked, but calibration, completeness, or acceptance criteria remain open. |
| **Acquired** | Hardware is available but its intended integration has not been verified. |
| **Planned** | Proposed work or a target; no completed result is claimed. |
| **Reconstructed** | Recreated from notes after the event; not the exact historical file or setup. |

When work progresses:

1. Add or update the detailed source record first.
2. Identify the exact mechanical revision, electronics configuration, firmware commit, and test setup.
3. Update the relevant status table here without deleting earlier failures or limitations.
4. Add a dated entry to the change log at the end of this report.
5. Create a platform release tag only when the release gate in [versioning.md](versioning.md) is satisfied.

## Overall position

P0 has substantial mechanical CAD and a physically demonstrated one-motor electronics/control chain. The electronics work has progressed from direct motor actuation through standard-NRF wireless joystick control. The mechanical work includes an Inventor full-vehicle assembly and detailed track-lane, running-gear, transmission, suspension, cabin, and track-link models.

The two streams have not yet been validated as a complete driving rover. The next shared milestone remains a **powered, instrumented single-track module**.

| Area | Strongest current evidence | Important boundary |
| --- | --- | --- |
| Electronics | Wireless joystick command caused physical motion of one motor through a BTS7960 | Exact successful historical sketches are unavailable; two-motor chassis control is not verified |
| Feedback | Optical encoder pulses were detected | RPM values were invalid/unvalidated and closed-loop control is not verified |
| Mechanics | Detailed Inventor parts, subassemblies, and full P0 assembly exist | CAD does not establish fabrication, assembly, mobility, strength, or load capacity |
| Track drive | Approximately 6.35 mm-pitch chain was measured and a revised 8-tooth sprocket reportedly showed promising hand fit | No documented powered track test exists |
| Integrated P0 | Mechanical and electrical architectures are represented | No documented complete driving rover, loaded test, slope test, or endurance test exists |

---

# Part I — Electronics and Control

## 1. Objective and current boundary

The electronics effort is developing a modular manual-control and sensing architecture for P0. The verified path uses an analog joystick and Arduino Nano transmitter, standard NRF24L01 radios, an Arduino Mega 2560 receiver, a BTS7960 motor driver, and one 12 V DC worm-geared motor.

The detailed source records are:

- [electronics development log](../prototypes/p0/electronics/DEVELOPMENT_LOG.md)
- [hardware inventory](../prototypes/p0/electronics/HARDWARE.md)
- [test-results matrix](../prototypes/p0/electronics/tests/TEST_RESULTS.md)
- [electronics roadmap](../prototypes/p0/electronics/ROADMAP.md)
- [firmware stages](../prototypes/p0/electronics/firmware/)

## 2. Development history

| Date or period | Activity | Result and evidence status |
| --- | --- | --- |
| 20 Aug 2026 | Arduino Uno, BTS7960, and 12 V motor bench test | **Bench verified:** run, stop, and opposite-direction response at approximately PWM 80 |
| 21 Aug 2026 | Standard NRF24L01 bring-up | **Bench verified after debugging:** communication bring-up achieved; wiring, 3.3 V power, decoupling, CE/CSN, and SPI speed were important |
| 28–31 Aug 2026 | Analog joystick characterization | **Bench verified:** center approximately 509–514; recorded endpoints 0 and 1023; a neutral dead zone was required |
| 31 Aug–3 Sep 2026 | Nano-to-Mega radio link | **Bench verified:** fixed value `123` and later live joystick values were received |
| 2–3 Sep 2026 | Wireless joystick-to-motor chain | **Bench verified:** joystick input produced physical movement of one motor through the radio, Mega, and BTS7960 path |
| 3 Sep 2026 | 20-slot optical encoder test | **Partially verified:** pulses were detected; reported 117–702 RPM values were invalid/unvalidated against a stated motor maximum near 260 RPM |
| By 10 Sep 2026 | PA/LNA radios, three VL53L0X sensors, and display-related hardware | **Acquired:** integration and performance remain unverified |
| Sep 2026 | ESP32 radio migration attempt | **Attempted:** compilation stopped because `RF24.h` was missing; no radio result was obtained |
| Late Sep 2026 | Temporary controller-side and rover-side bench approach | **Planned/decision:** intended to keep electronics integration independent of final mechanical packaging |
| 30 Sep 2026 | Electronics records and reconstructed reference firmware committed | **Repository milestone:** historical evidence consolidated with provenance warnings |

## 3. Demonstrated signal chain

```mermaid
flowchart LR
    J[Analog joystick] --> N[Arduino Nano]
    N --> TX[Standard NRF24L01]
    TX -. 2.4 GHz link .-> RX[Standard NRF24L01]
    RX --> M[Arduino Mega 2560]
    M --> B[BTS7960]
    B --> D[One 12 V DC worm-geared motor]
    E[20-slot optical encoder] -. pulses detected;<br/>RPM not validated .-> M
```

This diagram represents the strongest demonstrated electronics chain. It does not represent two-motor steering, a powered track, or a complete rover test.

## 4. Verified and partial results

| Function | Configuration | Current conclusion | Remaining work |
| --- | --- | --- | --- |
| Direct motor actuation | Uno → BTS7960 → one motor | **Bench verified** for basic speed/direction commands | Measure voltage, current, temperature, load, stall response, and endurance |
| Standard radio bring-up | Nano/Uno and standard NRF24L01 modules | **Bench verified after debugging** | Record module identities; characterize supply margin and motor-noise susceptibility |
| Joystick input | Nano A0/A1, switch D2 | **Bench verified** for the tested joystick | Record exact dead zone and repeatability |
| Fixed-value wireless link | Nano → Mega, address `00001`, channel 76, 250 kbps | **Bench verified** with `GOT: 123` | Measure packet loss, latency, and range |
| Wireless motor command | Joystick → Nano → radio → Mega → BTS7960 → motor | **Bench verified** for one motor | Validate two channels, differential mixing, link-loss behavior, and E-stop |
| Encoder pulse input | 20-slot disk, Mega D2 | **Partially verified** | Determine real pulses/revolution, condition signal, and compare with an independent tachometer |
| ESP32 radio path | ESP32 GPIO18/19/23, CE27, CSN26 | **Attempted, not validated** | Install/lock RF24 dependency and repeat fixed-packet bring-up |

## 5. Hardware status

### Used in verified work

- Arduino Uno
- Arduino Nano
- Arduino Mega 2560
- standard NRF24L01 modules
- analog joystick
- BTS7960 motor driver
- one 12 V DC worm-geared motor
- 20-slot optical encoder for pulse-detection work

The development record lists the motor as approximately 260 RPM maximum, approximately 1.6 A nominal, and approximately 8 A stall. These are recorded development values, not independently verified specifications in this repository.

### Acquired or under integration

- ESP32 controller candidate
- pair of external-antenna NRF24L01+ PA/LNA modules
- 2.4-inch touch LCD
- three VL53L0X time-of-flight sensors
- 4S Li-ion battery, approximately 2200 mAh, 14.8 V nominal and 16.8 V full
- 40 A BMS
- 20 A main fuse
- LM2596-based conversion considered or used during development

No completed integrated power-system, PA/LNA range, LCD, or three-sensor test is documented.

## 6. Firmware status and provenance

The repository contains seven numbered firmware stages under [electronics/firmware](../prototypes/p0/electronics/firmware/):

1. motor test;
2. NRF24L01 bring-up;
3. Nano-to-Mega wireless link;
4. joystick characterization;
5. wireless motor control;
6. encoder test; and
7. ESP32 NRF attempt.

The included `.ino` files are explicitly labeled **reconstructed reference firmware**. They implement the documented wiring and intended behavior, but they are not the exact historical sketches used in the physical tests. Compiling reconstructed code does not retroactively validate it on hardware.

The reconstructed wireless motor receiver adds useful reference safety behavior—a 500 ms link-loss stop, gradual PWM changes, and stop-before-reverse—but those additions are not yet recorded as physically verified.

## 7. Electronics problems and risks

- The exact successful historical firmware is unavailable.
- At least one standard NRF24L01 became abnormally hot during debugging; its failure cause is unresolved.
- Radio range, packet loss, latency, interference, and PA/LNA supply behavior are unmeasured.
- Encoder RPM is not trustworthy until independently calibrated.
- Two-motor mixing and complete tracked steering are not verified.
- Battery, BMS, fuse, conversion, grounding, and rail stability have not been tested as an integrated system.
- BTS7960 current-sense feedback and stall protection are not validated.
- Emergency-stop behavior is planned but not verified.
- LCD and multi-VL53L0X integration are pending.

## 8. Electronics next actions

1. Build and photograph controller-side and rover-side test benches.
2. Recover or replace the historical firmware with versioned, physically tested source.
3. Lock toolchain, board packages, and RF24 library versions.
4. Re-establish a fixed-packet link, then joystick data, using the intended radios.
5. Calibrate the encoder against an independent speed reference.
6. Instrument motor voltage, current, speed, and temperature.
7. Validate link loss, stop-before-reverse, E-stop, fuse, and power-isolation behavior.
8. Integrate the electronics with one mechanical track lane before attempting a full rover.

---

# Part II — Mechanics

## 1. Objective and current boundary

The mechanical effort develops the P0 tracked chassis, running gear, suspension, transmission, enclosure, and packaging in Autodesk Inventor. Inventor source files are authoritative; selected printable/review artifacts are stored separately under [mechanical exports](../prototypes/p0/mechanical/exports/).

The current import includes a full P0 assembly plus detailed subsystem assemblies. It also contains historical versions, failed concepts, slicer artifacts, and downloaded component models. Their presence documents iteration, but does not mean every file represents a current, fabricated, or tested design.

## 2. Development reconstructed from available artifacts

The original mechanical work was not accompanied by a dated engineering log. The following sequence is reconstructed from filenames, directory organization, stored file timestamps, the CAD assembly structure, and the project owner's recorded context. It should be refined when dated notes or photographs become available.

| Development area | Repository evidence | Status |
| --- | --- | --- |
| Track-link concept | Inventor track-link source, rod geometry, STL/3MF iterations, failed link model | **CAD / slicer artifacts** |
| Sprocket and chain engagement | Multiple Inventor sprocket parts/assemblies, a drawing, printable artifacts, and the separately reported FreeCAD sprocket work | **CAD; reported hand-fit for the revised 8-tooth sprocket** |
| Wheel system | Parametric wheels in several sizes, end-wheel and double-wheel assemblies, shafts, roller assemblies, and connectors | **CAD** |
| Bogie and running gear | Bogie assembly, middle-wheel link, lane-chassis assemblies, idler support, roof/support structure | **CAD** |
| Suspension | Custom RC shock-absorber parts, assembly, larger variant, and failed/older iterations | **CAD / slicer artifacts** |
| Motor transmission | Shaft parts and assemblies, coupling/connector work, GT2 pulley references, sprocket-shaft assemblies, and documented failed transmission concepts | **CAD / printable exports** |
| Encoder mechanics | Optical-counter disk model and print artifacts | **CAD / slicer artifacts; electronic pulse detection separately verified** |
| Cabin and packaging | Cabin chassis, second floor, cover, battery pack, motor, and BTS7960 envelope models | **CAD** |
| Whole vehicle | `Roverics P0 Assembly.iam` and a rendered assembly image | **CAD only** |

Historical file timestamps suggest work across June–August 2026, followed by repository consolidation on 1 October 2026. Filesystem timestamps are not treated as proof of fabrication or test dates.

## 3. Current CAD organization

The principal source areas are:

- `MasterParameters.ipt` and `MasterParameters-params.xml` for shared parameter work;
- `Track Connector Link/` for the current track-link source;
- `Lane Chassis/` for the lane structure, wheels, bogie, idler, suspension, and covers;
- `Sp Rocket Gear/` for sprocket, shaft, connector, and assembly iterations;
- `Motor Shaft/` for the current shaft design plus explicitly retained failed concepts;
- `Optocounter/` for the encoder disk;
- `Cabin/` for enclosure and component-envelope integration;
- `Full Assembly/Roverics P0 Assembly.iam` for the full CAD configuration;
- `Parts/` for bearings, couplings, rods, and downloaded/imported pulley references; and
- `mechanical/exports/` for selected STL and rendered output.

At the current snapshot, 22 non-history Inventor assembly files were identified outside folders named OldVersions, Failed Models, Faield Tests, and MIRRS. This count is descriptive, not a release configuration. A proper released configuration must list exact part IDs and revisions.

## 4. Mechanical evidence and conclusions

| Item | Evidence | Conclusion allowed now | Not yet established |
| --- | --- | --- | --- |
| Full P0 layout | Inventor full assembly and rendered image | A complete-looking rover arrangement has been modeled | That the complete arrangement was fabricated, assembled, or driven |
| Track lane and bogie | Lane, bogie, wheel, shaft, idler, and support models | Detailed running-gear architecture exists in CAD | Alignment, tension range, wear, derailment behavior, and load performance |
| Track link | Editable Inventor model and print/slicer iterations | Track-link geometry has been iterated | Material life, pin wear, tensile strength, or reliable powered circulation |
| Small chain | Project-owner measurement of approximately 6.35 mm pitch | A provisional chain-pitch basis exists | Standard designation, tolerance, multi-pitch measurement, roller dimensions, and traceable measurement record |
| Revised sprocket | 8-tooth model/export and reported promising manual engagement with the real chain | **Hand-fit**, promising enough for further testing | Powered engagement, tooth loading, wear, efficiency, retention, or service life |
| Wheel variants | Multiple parametric sizes and assemblies | Several running-gear options were explored | Selected release geometry and comparative test result |
| Suspension | Custom shock-absorber CAD and print artifacts | A compact suspension concept was developed | Spring/damping rates, travel, fatigue, side-load behavior, or loaded response |
| Motor/transmission | Motor envelope, shaft, pulley, sprocket, connector, and assembly models | Packaging and transmission concepts exist | Final reduction, torque margin, key/coupling strength, bearing life, or thermal performance |
| Cabin | Enclosure, cover, battery, driver, and motor envelope models | Packaging space has been modeled | Physical fit, ventilation, service access, ingress protection, or structural performance |
| 3MF files | Meaningful slicer iterations retained in Git LFS | Slicing decisions can be preserved | A successful print unless a separate print/test record says so |

## 5. Work explicitly not demonstrated

The repository does not currently document:

- a powered single-track run;
- a complete driving P0 rover;
- synchronized or differential two-track motion;
- measured track tension or alignment acceptance limits;
- measured motor current, speed, or temperature while driving a track;
- a controlled load, slope, endurance, obstacle, or terrain test;
- a validated 10 kg P0 load target;
- a validated 100 kg or 200 kg platform capacity;
- structural analysis or a safety factor tied to a released configuration; or
- any R1 fabrication or production validation.

## 6. Mechanical configuration and repository risks

- Stable part IDs and released revisions have not yet been applied to the imported Inventor filenames.
- Multiple project files, older assemblies, mirrored parts, failed concepts, and spelling variants make the authoritative configuration ambiguous without an Inventor dependency report.
- `OldVersions`, failed-model, MIRRS, G-code, and obsolete mesh content is present in the current Git history even where later ignore rules prevent new additions.
- Some pulley, motor, driver, and gearbox models appear to be downloaded references. Their origin, author, license, modification state, and redistribution rights are not yet recorded.
- STL is not an authoritative editable source. Selected STL exports should identify their Inventor source and revision.
- 3MF files are intentionally preserved as slicer-development evidence, but need slicer version, printer/material profile, key overrides, and print-result status.
- No Inventor version is recorded in the CAD README yet.

## 7. Mechanical next actions

1. Open the full assembly with the intended Inventor version and produce a dependency/Pack-and-Go audit.
2. Identify the current authoritative assembly and remove or quarantine broken, duplicate, and unlicensed references in a separate reviewed change.
3. Record provenance and redistribution rights for every downloaded component model.
4. Assign stable part IDs and `Rev A` only to definitions selected for fabrication/test; do not rename the full tree blindly.
5. Create a configuration sheet for the first powered single-track module.
6. Measure the chain over multiple pitches and record pitch, roller diameter, inner width, measurement tool, uncertainty, and photographs.
7. Record the exact 8-tooth sprocket source/revision used for the hand-fit observation.
8. Define track alignment, tension, and derailment observations for the first powered test.
9. Instrument the track module for voltage, current, speed, temperature, and run duration.
10. Add photographs and a test record before promoting any result from CAD/hand-fit to bench verified.

---

# Shared Integration Milestone

## Powered, instrumented single-track module

This is the next milestone for both workstreams. It is complete only when the repository contains:

- a configuration record listing mechanical part IDs/revisions, electronics revision, and firmware commit;
- the motor, reduction, sprocket, track/chain, wheel/bogie, tension, power, and controller configuration;
- a safe fixture and stop/isolation method;
- calibrated or identified voltage, current, speed, and temperature instruments;
- a documented procedure and acceptance criteria;
- raw observations covering startup, steady running, stopping, reversing, and representative disturbance/load;
- photographs or video of the actual setup;
- failures, skips, derailments, overheating, radio loss, and other anomalies; and
- a conclusion that says exactly what was demonstrated and what remains unknown.

Passing this milestone will not by itself validate a complete rover, a payload capacity, or R1.

# Current priorities

| Priority | Owner | Deliverable |
| --- | --- | --- |
| 1 | Mechanical | Authoritative single-track configuration and chain/sprocket measurement record |
| 2 | Electronics/control | Reproducible physically tested motor-control firmware and instrumented power setup |
| 3 | Shared | Powered single-track test plan, safety review, and configuration sheet |
| 4 | Shared | Executed test record with raw evidence and explicit conclusions |
| 5 | Mechanical | Part IDs/revisions for the tested configuration |
| 6 | Electronics/control | Encoder calibration, link-loss validation, and current/temperature logging |

# Change log

## 1 October 2026 — Initial permanent report

- Consolidated the electronics history recorded for August–September 2026.
- Recorded the distinction between verified historical results and reconstructed firmware.
- Inventoried the imported P0 mechanical CAD, assemblies, exports, failures, and reference-model risks.
- Recorded the approximately 6.35 mm chain measurement and revised 8-tooth sprocket hand-fit as provisional/hand-fit evidence.
- Kept P0, R1, targets, CAD, hand-fit, and physical test claims separate.
- Established the powered, instrumented single-track module as the next shared milestone.
