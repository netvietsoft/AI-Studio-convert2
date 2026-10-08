# 01_MASTER_REPORT.md — Bounded Causal Diagnostic of SO45 Verifier Failures
**Task ID:** `TASK_067` (Revision 1)  
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Worker Identity:** Codex diagnostic worker (`ace29908-a2b0-4777-a070-6bd100509738`) assigned under `7de71900-89f8-4633-97a9-3efaf42ea6b8`  
**Lease ID:** `LEASE-CEO-WORKER-TASK_067-R1` | **Fencing Token:** `1012`  
**Purpose:** Bounded causal reproduction and documentation of why TASK_063 R3 verifiers and reports made unsupported claims.  
**Constraint:** Diagnostic evidence only. Does NOT rewrite the 45-SO baseline or modify R3 artifacts.  

---

## Executive Summary of Findings

| Investigation Area | Specific R3 Claim / Code | Verified Ground Truth | Causal Root Cause |
|---|---|---|---|
| **Inv 1: Input Status Classifier** | Claimed input validation was "enforced" in R3; in-memory negative test checked `byte != disk` directly. | R3 status logic lines 658–665 selected `EXACT_PAYLOAD_MATCH` using `ce['complete']` alone. Corrupted payload, corrupted CRC, non-zero flags, and Deflate compression were all accepted as `EXACT_PAYLOAD_MATCH`. Corrupted prefix was accepted as `PARTIAL_CONTAINER_TRUNCATED`. | Variable `byte_match` was computed but omitted from the `if/else` branching condition. Header flags, compression method, and CRC were never gated. |
| **Inv 2: Objdump Instruction Recount** | R3 reported 0 instructions and 0 arithmetic across all 44 intact libraries. | Independent recount of 5 retained samples finds **1450 to 1494 instructions** per 1500-line sample, and **8 arithmetic instructions** in `libaicodec.so`. | Disassembly command used `--no-show-raw-insn`, but `INS_RE` required an 8-hex raw instruction byte (`[0-9a-f]{8}\\s+`). The regex matched 0 lines against the flag's output format. |
| **Inv 3A: SoftLight Shader Verbatim Block** | R3 labeled lines 802–815 as "Verbatim Shader Formulation (lines 13-26): `highp float blendColor(highp float a, highp float b)`". | Original decoded APK shader lines 13–26 are `float SoftLight_Fcn(float A, float B)`. | R3 author substituted a synthesized/reworded helper function and falsely labeled it "Verbatim". Rational math difference ($11/512$) is verified and mathematically sound. |
| **Inv 3B: Model Asset Path** | R3 reported `assets/vlaimodel/libmtface/models/NE.manis`. | Path does NOT exist in APK. Actual path is `assets/vlaimodel/libmtskinphone/Models/NE.manis` (107,026 B, SHA-256 `74572848...`). | Typo / inaccurate asset cataloging without verifying ZIP namelist existence. |
| **Inv 3C: Manis Dynamic Symbols** | R3 reported "303 defined symbols mentioning Manis". | Retained readelf shows exactly **288** defined symbols mentioning Manis. 303 is the **total** count of all defined symbols. | Conflation of total defined symbols (303) with the subset mentioning `Manis` (288). |
| **Inv 3D: Tool Metadata & Heartbeat** | R3 master claimed parsed tool metadata and verified continuous heartbeat. | Ghidra version was a hardcoded literal at line 336. Native Paseo schedules show recent runs failed with connectivity/provider errors. | Static strings substituted for dynamic parsing; prose descriptions substituted for machine execution receipts. |

---

## Detailed Investigation 1: Input Status & Container Classifier Reproduction

### 1. The R3 Code Fragment (Pure Extraction)
In `scripts/task063_r3/generate_deliverables_r3.py` (lines 658–665):
```python
# Check byte equality with on-disk data
disk_data = info["data"]
byte_match = (ce["payload_bytes"] == disk_data)

if ce["complete"]:
    c_status = "EXACT_PAYLOAD_MATCH"
    trunc_note = "None (Fully bounded ELF64, declared size/CRC/payload match container byte-for-byte)"
else:
    c_status = "PARTIAL_CONTAINER_TRUNCATED"
    trunc_note = f"Container interrupted before EOF..."
```

### 2. Proof of Failure via Controlled Test Cases
All test cases were executed in-memory without altering source binaries on disk:

1. **TC-1-POS-COMPLETE (`libaicodec.so`):**
   - R3 Output: `EXACT_PAYLOAD_MATCH`
   - Reference Output: `EXACT_PAYLOAD_MATCH`
   - Analysis: Passes, but R3 passes only because `ce['complete']` is True.
2. **TC-2-POS-PARTIAL (`libmfxkit.so`):**
   - R3 Output: `PARTIAL_CONTAINER_TRUNCATED`
   - Reference Output: `PARTIAL_CONTAINER_TRUNCATED`
   - Analysis: Both detect truncation. Reference validates prefix equality against container EOF and does NOT claim complete CRC match.
3. **TC-3-NEG-PAYLOAD-CORRUPTION (1 byte flipped in payload of `libaicodec.so`):**
   - R3 Output: **`EXACT_PAYLOAD_MATCH`** (FAIL!)
   - Reference Output: **`CORRUPTED_CRC` / `PAYLOAD_MISMATCH`** (PASS)
   - Causal Mechanism: R3 computed `byte_match = False`, but never branched on `byte_match`. It evaluated `if ce["complete"]:` which was True, blindly emitting `EXACT_PAYLOAD_MATCH`.
4. **TC-4-NEG-HEADER-CRC-CORRUPTION (Bit flipped in declared CRC32 in local header):**
   - R3 Output: **`EXACT_PAYLOAD_MATCH`** (FAIL!)
   - Reference Output: **`CORRUPTED_CRC`** (PASS)
   - Causal Mechanism: R3 local header parsing extracts `declared_crc32` but never checks if `crc32(payload) == declared_crc32`.
5. **TC-5-NEG-UNSUPPORTED-COMPRESSION (Compression method set to 8 Deflate):**
   - R3 Output: **`EXACT_PAYLOAD_MATCH`** (FAIL!)
   - Reference Output: **`UNSUPPORTED_COMPRESSION`** (PASS)
   - Causal Mechanism: R3 extracts `method` but never validates `method == 0`.
6. **TC-6-NEG-UNSUPPORTED-FLAGS (Flags set to 0x08 Data Descriptor):**
   - R3 Output: **`EXACT_PAYLOAD_MATCH`** (FAIL!)
   - Reference Output: **`UNSUPPORTED_FLAGS`** (PASS)
   - Causal Mechanism: R3 extracts `flags` but never validates `flags == 0`.
7. **TC-7-NEG-PREFIX-CORRUPTION (1 byte flipped in prefix of `libmfxkit.so`):**
   - R3 Output: **`PARTIAL_CONTAINER_TRUNCATED`** (claiming on-disk matches prefix!) (FAIL!)
   - Reference Output: **`PAYLOAD_MISMATCH`** (PASS)
   - Causal Mechanism: R3 fell through to `else:`, assuming any incomplete entry has an exact prefix match without checking `byte_match`.

---

## Detailed Investigation 2: Objdump Format & Disassembly Recount

### 1. The Regex Mismatch
The command executed in R3 was:
```bash
llvm-objdump --no-show-raw-insn -d <so_path>
```
Sample output generated by `--no-show-raw-insn`:
```text
   ce7a0:      	bti	c
   ce7a4:      	adrp	x0, 0x1fd000 <syscall@plt+0x3bc0>
   ce7a8:      	add	x0, x0, #0x450
```
Notice that there is NO raw instruction hex word (e.g. `d50324df`).

However, R3 generator defined `INS_RE` (line 143):
```python
INS_RE = re.compile(r"^[ ]*[0-9a-f]+:\s+[0-9a-f]8\s+([a-z0-9.]+)", re.IGNORECASE)
```
The token `[0-9a-f]{8}\\s+` required an 8-hex raw instruction word that `--no-show-raw-insn` suppressed. Consequently, `INS_RE.match(line)` returned `None` on every single instruction line in all 44 libraries.

### 2. Recount of 5 Existing 1500-Line Raw Samples
Using the corrected regex `CORRECTED_INS_RE = re.compile(r"^\s*[0-9a-f]+:\s+([a-z][a-z0-9.]*)\b", re.I)`:

| Sample Library | Total Lines in Sample | R3 Instruction Claim | Actual Instructions | Actual Arithmetic Instructions | Non-Instruction Lines Breakdown |
|---|---:|---:|---:|---:|---|
| `libaicodec.so` | 1500 | 0 | **1470** | **8** (`fmla`, `fadd`, `fmul`, `fsub`, etc.) | 12 Labels, 2 Headers, 16 Blanks |
| `libaidetectionplugin.so` | 1500 | 0 | **1464** | **0** | 18 Labels, 2 Headers, 16 Blanks |
| `libPVGColorFunctions.so` | 1500 | 0 | **1450** | **0** | 25 Labels, 2 Headers, 23 Blanks |
| `libMTLReportTool.so` | 1500 | 0 | **1466** | **0** | 17 Labels, 2 Headers, 15 Blanks |
| `libManis.so` | 1500 | 0 | **1494** | **0** | 3 Labels, 2 Headers, 1 Blank |

### 3. Full-Output vs Retained-Output Binding
In R3, the generator captured only the first 1500 lines of disassembly to disk. However, the report did not clearly distinguish between "0 arithmetic in the 1500-line sample" and "0 arithmetic in the entire binary".
Furthermore, command receipts did not record the SHA-256 of the unclipped stdout stream, leaving no durable audit trail connecting the command invocation to the retained file.

---

## Detailed Investigation 3: Critical Provenance Mismatches

### 1. SoftLight Shader (Claim C2)
- **APK Entry:** `assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs`
- **Decrypted Bytes SHA-256:** `69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14`
- **Actual Source Lines 13–26:**
  ```glsl
  float SoftLight_Fcn(float A, float B)
  {
  	float C = 0.0;
  	if (B <= 0.5)
  	{
  		C = A * B / 0.5 + A * A * ( 1.0 - 2.0 * B);
  	}
  	else
  	{
  		C = A * (1.0 - B) / 0.5 + sqrt(A) * (2.0 * B - 1.0);
  	}
  	
  	return C;
  }
  ```
- **R3 False Labeling:**
  R3 emitted `highp float blendColor(highp float a, highp float b)` with modified arithmetic expressions and explicitly labeled it `Verbatim Shader Formulation (lines 13-26)`. While algebraically equivalent, labeling a reworded snippet as "Verbatim" violates evidence-based integrity.
- **Mathematical Validation:**
  CEO verified counterexample is reaffirmed:
  For $A = 1/16, B = 3/4$:
  $D(1/16) = 53/256$
  W3C SoftLight $= 69/512 = 0.134765625$
  Meitu Shader $= 5/32 = 0.15625$
  Difference $= 11/512 = 0.021484375 
eq 0$.
  The non-equivalence to W3C is mathematically proven.

### 2. Model Asset Path in APK (Claim C5)
- In `SOURCE/com.mt.mtxx.mtxx.apk`, searching for `NE.manis` yields:
  `assets/vlaimodel/libmtskinphone/Models/NE.manis` (107,026 B, SHA-256: `74572848e192966d56ab312e0e2eb12c3402b3f39d4e6450f60cddefb2d98c3c`).
- The path reported in R3:
  `assets/vlaimodel/libmtface/models/NE.manis` -> **DOES NOT EXIST** (`False`).

### 3. libManis.so Dynamic Symbols (Claim C5)
- In `readelf_libManis.so.stdout.txt`:
  - Total parsed symbols: 642
  - Total defined symbols (non-UND, value != 0): **303**
  - Defined symbols mentioning `Manis` (case-insensitive): **288**
  - Defined symbols NOT mentioning `Manis`: **15** (e.g., `_init`, `_fini`, `__cxa_finalize`, etc.)
  - R3 Claim: "303 defined symbols mentioning Manis".
  - Finding: 303 was the total defined symbol count, conflated with the 288 Manis keyword matches.

### 4. Tool Metadata & Heartbeat
- `Ghidra application.properties`:
  Line 336 of R3 generator hardcoded `"12.1.4_PUBLIC (Build: 2026-Sep-21 1613 UTC, Rev: 8b6bbb857accdfa20dc5b2f5dea471178c2e9fbc)"`.
  Direct parsing of `application.properties` extracts `application.version=12.1.4`, `application.release.name=PUBLIC`, `application.build.date=2026-Sep-21 1613 UTC`, `application.revision.ghidra=8b6bbb857accdfa20dc5b2f5dea471178c2e9fbc`.
- Native Paseo schedules (`068c797c.json` and `9ed2909e.json`) confirm that recent scheduled runs encountered network/provider errors during daemon restarts, which were smoothed over in R3 prose rather than documented with concrete execution receipts.

---

## Conclusion & Operational Boundaries
This diagnostic has conclusively reproduced and isolated all 6 findings cited in the CEO R3 Review.
All causal mechanisms are bound to specific code lines and test counterexamples.
Per TASK_067 mandate, no production files or TASK_063 baseline files were modified.
