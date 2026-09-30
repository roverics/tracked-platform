# Roverics Tracked Platform

Open engineering repository for Roverics' tracked rover platform. The current vehicle, **P0**, is a reduced-scale, mainly 3D-printed prototype used to learn about tracked mechanics, electronics, controls, and system integration. **R1** is a later full-size, production-intent platform; P0 is not a manufactured, load-rated, or production-representative R1.

This repository is owned under the **RoverX** GitHub account and uses **Roverics** as the customer-facing brand.

## Status

The project is in early prototype development. The repository now includes an imported Autodesk Inventor P0 assembly tree, selected mechanical exports, an electronics development log, and reconstructed reference firmware. Recorded work includes:

- Autodesk Inventor models for a track link and sprocket;
- a tracked-lane and bogie/chassis layout;
- enclosure design work; and
- a FreeCAD transmission sprocket manually checked against a real chain.

The small chain was measured at approximately **6.35 mm pitch** and a revised 8-tooth sprocket showed a promising hand fit. These are provisional observations until the source models, measurement method, and dated test record are added here.

There is currently no repository evidence of:

- a powered single-track test;
- a complete driving rover; or
- a validated 100 kg load capacity.

Those outcomes must not be claimed until a reproducible test record is committed.

### Evidence language

Use these terms precisely in issues, documents, and release notes:

| Level | Meaning |
| --- | --- |
| CAD | Designed or evaluated in a model; not necessarily fabricated. |
| Hand-fit | Physical parts were manually brought together; no powered operation implied. |
| Bench-tested | Operated under documented bench conditions, with the setup and results recorded. |
| Loaded-tested | Tested under a measured load with procedure, instrumentation, and acceptance criteria recorded. |

## P0 and R1

**P0** is the active learning prototype. Its dimensions, materials, and performance are provisional and may change quickly. It is intended to expose integration problems inexpensively.

**R1** is a future, full-size platform with production intent. Its requirements are being developed in [docs/r1-requirements.md](docs/r1-requirements.md). No P0 result automatically validates an R1 requirement.

Potential arm-equipped, garden-guard, and agricultural rovers are possible configurations or products built on the platform. They do not yet have separate implementations or repositories.

## Next milestone

Build and document a **powered, instrumented single-track module**. At minimum, the record should identify the configuration, motor and drivetrain, power source, track tension, test surface, commanded motion, current/voltage observations, temperatures, run time, failures, and resulting design changes. See [the P0 test guide](prototypes/p0/tests/README.md).

## Repository map

- [`prototypes/p0/`](prototypes/p0/) — P0 mechanical, electronics, firmware, tests, and photos
- [`docs/progress-report.md`](docs/progress-report.md) — permanent living progress report for electronics and mechanics
- [`docs/architecture.md`](docs/architecture.md) — system boundaries and intended interfaces
- [`docs/roadmap.md`](docs/roadmap.md) — evidence-based development sequence
- [`docs/part-revisions.md`](docs/part-revisions.md) — part identity and revision rules
- [`docs/versioning.md`](docs/versioning.md) — whole-platform release versioning
- [`docs/r1-requirements.md`](docs/r1-requirements.md) — clearly separated R1 planning
- [`docs/design-decisions/`](docs/design-decisions/) — durable engineering decisions
- [`CONTRIBUTING.md`](CONTRIBUTING.md) — two-person workflow and review conventions

## Team

- **Mechanical:** project owner — mechanical design, fabrication, and mechanical test evidence
- **Electronics and control:** collaborator — electronics, embedded software, and control test evidence
- **Shared:** interfaces, integration tests, configuration records, and release decisions

Names and contact details can be added with both contributors' consent.

## Releases and revisions

P0 integration milestones use tags such as `p0.1.0`. Later R1 prereleases may use tags such as `r1.0.0-alpha.1`. Tags describe tested whole-platform configurations; they are not substitutes for individual part revisions such as `TL-CH-001 Rev A`. No release tag should be created without a dated test/configuration record.

## License and safety

No license has been selected. Until an explicit license is added, copyright is retained and reuse rights are not granted by publication alone. Do not commit third-party CAD or downloaded reference models unless their source, license, and redistribution rights are recorded.

This is an experimental robotic platform. Repository material does not certify safety, load capacity, or fitness for a particular use.
