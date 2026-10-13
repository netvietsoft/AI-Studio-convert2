# TASK_197 R1 audit index

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `1106213d30261aff5d09e0283eb95b047fd36359ba821663e4796f419e13b65f`; exact target manifest SHA-256 `273d3508fb7a933cbbff362364a8e35be067892aba01620adb953a54697d1af6`. Worker `/root/so45_mtfilter_next`; lease `LEASE-CEO-WORKER-TASK_197-R1`; fencing token `1231`.

The 62 selected nonexport unwind FDE ranges are pinned to original `libMTFilterKernel.so` PT_LOAD bytes. An FDE candidate does not prove a unique source-function boundary. `source_project_index.json` holds source hashes, overlaps and a byte-verified private analyzed-project copy. `source_assembly/` holds every source instruction word and Capstone decode.

Final evidence: 62 `source_assembly/` rows with call sites, 62 `ghidra_raw_batch{1,2}/` rows, six `ghidra_correction_raw/` rows, six `ghidra_postrollback_raw/` rows, source/project index, raw command/stdout/stderr receipts, and `WORKER_VERIFICATION.json` with per-byte membership, output hashes and a spread source-instruction sample. `COMPLETE.json` hashes every immutable report/code/scratch artifact.
