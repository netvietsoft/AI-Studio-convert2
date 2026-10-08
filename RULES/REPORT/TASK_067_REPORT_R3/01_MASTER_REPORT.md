# TASK067 R3 packaging correction of historical R2 diagnostic

The measured R3 failures arise from an unenforced status gate, a disassembly-format mismatch and static proof text that is not derived from the cited original inputs. This diagnostic demonstrates those causes without modifying TASK063 or accepting its baseline.

## Input-status cause and counterexamples

The actual AST-extracted R3 `byte_match` assignment and `if ce['complete']` branch are compiled independently; mutating main is never imported or executed. `raw/source_anchors.json` binds each original line range and extracted fragment to SHA256. The original parser is executed with BytesIO over exact local header/payload slices. Slices rebase header offset to zero; original container coordinates and header hex remain in `raw/input_cases.json`.

For the complete real libaicodec control, old and reference statuses are EXACT_PAYLOAD_MATCH. Changing a payload byte, declared CRC, flags, method or compressed size still produces old EXACT_PAYLOAD_MATCH. The same reference function rejects each. A changed declared size yields old PARTIAL_CONTAINER_TRUNCATED, whereas the reference rejects stored-size inconsistency. Thus old classification does not enforce its calculated byte_match or header/CRC constraints.

For actual mfx, both inputs contain only 773652 bytes of declared 1354736, deficit 581084. Original container prefix and disk agree; full-file declared CRC cannot be checked. Old partial status and its generated note remain unchanged even when the prefix is corrupted; reference rejects the payload mismatch. Changing only mfx declared CRC intentionally stays partial/UNKNOWN in the reference: there is no full tail against which to validate that CRC. This case is not presented as a corruption detector. Flags/method/size inconsistencies are rejected by the same reference function. Reference only supports flags0/stored-method0 for these measured controls, not a general ZIP validator. Header/data bounds and prefix/CRC distinctions are explicit in JSON.

## Retained-format cause

R3 INS_RE requires an eight-hex instruction word while its objdump command uses --no-show-raw-insn. All five old counts are zero. Measured retained instruction/arithmetic counts are libaicodec1470/8, libaidetectionplugin1464/0, libPVGColorFunctions1450/0, libMTLReportTool1466/0 and libManis1494/0. Each file contains1500 retained text lines. Literal examples, line anchors, address/mnemonic/operands and text-versus-instruction counts are in raw/parser_cases.json.

Malformed checks reject nonhex addresses, labels, question-mark mnemonics, raw-word format, unaligned addresses, headings and empty lines. This parser validates the demonstrated no-raw-insn syntax, not every AArch64 opcode. Zero arithmetic in a bounded sample says nothing about the rest of that library. No new full disassembly/decompilation was run.

R3 captures full-output receipts transiently, retains only the first1500 lines, and does not serialize per-SO receipt objects. A full-output hash cannot independently identify the retained bytes. Historical per-SO command start/end/exit remain UNKNOWN; no file-mtime reconstruction was used. Existing hashes bind the present retained samples; they do not retroactively prove original command execution. The original R2 lightweight libManis readelf execution has real tool/input/start/end/exit/stdout/stderr hashes in raw/critical_cases.json.

## Critical-provenance causes and controls

Original APK C2 bytes were actually read and XOR decoded during the original R2 diagnostic. Decoded source contains SoftLight_Fcn and does not contain blendColor, whereas R3 labels its rewritten blendColor block verbatim. Literal decoded bytes and SHA256 are retained in raw/C2.decoded.fs; original encrypted entry bytes are retained too. Equivalent algebra, if established separately, would not make that block a literal quotation.

Original APK contains assets/vlaimodel/libmtskinphone/Models/NE.manis; the claimed libmtface/models/NE.manis path is absent. Actual entry hash/size are in results. Original R2 libManis readelf gives303 defined nonzero symbol records, of which288 names contain case-insensitive manis. The cause is conflating total defined records with keyword hits. All hit lines are retained with actual readelf output.

Known-good controls are explicitly reused from CEO critical_source_reproduction.json with measured current receipt/input hashes: SoftLight69/512 versus5/32, difference11/512;30 native float words; historical Ghidra FilterToFBO text identifier0x002344e8 and body-text anchors. These are hash-bound historical reuse, not a claim this worker reran the CEO math/decompilation/spirv command. Ghidra current application.properties is hashed with literal version/build lines. Historical heartbeat receipts are reused with their actual statuses; current provider availability and continuous successful delivery remain UNKNOWN.

## Execution and limits

Initial harness guard used nonexistent leases key and exited1 before measurement/writes. Correcting it to active_locks allowed the same bounded attempt to execute successfully. Initial exact timing/script hash and original parent stdout byte capture are UNKNOWN; a labeled session-transcript summary is in raw/harness_initial_failure.txt. Successful script SHA matches02_DIAGNOSTIC_RESULTS.json and current file. Actual child stdout/stderr are preserved. Eleven meaningful diagnostic assertions passed; this is neither Phase PASS nor independent acceptance.

No15-target readelf rerun was needed: target correctness was not disputed by the CEO review; this task investigates counts and provenance. No product build/device QA is required for isolated diagnostic artifacts; no product PASS is claimed. PROJECT_ERROR/ACQUIREMENTS were read, but durable-memory edits are outside this lease; reusable findings are proposed for CEO disposition only. Model architecture, runtime loader/producer, confidence, material defaults, missing mfx tail and truncation cause remain UNKNOWN.

During R2 only its script/report scope was written; R3 writes only its own packaging script/report scope. Original SOURCE, R3, production/P0 and CEO state were not edited. Existing unrelated workspace changes were preserved. No baseline/lane regeneration, downstream activation, commit/push or duplicate heartbeat occurred. Submit REVIEW_CANDIDATE_AWAITING_CEO; TASK063 remains blocked pending separate CEO disposition.

## R3 packaging correction and superseding address limitation

R3 copied original R2 result/raw artifacts byte-for-byte without changing their revision2 labels, internal timestamps or hashes. These labels describe historical origin, not current R3 execution. R3 current task/fence and packaging execution are bound separately by COMPLETE and raw/package_execution.json. The copy-provenance table and current immutable-reference checks are in04_PROVENANCE.json. No diagnostic producer, original package producer, native tool or heavy analysis was executed in R3.

Historical external mutable schedule hashes are recorded alongside current observed hashes in04_PROVENANCE.json; changed/missing current files are historical references, not immutable-evidence failures. Original schedule bytes at historical receipt time are unavailable in this package; current provider availability and continuous successful delivery remain UNKNOWN. The prior R2 packaging assertion failed on a changed9ed2909e schedule; original R2 package remained incomplete until its deadline expired. That failure does not invalidate the independently verified diagnostic script/result/raw bindings.

Address0x2344e8 is a historical Ghidra FilterToFBO text identifier ONLY. Per the hash-bound TASK068 ELF finding, that literal address is not a file-backed executable address in the current arm64 ELF; current image-base/ABI/address correspondence is UNKNOWN. Neither the reused body text nor tables establish body-to-current-native correspondence, a runtime pointer, native function entry or native execution order. Any stronger wording inside unchanged historical JSON is superseded by this explicit limitation.

Initial R2 guard failure KeyError leases is disclosed; the harness was changed to actual active_locks before the successful diagnostic. Exact initial parent invocation times/script hash/original stdout bytes were not captured and remain UNKNOWN. No fabricated parent capture is supplied. R3 package_execution receipt captures actual packaging child argv/start/end/exit/stdout/stderr only.

This is REVIEW_CANDIDATE_AWAITING_CEO. Diagnostic assertions and package integrity do not constitute independent acceptance, TASK063 baseline acceptance,064 dependency satisfaction or V4/product PASS. No retry budget reset. Return to own-identity scanner under existing CEO supervision.
