# TASK_238 R1 — libPVGImageCodec.so bounded internal candidates

**PARTIAL static research.** The exact 506 pinned nonexport FDE candidates were revalidated against the original SO: 192,464 bytes / 48,116 AArch64 instruction words. Bounded Ghidra produced 506 raw rows and 506 nonempty C-like texts, with 48,036/48,116 listing positions, 80 gaps and 145,757 p-code operations. Full FDE body membership appears in 496/506 rows.

Indices **3588** (12 overlapping bytes) and **3590** (92 overlapping bytes) overlap another Ghidra function. Their source-function boundaries remain unresolved. Thus **504 C-like candidate rows lack this specific overlap**; none is independently decoded or behavior-equivalent source code. The other membership/listing gaps remain visible in the raw rows.

The six current-slice oversized indices [3867, 3877, 4025, 4051, 4052, 4066] were skipped under the <=4,096-byte bound. Eleven older oversized indices [450, 499, 555, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523] are assigned to ACTIVE TASK_239 and are **not yet accepted**. Seven indices [1542, 1586, 1620, 1623, 1626, 1830, 1912] were independently ACCEPTED as **partial static research** in TASK_236; they are not pending here.

The 5,050/48,116 spread source positions (10.50%) rechecked with zero mismatch; the private project hashes were unchanged. These are ELF unwind FDE candidates, not proven unique source-function boundaries or recovered behavior. No native/device equivalence, product Phase PASS, V4 or P7 is claimed. Independent CEO review and commit/push remain pending.
