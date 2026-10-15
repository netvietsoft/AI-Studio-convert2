# TASK_211 R1 — libPVGImageCodec nonexport FDE static continuation

## Result

The 126 pinned, distinct zero-based nonexport FDE candidates 384–511, excluding oversized 450 and 499, map to 74,008 original ELF bytes and 18,502 AArch64 words. Every original body hash and every word was independently rechecked against the pinned SO. Ghidra's existing analyzed project has an exact function start/body for each selected range, with no listed missing instruction, body gap or extra range. Its four prior headless batches produced 125 nonempty C-like outputs and 64,056 recorded p-code operations. A spread 15/126 ordinary provenance sample checked per-instruction p-code positions/counts and C-like text.

Global **zero-based FDE index 465** is R1 raw **one-based row 466**, ELF VA `0x1ebdd8`, 2,780 bytes / 695 instructions. Its first attempt failed with `Unable to find unique hash for varnode`; a fresh, targeted 15-second-cap decompiler attempt reproduced the same error. The separate fresh-session inspection found the original exact function body and bytes unchanged. All nine private project files matched before/after both read-only processes. This row is PARTIAL: source assembly and p-code, no whole C-like body. R1 raw row 465 is a different candidate and did decompile.

## Limits and next work

These are static research outputs, not reconstructed and tested algorithms. FDE boundaries and Ghidra C-like text do not establish source semantics, ABI correctness or behavior parity. Global indices 450 and 499 were excluded for size and remain open. After this selection, 6,153 of the 6,655 nonexport FDE candidates remain unselected (including those two and earlier exclusions); no claim that the 45 SO campaign or this library is complete. Further work on index 465 should use a distinct bounded diagnostic method, not repeat the same decompiler call without new evidence.

The expired TASK_208 R1 was not modified, accepted or counted as a complete task. This TASK_211 package awaits independent CEO review; no commit/push or product gate is claimed.

## Reproduction and evidence

`evidence_summary.json` gives pinned hashes and aggregate checks; `candidate_evidence.jsonl` binds each index, VA, body hash, raw evidence hash and C-like/PARTIAL status. `inherited_task208_r1/` carries the exact source assembly, Ghidra raw output and original command logs. `row466_retry_command.json` and `row466_fresh_verify_command.json` bind new headless commands, stdout/stderr, project hashes and results.
