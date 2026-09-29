# Part Identification and Revisions

CAD history in Git, a physical part revision, and a whole-platform release are three different records.

## Identifier format

Use `TL-CC-NNN`, where:

- `TL` means tracked platform;
- `CC` is a stable two-letter class; and
- `NNN` is a sequential number within the class.

Suggested classes are `CH` chassis, `TR` track component, `SP` sprocket, `BG` bogie, `DR` drivetrain, `EN` enclosure, and `FX` fixture. For example, `TL-CH-001 Rev A` illustrates a chassis part identity; it does not assert that such a part currently exists.

Do not encode prototype stage, material, dimensions, or vendor in the permanent ID. Those can change without changing the part's identity.

## When to change revision

- Increment the revision when the form, fit, function, material specification, manufacturing definition, or acceptance criteria change.
- Keep the revision for edits that do not change the released definition, such as metadata or spelling corrections.
- Create a new part ID when interchangeability or function changes so substantially that treating it as the same part would be misleading.
- Mark physical parts where practical and record which revision was tested.

Start at `Rev A`. Revisions describe a released part definition, not every saved CAD edit. Git commits preserve edit history between revisions.

## Part register

Add rows only after the source file and ownership have been checked.

| Part ID | Revision | Description | Editable source | Released export/drawing | Status/evidence |
| --- | --- | --- | --- | --- | --- |

## Filenames

Prefer `TL-CC-NNN_rev-a_short-description.ext`. Use lowercase revision text in filenames for portability, while drawings and prose may show `Rev A`.
