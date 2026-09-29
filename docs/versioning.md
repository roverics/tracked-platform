# Versioning and Releases

Whole-platform versions identify tested configurations. They are separate from part revisions and routine Git commits.

## Scheme

- P0 integration releases: `p0.MAJOR.MINOR`, for example `p0.1.0`
- R1 production-intent prereleases: `r1.MAJOR.MINOR-alpha.N`, for example `r1.0.0-alpha.1`
- Later stable R1 releases may use `r1.MAJOR.MINOR` after release criteria are defined

For a given platform stage:

- increment **MAJOR** for a configuration or interface change that invalidates prior integration assumptions;
- increment **MINOR** for a documented, backward-compatible tested milestone; and
- increment the prerelease number for successive R1 candidates at the same intended version.

## Release gate

Do not create a tag merely because files were added. A release needs:

1. a committed configuration record listing mechanical revisions, electronics revision, and firmware commit;
2. a dated test record with setup, instruments, results, and known limitations;
3. reviewed release notes that distinguish CAD, hand-fit, bench, and loaded evidence; and
4. a clean commit on the default branch.

Use an annotated Git tag matching the version. No tag is created by this initial repository setup because no tested platform milestone is documented yet.
