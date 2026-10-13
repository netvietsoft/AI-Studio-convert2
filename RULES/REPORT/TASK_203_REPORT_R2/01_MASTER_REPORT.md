# TASK_203 R2 - correct whole-FDE C-like evidence labels

The R1 window evidence mislabeled both oversized candidates as having whole-FDE C-like output. The original Ghidra function objects do have C-like text, but their bodies omit 96 original FDE bytes for #505 (`0x3cd44..0x3cda3`) and 660 bytes for #556 (`0x4e7e8..0x4ea7b`). Neither C-like output establishes coverage of the whole original FDE.

`window_evidence_corrected.json` sets `whole_fde_c_like_present` to `false` and gives each exact body-gap explanation. It separately sets `ghidra_function_c_like_present` to `true`. The parsed R1-to-R2 delta contains exactly these three field changes per target; every other source/window value and gap context is equal to immutable R1. The raw Ghidra membership bitmaps independently reproduce both missing ranges and 756 total missing bytes.

The result remains **PARTIAL_OVERSIZED_FDE_BOUNDARY** for #505 and #556. R1 raw source, Ghidra output, C-like text, project files and CEO replay remain immutable; no Ghidra run or metadata correction occurred in R2. This correction establishes no complete source-function recovery, code/data classification, functional or pixel parity, product Phase PASS, V4/P7, or all-45-SO completion. CEO independent R2 review is pending.
