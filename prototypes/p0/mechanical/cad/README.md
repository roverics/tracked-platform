# Editable CAD Sources

Autodesk Inventor is the authoritative mechanical CAD tool for P0. Store editable Inventor parts (`.ipt`), assemblies (`.iam`), drawings (`.idw`/`.dwg`), presentations (`.ipn`), and the project file (`.ipj`) here, grouped by assembly when the source set is available. Keep referenced components together and document the Inventor release used in the nearest README.

Binary Inventor types are configured for Git LFS. Confirm `git lfs install` succeeds before adding them. Commit `.ipj` project files normally so reference paths and workspace settings are reproducible. A filename should use its stable part ID and revision once released, for example `TL-SP-001_rev-a_drive-sprocket.ipt`.

Before importing an assembly, use Inventor's dependency tools (such as Pack and Go) to identify referenced parts, then review the collected set rather than committing unrelated libraries or Content Center caches.

Do not add a downloaded reference model until origin, author, license, retrieval date, modifications, and redistribution permission are known.
