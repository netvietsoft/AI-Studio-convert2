# TASK_249 R1 — libPVGCodec.so gap review

## Disposition

**PARTIAL, with no function recovered.** The bounded `[0xaf040,0xaf688)` window is now independently rehashed and decoded as 402 contiguous ARM64 words. A second, read-only query of the existing TASK_248 Ghidra project confirms that Ghidra defines neither instructions nor function-body membership in any of these 402 words. I recover **0 new C-like bodies** and do not increase any decoded-function total.

The evidence strongly supports classifying this window as exception landing-pad/control-flow material inside TASK_248's candidate oversized FDE, rather than as a proven independent function. This remains a static classification: neither an independent source-function boundary nor algorithm behavior is proven.

## Reproducible source mapping and complete span coverage

The source file hash is `4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc` (1,283,760 bytes). ELF PT_LOAD inspection derives VA `0xaf040` to file offset `0xaf040` from `p_vaddr=0`, `p_offset=0`; the span is within that segment's 1,266,000-byte file range. Source gap bytes hash to `f825653da2ed819fd5334f4103037f4466fcf8655080e5ec84c56a684569c54b`. The 27,524-byte candidate FDE `[0xa8b08,0xaf68c)` rehashes to `7c65b7edc58d97da61177d6c07fe5579bf950074592f79dc0bb6d4499e904fb5`.

Capstone ARM64 decoding produced one 4-byte instruction for each aligned source word: 402/402 coverage, with bytes and address recorded in `source/word_edge_ledger.json` and textual listing in `source/capstone_disassembly.txt`. Mnemonic counts are: `b` 128, `b.eq` 1, `b.ne` 1, `bl` 49, `cbnz` 1, `cbz` 8, `tbz` 29, `tbnz` 23, `mov` 50, `ldr` 40, `ldrb` 44, `ldur` 6, `ldurb` 9, `add` 7, `cmp` 2, `str` 2, `sub` 2.

The gap contains 130 direct branch edges (129 remain inside this window, one exits it) and 49 direct call sites. There are no `br`, `blr`, or `ret` instructions in the decoded gap, hence no unresolved indirect control-transfer edges within the window. A scan of all 6,881 candidate-FDE words found no direct branch/call from outside the gap targeting an address inside it; the existing Ghidra reference manager also reports zero code-flow references from outside the gap into its 402 addresses. However, the preceding instruction at `0xaf03c` is `bl 0x6d5e4`, whose return continuation can resume at `0xaf040`; this is a possible normal continuation, not a direct branch edge. The only direct branch out is `0xaf5f8: b.ne 0xaf688`, which skips to the candidate FDE's final `0xaf688: bl 0x132a10`.

## Ghidra listing/body membership

The existing private TASK_248 Ghidra project was queried with Ghidra 12.1.4 headless, `-noanalysis -readOnly -max-cpu 1`, and a 1 GiB Java heap. The post-script inspected only `[0xaf040,0xaf688)` and 16-byte edge context; it did not call a decompiler. Process exit was 0. Raw logs, JSON output, script hash, invocation, and project integrity evidence are in `ghidra/`. A corrected final run returned native launcher exit 0 and wrote the script summary. One intermediate xref-reference version did not compile because Ghidra returns `ReferenceIterator`, not an array; its failed stdout/stderr/exit are preserved as `attempt_xref_array_error.*`. The final Java source uses `ReferenceIterator`. The final `stderr.log` retains PowerShell NativeCommandError stream formatting and the JVM `JAVA_TOOL_OPTIONS` notices; native launcher `$LASTEXITCODE` is separately saved as `0`, and stdout confirms the final script result.

Result: `function_body_member_words=0`, `instruction_defined_words=0`, `both=0`, and `external_flow_references=0` for Ghidra flow references from outside the gap into the 402 queried addresses. Ghidra's edge context reports the prior candidate function `FUN_001a8b08` at `0xaf030–0xaf03c`, then `FUN_001a8b08` resumes at `0xaf688` for the FDE-tail call. At `0xaf68c` Ghidra begins a distinct function `FUN_001af68c`. This tool-defined boundary is evidence about the imported project only; it does not establish compiler/source boundaries for the missing gap. TASK_248's register HighFunction address map likewise maps 0/402 gap addresses and marks all 402 absent. The p-code file explicitly records this address-map absence; machine instructions are present in the source and are separately decoded above.

## Exception metadata and likely role

The candidate FDE has an LSDA pointer at `0x4f004`, verified through `.eh_frame` metadata. Its LSDA header uses omitted LP-start and type table encodings (`0xff`, `0xff`) and ULEB128 call-site entries (`0x01`). The 1,371-byte call-site table parses exactly to its endpoint as 184 rows. Of these, 167 have nonzero landing-pad offsets, producing 128 unique landing-pad addresses, all within the gap; no row has a nonzero action field. The raw LSDA bytes, SHA-256, every parsed row, and unique-pad frequencies are in `source/lsda_callsite_evidence.json`.

The gap's repeated `ldrb/ldurb` flag tests, stack/frame loads, conditional branches, and calls—many to the same stripped address `0x1327d0`—are compatible with cleanup paths. Coupled with the LSDA's landing-pad references, this supports a **landing-pad/cleanup-control-flow** classification. I do not name these helper calls as destructors, infer resource types, or claim semantics: symbols are stripped and no source boundary/body is available. Some code may also be reached through the call-return continuation at the gap start.

## Counts and claim limits

- New complete C-like function bodies: **0**.
- New accepted/recovered function count: **0**.
- Machine words independently source-decoded: **402** (reported separately from function counts).
- Ghidra function-body membership in gap: **0/402 words**.
- Ghidra-defined instructions in gap: **0/402 words**.
- Gap words represented in TASK_248 optimized IR map: **0/402**; absence from optimized IR does not prove unreachable code.
- Function/source boundary: **unproven**. `[0xa8b08,0xaf68c)` is a candidate FDE range, not asserted as a function boundary.
- No ordinary provenance rows are relied upon for a function claim; all 402 target words and source/file mapping were rechecked directly. No runtime or behavior claim is made.

## Bounded next step

If further recovery is authorized, the next useful experiment is a minimal isolated Ghidra analysis of only this exact region with EH landing-pad entries seeded as candidate block starts, preserving the original bytes and project, followed by a complete normal-path plus EH-path CFG reconciliation. Do not fabricate or force a function at `0xaf040`, and do not run a whole-FDE decompile. Only consider C-like output if a complete body and exact extent are established independently of the FDE. The current evidence is adequate to report the region and its edges as static research, but not to count it as a decoded function.

## Validation and package state

Run from the repository root:

```powershell
python -X utf8 -B scripts/task_249_codex_internal/verify_gap.py
```

The verifier checks standard/task/manifest/source digests, PT_LOAD mapping, candidate-FDE and gap hashes, 402-word decode coverage, Ghidra listing absence, TASK_248 IR address coverage, and full LSDA row parsing. No task files, source bytes, production code, or Ghidra project files were written. The report package remains `PARTIAL` / `REVIEW_CANDIDATE_AWAITING_CEO`; COMPLETE.json binds all artifacts by hash. No commit or push was performed.
