# TASK_204 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `a175e7b87e7e257d6623d4f650201ba091868794d54cd2d77ca7a3ebaf9d43ee`; exact target manifest SHA-256 `548a3f83bf498b047d34dd77e707c00d3644d1c8780eef4e71d8e43802874793`. Worker `/root/so45_mtfilter_next`; lease `LEASE-CEO-WORKER-TASK_204-R1`; fencing token `1241`.

The 127 selected nonexport unwind FDE ranges are pinned to original `libMTFilterKernel.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 127 `source_assembly/` source-word/call records; 127 first-pass `ghidra_raw_batch1..5/` records; four each `ghidra_correction_raw/` and `ghidra_postrollback_raw/` records; seven command/stdout/stderr receipts; exact source/project index and `WORKER_VERIFICATION.json` with boundary and source-word spread checks. `COMPLETE.json` hashes immutable report, code and scratch artifacts.
