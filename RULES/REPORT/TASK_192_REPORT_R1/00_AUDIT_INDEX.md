# TASK_192 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `583740b94edda2929900fbc38929e88041f7374558fefe1bb735e3199ae4195e`; exact target manifest SHA-256 `2c1842f80abc1a74f9e2fffe9de3ef86eb07102df660b3c5149eb21f3146f15b`. Worker `/root/so45_imagecodec_internal`; lease `LEASE-CEO-WORKER-TASK_192-R1`; fencing token `1224`.

The 64 selected nonexport unwind FDE ranges are pinned to original `libPVGImageCodec.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 64 source_assembly rows, 64 successful ghidra_raw_batch1_retry and ghidra_raw_batch2 rows, four ghidra_correction_raw rows and four ghidra_postrollback_raw rows. The first failed Ghidra command/stdout/stderr is retained with 0 output rows. WORKER_VERIFICATION.json holds per-byte membership, source/output hashes and a spread instruction sample. COMPLETE.json hashes every immutable report/code/scratch artifact.
