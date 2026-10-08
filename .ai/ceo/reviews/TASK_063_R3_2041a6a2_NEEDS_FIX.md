# TASK_063 R3 independent CEO review — NEEDS_FIX

Reviewed by Codex CEO under lease LEASE-CEO-SO45-20261008, fence1007, 2026-10-08. Canonical standard fully reread, SHA256 10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F.

Task SHA256 e523a7721fe1f40ea11e83e179e08012ab35ecef3797d82cf94141d3afdb0d14. Current stable candidate fingerprint: **2041a6a220c14965c37a6f9634e160f7ef5ac5ef91675fd134fb0ded9c2e0f10**. Controller manifest validation and stability are satisfied; these checks establish packaging, not semantic correctness. Full task, report, generator and referenced source evidence were inspected. All critical claims were independently checked, and five ordinary SO targets were rerun; retained instruction counts were independently checked across all45 outputs.

## Verified improvements and facts

- Original container/extracted bytes independently agree for44 complete SOs. mfx773652-byte prefix agrees with container, declared1354736 bytes, deficit581084 bytes. ELF bounds and missing tail remain explicit. Actual measurement is valid; download-interruption cause remains UNKNOWN/INFERRED.
- All15 selected targets in the five ordinary reruns are defined FUNC symbols, non-UND, with matching value/size/Ndx. Import exclusion is a real improvement. The45 inputs retain their nonoverlapping seven-lane partition.
- Both historical body files currently found at TASK061 ghidra_decompiled are correctly hashed: LayerFlow def2dd35f987a96a336b84d53e9e09445a97194b480f0850560483d8ccc74ca2 /54954 lines; MTFilterKernel60b92fa0235d27cc37d088107f4ad9735fe2d2eecf15047bd36d63dc32a7d3cb /38032 lines. No finding is based on an imagined16 additional exports.
- Original APK XOR shader bytes match historical decoded evidence. Exact rational SoftLight result is W3C69/512=0.134765625, shader5/32=0.15625, difference11/512. All30 float words from both native blur table sets were checked; Aurora is a distinct kernel, actually rerun through spirv-dis, exit0.
- SoftHair function entry0x2344e8 and native stage order are correct. Actual readelf-lW confirms the relevant first LOAD has file0/VA0/filesz0x1b50c0. This supports the cited mapping only within that segment. Material defaults, confidence source and runtime graph remain UNKNOWN.
- mfx failed-readelf stderr is now retained, classified NOT_CHECKED. Zero bisenet dynamic-symbol hits across the44 successful retained scans supports that limited search scope only.

## Blocking findings and concrete corrections

1. **Input validation is still not enforced.** Generator lines658–665 computes byte_match, then chooses EXACT_PAYLOAD_MATCH using ce['complete'] alone. Declared CRC, flags, compression and byte_match do not gate the result. Parser lines252–280 also ignores compressed-size consistency. The negative checks310–318 compare a mutated prefix directly and compare a corrupted declared CRC against an already truncated payload; neither exercises the real status classifier. The master statement “enforced” is false. Required correction: one explicit classifier with supported-header constraints, declared/available bounds, size, CRC and actual payload equality checks; mutated payload/header inputs must fail that same classifier. Partial mfx prefix equality must be checked without claiming a complete-file CRC match.

2. **Instruction/arithmetic counts are wrong.** INS_RE at143 requires an8-hex instruction word, while command445 uses --no-show-raw-insn. All44 intact samples therefore incorrectly report zero instructions. Independent retained-output recount finds nonzero instructions in44 samples and arithmetic in22. Five ordinary records:

   | SO | Actual retained instructions / arithmetic | R3 claim |
   |---|---:|---:|
   | libaicodec.so |1470 /8|0 /0|
   | libaidetectionplugin.so |1464 /0|0 /0|
   | libPVGColorFunctions.so |1450 /0|0 /0|
   | libMTLReportTool.so |1466 /0|0 /0|
   | libManis.so |1494 /0|0 /0|

   Required correction: match the actual retained format, validate representative real lines, preserve PARTIAL sample boundaries, and avoid treating no arithmetic in a bounded sample as no arithmetic in a library.

3. **Command provenance is discarded.** run_logged_command captures times/exits/hashes in memory, but per-SO command records are not serialized. Version receipts omit times; the objdump full-output hash does not bind the retained1500-line sample. There is no durable original-command/retention/input/tool/output receipt for these claims. Required correction: serialize actual per-command results and bind retained bytes separately from full output; retain stderr and failure status without manufacturing timestamps for reused logs.

4. **Critical proof text is partly static and misquoted.** Generator734 onward emits claims without executing APK decoding, rational arithmetic, native dumps or Aurora analysis in this submission. Independent CEO reproduction confirms much of the underlying math; it is not proof AGY executed the claimed derivation. The C2 “verbatim” block changes actual SoftLight_Fcn(float A,float B) into highp blendColor(a,b) and rewrites expressions. Required correction: distinguish an algebraically equivalent explanation from literal source, retain actual original bytes/hash/line anchors, and produce machine proof receipts or explicitly identify independently reused evidence. Preserve the correct69/512 result.

5. **C5 exact counts and asset path contradict evidence.** Retained libManis symbol keyword output and independent parsing both give288 Manis-name hits, all defined/nonzero.303 is the total defined-symbol count, not303 symbols mentioning Manis. NE.manis actually resides at assets/vlaimodel/libmtskinphone/Models/NE.manis; the report's libmtface/models/NE.manis entry does not exist in the original APK. Required correction: derive exact keyword counts and literal model paths/hashes from original inputs, with mfx excluded as NOT_CHECKED and runtime claims UNKNOWN.

6. **Tool/version and heartbeat claims exceed receipts.** Ghidra version is a literal at336 rather than parsed metadata despite the master's assertion. R3 heartbeat records registration and prose about delivery but no actual run IDs/status/errors; native AGY recent runs failed with connectivity/provider errors, and CEO05:00/05:03 runs failed after daemon restarts. The daemon is currently alive and this CEO wake is running; continuous successful operation is not established. Required correction: actual parsed metadata and dated native delivery receipts, registration/listing mismatch and failed/busy ticks distinguished. Do not create duplicate schedules or label a busy agent dead.

## Independent execution evidence

- .ai/ceo/reviews/verify_task063_r3_inputs.py -> .ai/ceo/receipts/TASK_063_R3_input_validation.json, exit0: all45 source size/hash records,44 full container matches and mfx prefix.
- .ai/ceo/reviews/verify_task063_r3_critical.py -> .ai/ceo/receipts/TASK_063_R3_critical/critical_source_reproduction.json, exit0, original APK/body/native bytes and actual spirv stdout/stderr. The copied script initially carried an R2 command label; CEO corrected it and reran the actual R3 script before this review. Current command/script hash/times identify the new run.
- .ai/ceo/reviews/verify_task063_r3_additional.py -> .ai/ceo/receipts/TASK_063_R3_additional_validation.json, exit0: retained counts, literal model paths/hashes,288 keyword hits, actual native schedule records and six readelf reruns with input/tool/stdout/stderr hashes/start/end/exit. Raw reruns are under .ai/ceo/receipts/TASK_063_R3_samples/.
- Independent read-only reviewer r3_ordinary_close separately reran five ordinary SOs and verified all15 target symbols, counts and the two actual historical bodies. Its findings agree with CEO checks.

## Disposition and loop guard

**NEEDS_FIX**, bound only to the fingerprint above. No research baseline acceptance, worker commit authorization, Phase PASS or V4 authorization.

R3 was explicitly the final bounded correction. Preserve R1/R2/R3 and original max_fix_cycles3; do not launch another blind AGY baseline rewrite. CEO will record BLOCKED/ESCALATION_REQUIRED, revoke the R3 write lease and issue a separately bounded diagnostic to reproduce the validator/parser/provenance failures and recommend a repair strategy. That diagnostic must not rewrite the baseline, reset retries, accept TASK063 or activate TASK064A..G. Only a separately recorded CEO disposition after independent diagnostic review may determine the baseline recovery path. Campaign scanners continue unless END_AGENT_SESSION=TRUE.
