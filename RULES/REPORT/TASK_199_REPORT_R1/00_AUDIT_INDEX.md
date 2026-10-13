# TASK_199 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `c4653848d9b16fa2056b7d39104e5c16bcd2826369468911944a5a322050a312`; exact target manifest SHA-256 `352dbf177177c589a4fe939df7f4d97e594ce37fb32ee8b2ad23c11a7309aaee`. Worker `/root/so45_imagecodec_internal`; lease `LEASE-CEO-WORKER-TASK_199-R1`; fencing token `1232`.

The 60 selected nonexport unwind FDE ranges are pinned to original `libPVGImageCodec.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 60 source_assembly and 60 ghidra_raw_batch rows, six ghidra_correction_raw and six fresh ghidra_postrollback_raw rows. WORKER_VERIFICATION.json records exact per-byte membership, every source/P-code position, C-like digests, before/after project hashes and a spread sample. CALL_SITES.json records original static call sites. COMPLETE.json seals the immutable report, code and private scratch inventory.
