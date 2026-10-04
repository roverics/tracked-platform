# Evidence for the Platform & Progress page

Keep original evidence in this repository. Publish optimized copies in the website's `public/progress/media/` folder after reviewing them for private information and third-party ownership.

## Where to put files

- Whole-prototype photographs: `prototypes/p0/photos/`.
- Mechanical photographs: `prototypes/p0/mechanical/photos/`.
- Electronics photographs: `prototypes/p0/electronics/photos/`.
- Test evidence: `prototypes/p0/tests/YYYY-MM-DD-short-test-name/` containing a README, measurements, photographs and video or a durable video reference.
- Editable models: `prototypes/p0/mechanical/cad/`.
- Selected STL/STEP/drawing exports: `prototypes/p0/mechanical/exports/`.

Use descriptive filenames and preserve original resolution. Do not commit large videos blindly; check file sizes and choose LFS or durable external storage first. Current ignore rules exclude `.log`, so preserve measured data deliberately as CSV or review an explicit exception.

Copy `prototypes/p0/tests/TEST-RECORD-TEMPLATE.md` into a new test folder as `README.md`. Fill unknown fields as unknown rather than guessing. A photograph shows physical state, while motion claims require an observation record or video. A CAD render establishes geometry, not fabrication or performance.

## Website media

Use JPEG/WebP images and optimized GLB models for public display. STL can be viewed with a compatible Three.js loader, but it lacks assembly hierarchy and standard material/color information. Keep the source export and record which source/revision produced the web model.

The page now uses the P0 CAD render and reviewed mechanical/electronics photos. Step 3 includes an on-demand STL viewer with rotate, pan, zoom, wireframe and original-file downloads. See [the media review](evidence-media-review-2026-10-04.md) for specific claim boundaries.
