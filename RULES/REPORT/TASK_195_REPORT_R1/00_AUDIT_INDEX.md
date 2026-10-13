# TASK_195 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `192bb1097373259379a04d095e3c3037c63a272256836284e2cec9d2ed1a624f`; exact target manifest SHA-256 `d2c6de5a699068c60e4a081a87349234f8878952c7a4a9a9248d2b3ae02c0901`. Worker `/root/so45_imagecodec_internal`; lease `LEASE-CEO-WORKER-TASK_195-R1`; fencing token `1229`.

The 64 selected nonexport unwind FDE ranges are pinned to original `libPVGImageCodec.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 64 source_assembly and 64 ghidra_raw_batch rows, 11 ghidra_correction_raw and 11 fresh ghidra_postrollback_raw rows. WORKER_VERIFICATION.json records exact per-byte membership, every source/P-code position, C-like digests, before/after project hashes and a spread sample. CALL_SITES.json records original static call sites. COMPLETE.json seals the immutable report, code and private scratch inventory.
