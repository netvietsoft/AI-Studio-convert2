# TASK_216 R1 — libPVGImageCodec nonexport FDE continuation

The next 128 pinned VA-sorted nonexport FDE candidate spans, global zero-based indices 512–640 excluding oversized index 555, cover 86,676 original ELF bytes / 21,669 AArch64 instruction words. All source-body hashes and every original instruction word were reverified against the pinned ELF and PT_LOAD mapping. No selected range overlaps another FDE or an exported body in the source census.

Four sequential private Ghidra headless batches produced 128/128 nonempty C-like outputs and 80,682 recorded p-code operations. All have exact Ghidra function starts and range membership with no missing listing slot, body gap or extra function-body byte. This does **not** prove exact original source function boundaries. A spread sample of 13/128 (10.16%) independently rechecked every sampled p-code row address and operation count against raw output. Source bytes and instruction words were checked 128/128. Raw commands, logs, generator hash and all 9 private project file hashes were rechecked. No metadata changed; fresh-session rollback was not applicable.

Oversized index 555 (VA `0x1f8bc4`, 4,796 bytes) remains unselected. Earlier open indices 450 and 499 and index 465 lacking C-like also remain separate limitations. These C-like outputs are static research, not source-equivalent algorithms or behavior parity. No product Phase PASS, V4 implementation, or full SO completion is claimed. This report awaits independent CEO review before any commit/push.

`candidate_evidence.jsonl` binds each range/hash/output status; `source_spread_recheck.json` records the ordinary provenance sample; `evidence_summary.json` records totals and command/project checks.
