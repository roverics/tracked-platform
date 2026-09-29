# Platform Architecture

Status: initial working boundary; not a claim that every subsystem has been built.

The platform is organized around replaceable mechanical, electrical, and software subsystems with explicit interfaces. P0 is the integration vehicle used to discover and document those interfaces before R1 requirements are frozen.

## System boundaries

| Area | Includes | Interface evidence still needed |
| --- | --- | --- |
| Running gear | Track links, sprockets, road wheels/bogies, tensioning | Geometry, tension range, wear, derailment limits |
| Structure | Chassis, mounts, enclosure | Mass, stiffness, fastening, ingress and service access |
| Drivetrain | Motor, reduction, shafts, bearings, couplings | Torque/speed envelope, thermal behavior, efficiency |
| Power | Battery, protection, distribution, conversion | Voltage/current limits, fusing, runtime, safe isolation |
| Control electronics | Motor drivers, controller, sensors, communications | Pinout, logic levels, update rates, failure states |
| Firmware | Device drivers, motion control, telemetry, safety states | Build instructions, version, commands, logged signals |
| Test system | Fixtures, instruments, data, procedures | Calibration, acceptance criteria, repeatability |

## Configuration traceability

Every integration test should identify:

- mechanical part IDs and revisions;
- electronics assembly or schematic revision;
- firmware Git commit;
- power source and limits;
- test setup and instruments; and
- raw evidence location and conclusion.

The first architecture validation target is one powered, instrumented P0 track lane. A two-track chassis should follow only after the single-track risks and interfaces are understood.
