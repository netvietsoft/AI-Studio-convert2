# TASK_036 — SIBLING SOURCE 45 SO INVENTORY, HASH MATCH & HAIR ALGORITHM RECON
## Executive Forensic Audit Index & Deliverables Manifest

- **Authority:** Chủ tịch Tony (Chairman) & Agent 0 (CEO / Orchestrator)
- **Task ID:** `TASK_036_SIBLING_SOURCE_45_SO_INVENTORY_HASH_MATCH_HAIR_ALGORITHM_RECON_ACTIVE`
- **Command ID:** `TASK_036_SIBLING_SOURCE_SO_INVENTORY_HAIR_RECON_20261004T091500+0700`
- **Execution Lane:** `native-so-forensics`
- **Runner Identity:** `CONVERT2-WINDOWS-02` (GitHub Actions Run `37170599066`)
- **Protocol:** `CONVERT2_COMMAND_V2`
- **Status:** **PASS — 100% EVIDENCE-BASED FORENSIC AUDIT COMPLETE**
- **Date:** 2026-10-04T09:27:00+07:00

---

### Executive Summary

1. **Physical Discovery:**
   - The user/chairman referenced a sibling directory named `"soure"` (or `"source"`).
   - In the canonical repository environment, this corresponds to `../SOURCE` relative to the workspace root `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2`.
   - The exact path inspected on the runner is:
     `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a`
   - Access was strictly **READ-ONLY**. Zero bytes were altered or deleted in the sibling source.

2. **Resolution of the 45-vs-46 Count Discrepancy:**
   - **Sibling folder count:** Exactly **45** native `.so` files (all arm64-v8a vendor binaries extracted from the Meitu production APK).
   - **GitHub repository baseline:** Exactly **46** native `.so` files located at `lib-core-graphics/src/main/jniLibs/arm64-v8a/`.
   - **Discrepancy reconciliation:**
     - Exactly **45 out of 45 (100.0%)** sibling `.so` files are **EXACT_MATCH** (identical byte-for-byte SHA-256 hash).
     - Exactly **0** files have mismatched hashes (`SAME_NAME_DIFFERENT_HASH = 0`).
     - Exactly **0** files are present only in the sibling source (`SOURCE_ONLY = 0`).
     - Exactly **1** file is present only in GitHub: `libomp.so` (1,205,616 bytes, SHA-256 `6D1C680BF28C6E25DC605C915EBEB2BAFC7E835DEE000078DB9CEBC261C7F620`).
     - `libomp.so` is the LLVM OpenMP runtime library, intentionally added during Phase P6 (commit `d971feaf8f2fcc208298912e749711a31e180550`) to enable parallel multi-core CPU computation for tensor orientation and guided filtering in `HairPipelineV2`.

3. **Hair Recolor & Matting Algorithm Reconstruction:**
   - Static symbol disassembly (`llvm-readelf`, `llvm-nm`) and string extraction (`llvm-strings`) unmasked the exact Meitu native hair coloring architecture:
     - **Core Recolor Engine:** `libMTFilterKernel.so` contains `MTFilterKernel::MTSoftHairFilter` and `MTFilterKernel::CMTFilterSoftHair` with dedicated FBO render passes: `GrayFilterToFBO` (luminance extraction), `HairMaskFilterToFBO` (segmentation matte binding), `BlurHFilterToFBO` / `BlurVFilterToFBO` (separable spatial feathering), and `SoftHairFilterToFBO` / `MTFilter_PsSoftLightr.fs` (Photoshop Soft Light blend shader with tone LUT maps).
     - **AR & Feature Deform Engine:** `libarkernel3.so` contains `mtlabar3::MakeupHairPart`, `mtlabar3::MakeupHairSoftPart`, GLSL shaders `Shaders/HairSoft/MTFilter_HairSoftMix.fs`, `MTFilter_gradient.fs`, and controls `kFaceliftControl_FluffyHair`, `kFaceliftControl_Hairline`.
     - **Layering & Dispatch:** `libLayerFlow.so` implements `LFDenseHairModular`, `decodeHairDyeConfig`, and `loadHairDyeConfig`.
     - **Color Science & Space:** `libPVGColorFunctions.so` executes color transforms across sRGB, Display-P3, and AdobeRGB with custom ICC profiles.
     - **Neural Inference:** `libManis.so` executes proprietary neural models for hair matting and facial parsing (BiSeNet).
     - **Android JNI Controls:** `MTIKABHairFilter` binds native controls via `nSetTraditionHairDyeIntensityAndShine`, `nSetHairEffectIntensity`, and `nSetSmearMaskColor`.

4. **Git Upload Policy Decision:**
   - Since all 45 sibling binaries already exist with identical SHA-256 hashes in GitHub, **no binary duplicates are committed**. Zero unnecessary repository bloat. Only metadata, hash manifests, and forensic evidence reports are checked into Git.

---

### Audit Deliverables Index

| Artifact | Format | Description |
|---|---|---|
| `00_AUDIT_INDEX.md` | Markdown | Master index, executive summary, and governance overview (this document). |
| `01_SIBLING_SOURCE_DISCOVERY.md` | Markdown | Physical filesystem discovery report, path resolution, and read-only protocol validation. |
| `02_SO_HASH_MATCH.csv` | CSV | File-by-file cryptographic comparison between Sibling and GitHub repositories (46 rows). |
| `03_ELF_METADATA_INVENTORY.csv` | CSV | ELF header metadata, machine ABI, SONAME, GNU Build IDs, and strip status for all 46 libraries. |
| `04_JNI_EXPORT_MAP.csv` | CSV | Full JNI symbol export catalog with demangled signatures and mapped Java classes. |
| `05_NEEDED_DEPENDENCY_GRAPH.md` | Markdown | Complete `DT_NEEDED` dependency DAG and Mermaid architectural cluster diagrams. |
| `06_HAIR_RELEVANCE_RANKING.csv` | CSV | Evidence-backed 0–5 hair algorithm relevance ranking for all 46 native libraries. |
| `07_HAIR_RECON_FINDINGS.md` | Markdown | Forensic analysis answering the 8 mandatory hair algorithm reconstruction questions. |
| `08_GITHUB_UPLOAD_DECISION.md` | Markdown | Formal binary upload policy audit and repository hygiene verification. |
| `09_GIT_PROVENANCE.md` | Markdown | Git commit provenance, runner environment, command bus dispatch, and cryptographic verification. |
| `SO_INVENTORY.json` | JSON | Machine-readable comprehensive inventory dictionary of all 46 libraries. |
| `raw/` | Directory | Per-library raw symbol listings (`*_symbols.txt`) and keyword search logs (`*_strings_hits.txt`). |

---

### Verification Hash Verification Summary

```
Total Discovered Native Libraries:       46
Sibling Source Arm64 Binaries:           45
GitHub Main Arm64 Binaries:              46
Cryptographic Exact Matches (SHA-256):   45 (100.0% of sibling set)
Different Hash Collisions:               0  (0.0%)
Source-Only Binaries:                    0  (0.0%)
GitHub-Only Binaries:                    1  (libomp.so - P6 OpenMP Runtime)
Hair Pipeline Relevance Tier 5 (Top):    5  (libMTFilterKernel, libarkernel3, libPVGColorFunctions, libManis, libAIModelKit)
```
