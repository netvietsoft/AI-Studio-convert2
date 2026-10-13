# TASK_180 R1 audit index

Canonical standard fully re-read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`.

Task SHA-256 `b7c15fcb495043e7d38b6b56183c0e30fc9256fd300c59859c8799ebfe6ab3b0`; actor `/root/so45_pvg_renderer`; lease `LEASE-CEO-WORKER-TASK_180-R1`; fence `1209`.

Only two pinned `libMTGif.so` exports are in scope. Original source, previous TASK_153/154/177 failures and analyzed project remain read-only. Full original PT_LOAD bytes, Capstone instruction coverage, CFG and copied-project hashes are in `source_and_project_index.json` and `target_*_source_cfg.json`.

Final evidence: `historical_failure_receipt.json`, `run_receipt.json`, `target_{1,2}_source_cfg.json`, `target_{1,2}/ghidra_command.json`, raw stdout/stderr/p-code/fragment JSON, and `target_{1,2}_independent_verification.json`. `COMPLETE.json` byte-hash seals the report, code and owned scratch.
