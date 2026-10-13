# TASK_178 R1 audit index

Canonical standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Exact TASK_178 R1 SHA-256 `df47d97e77ec29934f7dde417737f70a34e9007be106992a20cdd4fb015b31dc`. Lease `LEASE-CEO-WORKER-TASK_178-R1`, fencing token `1207`. Actual executor: real Codex subagent `/root/so45_dexvmp_correction`; AGY was not used.

Original SO: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libdexvmp.so` SHA-256 `b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e`. Target ELF VA `0x29cd4`, size `224440`, SHA-256 `ffe6c5558f71b31ead9ce7055ecea778379cccd409978b5502c9cb39ff272654`. Source function bytes and two adjacent original jump tables are retained in this report. All outputs are static research, not product implementation.

Reproduction: `python -X utf8 -B scripts/task_178_codex_exports/block_inventory.py`, then `python -X utf8 -B scripts/task_178_codex_exports/verify_and_seal.py`. See `raw_command.json`, `run_stdout.log`, historical raw Ghidra receipt/log/output, `instruction_stream.tsv`, `candidate_blocks.jsonl`, `edge_inventory.tsv`, `jump_tables.json`, `independent_verification.json` and `spread_block_sample.json`. No Ghidra process or fresh import was launched for TASK_178.
