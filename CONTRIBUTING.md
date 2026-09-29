# Contributing

This project currently uses a lightweight two-person workflow. Keep changes small enough that the other discipline can understand their effect on interfaces.

## Working agreement

1. Start from an up-to-date default branch and use a short-lived branch such as `mechanical/track-tensioner` or `controls/motor-current-log`.
2. Commit one coherent change at a time using an imperative subject, for example `Revise sprocket tooth profile`.
3. Open a pull request for changes that affect the other discipline, shared interfaces, safety, test conclusions, or a release candidate.
4. State what changed, why, evidence level, affected part revisions, and how it was checked.
5. The other contributor reviews cross-discipline changes. The author may merge isolated documentation fixes after checking the rendered diff.

Direct commits may be used for urgent or trivial fixes while the team is small, but tested milestones should still be reviewed and tagged from a clean default branch.

## Documentation rules

- Separate observation from inference and target. Prefer “8-tooth sprocket hand-fit to the measured chain” over “sprocket validated.”
- Attach units to every physical value and record the instrument or method when it matters.
- Date test records with ISO dates (`YYYY-MM-DD`).
- Link results to exact part revisions, firmware commit, electronics revision, and configuration.
- Put reusable decisions in [`docs/design-decisions/`](docs/design-decisions/), not only in chat or commit messages.
- Do not commit credentials, personal contact details, customer-confidential material, or location metadata from photos.

## CAD and generated files

- Keep editable source CAD when ownership is clear.
- Add useful neutral exports (normally STEP) and drawings when they help review or fabrication.
- Do not commit slicer output, autosaves, backups, caches, or routine mesh exports. Commit an STL/3MF only when it is a deliberate release artifact that cannot be reproduced conveniently, and document why.
- Use Git LFS for tracked binary CAD and large media types covered by [`.gitattributes`](.gitattributes). Verify LFS is installed before adding them.
- Record third-party references with origin, author, license, retrieval date, and whether redistribution is permitted. If ownership is unclear, keep the file out of the repository.

## Tests

Test records belong under [`prototypes/p0/tests/`](prototypes/p0/tests/) and should begin from its template. Failed tests are useful evidence; keep them and describe the resulting action.
