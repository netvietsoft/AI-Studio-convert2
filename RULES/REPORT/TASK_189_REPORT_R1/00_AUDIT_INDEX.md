# TASK_189 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `a6a132170d264727ea7cd0cec13954b132d577b0f6e37594f0f109b06748757e`; exact target manifest SHA-256 `569b5f8348e847139cc90ec5e42023a4360724d98210101c83003a86e3587693`. Worker `/root/so45_mtfilter_next`; lease `LEASE-CEO-WORKER-TASK_189-R1`; fencing token `1221`.

The 64 selected nonexport unwind FDE ranges are pinned to original `libMTFilterKernel.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 64 `source_assembly/` rows, 64 `ghidra_raw_batch{1,2}/` rows, 14 `ghidra_correction_retry_raw/` rows, 14 `ghidra_postrollback_raw/` rows, source/project index, raw first-failure and retry command/stdout/stderr, and `WORKER_VERIFICATION.json` with per-byte membership, output hashes and a spread source-instruction sample. `COMPLETE.json` hashes every immutable report/code/scratch artifact.
