# TASK_193 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `2b54c486f2acb3702bb966d65809381c75121825a35c13592e217d7e5769e9f0`; exact target manifest SHA-256 `44c08dc8cb67c4e3dec44dbd29726602dcd74e5be771d8ba926252c7d8e95d44`. Worker `/root/so45_mtfilter_next`; lease `LEASE-CEO-WORKER-TASK_193-R1`; fencing token `1225`.

The 60 selected nonexport unwind FDE ranges are pinned to original `libMTFilterKernel.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 60 `source_assembly/` rows with call sites, 60 `ghidra_raw_batch{1,2}/` rows, three `ghidra_correction_raw/` rows, three `ghidra_postrollback_raw/` rows, source/project index, raw command/stdout/stderr receipts, and `WORKER_VERIFICATION.json` with per-byte membership, output hashes and a spread source-instruction sample. `COMPLETE.json` hashes every immutable report/code/scratch artifact.
