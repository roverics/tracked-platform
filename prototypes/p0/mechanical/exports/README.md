# Mechanical Exports

Commit only exports that help review, interchange, fabrication, or reproduce a documented configuration:

- STEP for useful neutral solid geometry;
- PDF for released drawings; and
- DXF only for deliberate 2D manufacturing geometry;
- STL for a deliberate printable or review mesh; and
- 3MF when it preserves a meaningful final slicer trial, including settings that are not captured by STL.

Do not commit routine or duplicate exports. For a retained STL or 3MF, link it to the authoritative source and part revision. For 3MF slicer projects, also record the slicer/version, printer and material profile, important overrides, and whether the file was actually printed or only prepared.

