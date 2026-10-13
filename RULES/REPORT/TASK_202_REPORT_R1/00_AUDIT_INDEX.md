# TASK_202 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `c42c8d006716d3c4c8306210748a877661f663d9939671bf66ba8379e9cd7a83`; exact target manifest SHA-256 `96c5b89e78847455d4a88ac901e63f20756bf3ba9a0cdece2a315d8a8c5add13`. Worker `/root/so45_imagecodec_internal`; lease `LEASE-CEO-WORKER-TASK_202-R1`; fencing token `1234`.

The 62 selected nonexport unwind FDE ranges are pinned to original `libPVGImageCodec.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 62 source_assembly and 62 ghidra_raw_batch rows, nine ghidra_correction_raw and nine fresh ghidra_postrollback_raw rows. WORKER_VERIFICATION.json records exact per-byte membership, every source/P-code position, C-like digests, before/after project hashes and a spread sample. CALL_SITES.json records original static call sites. COMPLETE.json seals the immutable report, code and private scratch inventory.
