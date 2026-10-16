# TASK_245 R2 independent audit index

Task SHA-256 `c2f2456dd196ec59477dfe6904a1e979913c774645c70d0aef5ba43b6cefeffe`; task revision 2; exact assignee `/root/audit_245_r2`; lease `LEASE-CEO-WORKER-TASK_245-R2`; fencing token `1288`.

Canonical Standard fully read: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Read `AGENTS.md`, `Docs/rules.md`, `.ai/ceo/SO45_TO_V4_PLAN.md`, `.ai/ceo/config.json`, `.ai/ceo/state.json`, `.ai/locks.json`, the END flag and exact ACTIVE task. END flag was absent. Target manifest SHA-256 `022953118235f468192b1c56f863770300b0639d1eeb9916de057f29fac8943c`.

The pinned source SHA-256 is `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` for 5,133,080 bytes. R1's historical SOURCE path is absent in this checkout; the in-tree JNI copy `lib-core-graphics/src/main/jniLibs/arm64-v8a/libPVGImageCodec.so` has the identical expected SHA-256 and exact byte count. This substitution is disclosed.

Independent checks used pyelftools to enumerate `.eh_frame` and executable PT_LOAD segments and defined `.dynsym` functions; direct source byte slices; ARM64 Capstone decoding; per-instruction source word/address checks; raw Ghidra p-code address mapping; Ghidra body/membership checks; and C-like output shape checks. R1 report/generator/research files and mandatory controls are all hashed in `03_INPUT_HASH_INVENTORY.csv`.
