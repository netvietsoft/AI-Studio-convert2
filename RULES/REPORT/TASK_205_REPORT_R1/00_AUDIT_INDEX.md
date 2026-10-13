# TASK_205 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `4eb23a8ff4eb3345be6a3bb61f353725377a45f5fdcf1c8070e402d2bf2906ac`; exact target manifest SHA-256 `fb7fc5d6f7ef0bb067a0989263bffc60b75a1be40e3ac2c39b9c7759b8666d12`. Worker `/root/so45_imagecodec_internal`; lease `LEASE-CEO-WORKER-TASK_205-R1`; fencing token `1240`.

The 126 selected nonexport unwind FDE ranges are pinned to original `libPVGImageCodec.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 126 source_assembly and 126 ghidra_raw_batch rows, two ghidra_correction_raw and two fresh ghidra_postrollback_raw rows. WORKER_VERIFICATION.json records exact per-byte membership, every source/P-code position, C-like digests, before/after project hashes and a spread sample. CALL_SITES.json and BRANCH_SITES.json record original static sites. COMPLETE.json seals the immutable report, code and private scratch inventory.
