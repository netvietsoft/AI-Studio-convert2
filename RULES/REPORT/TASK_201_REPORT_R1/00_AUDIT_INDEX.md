# TASK_201 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `5caebf855c995650171dd848e46aa4699e06475b3e29945a8108df04ab6a243a`; exact target manifest SHA-256 `3523ec8697b80bace822a7367bdcc226e984eb328b5b3a7f6d4a95128dbe5746`. Worker `/root/so45_mtfilter_next`; lease `LEASE-CEO-WORKER-TASK_201-R1`; fencing token `1235`.

The 62 selected nonexport unwind FDE ranges are pinned to original `libMTFilterKernel.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 62 `source_assembly/` rows with call sites, 62 `ghidra_raw_batch{1,2}/` rows, seven `ghidra_correction_raw/` rows, seven `ghidra_postrollback_raw/` rows, source/project index, raw command/stdout/stderr receipts, and `WORKER_VERIFICATION.json` with per-byte membership, output hashes and a spread source-instruction sample. `COMPLETE.json` hashes every immutable report/code/scratch artifact.
