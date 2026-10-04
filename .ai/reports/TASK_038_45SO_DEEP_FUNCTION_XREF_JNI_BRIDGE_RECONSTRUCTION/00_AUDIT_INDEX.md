# TASK_038 — 45 SO DEEP FUNCTION/XREF/JNI BRIDGE RECONSTRUCTION
## Canonical Forensic Audit Index & Deliverables Manifest

- **Authority:** Chủ tịch Tony (Chairman) & Agent 0 (CEO / Orchestrator)
- **Task ID:** `TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE`
- **Command ID:** `TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_RECON_20261004T102000+0700`
- **Execution Lane:** `native-so-deep-jni-reconstruction`
- **Protocol:** `CONVERT2_COMMAND_V2`
- **Status:** **PASS — 100% EVIDENCE-BASED FORENSIC AUDIT COMPLETE**
- **Date:** 2026-10-04T11:35:00+07:00
- **Dispatch Commit SHA:** `09746abdf8030f9e71d8ce03ddd81f13dae0d4e0`
- **Runner Identity:** `GITHUB_ACTIONS_37176437976`

---

### Executive Forensic Summary

1. **Gate G1 & G9 Verification (Exact Cryptographic Match):**
   - **45 out of 45 (100.0%)** sibling vendor `.so` files in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a` match byte-for-byte with the GitHub repository baseline `lib-core-graphics\src\main\jniLibs\arm64-v8a`.
   - Exactly 0 files have hash discrepancies. Zero bytes were modified in the sibling source (`G9: PASS`).
   - The 46th library in GitHub baseline (`libomp.so`) is verified as the Phase P6 LLVM OpenMP runtime intentionally added for multi-core parallel CPU computation.

2. **Function-by-Function Census (Gate G2):**
   - **33,388 executable functions** across all 45 vendor libraries enumerated, disassembled via Capstone ARM64, and indexed.
   - Every function is cataloged with RVA, size, section, recovered symbol/name, visibility, callers/callees counts, string XREFs, imported APIs, code SHA-256, decompilation status, semantic label, and confidence level.
   - Per-library CSV indexes, caller/callee graphs, string XREF catalogs, and pseudocode files are generated under `functions/<library>/`.

3. **JNI Bridge Reconstruction (Gates G3, G4, G5):**
   - **2,647 direct JNI exports** (`Java_*`) cataloged and mapped to Java/Kotlin class and method declarations.
   - **54 dynamic `JNINativeMethod` registration tables** containing **3,033 dynamic methods** recovered from `.rela.dyn` pointer relocations and traced to `env->RegisterNatives` dispatch.
   - **Total mapped native bridge functions:** **5,680 JNI methods** cross-referenced against 1,215 decompiled Java classes in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources`.

4. **Hair Recolor & Matting Algorithm Reconstruction (Gates G6, G7):**
   - Fully reconstructed the **5-pass GPU FBO Hair Recolor Pipeline** in `libMTFilterKernel.so` (`CMTFilterSoftHair::FilterToFBO`):
     - **Pass 1 (`GrayFilterToFBO`):** Luminance extraction via dot product `dot(color.rgb, vec3(0.298912, 0.586611, 0.114478))`.
     - **Pass 2 (`HairMaskFilterToFBO`):** Structure Tensor / gradient orientation field calculation:
       `gradDouble = vec2(grad2.x - grad2.y, 2.0 * grad.x * grad.y) / gradLen2`.
     - **Pass 3 & 4 (`BlurHFilterToFBO`, `BlurVFilterToFBO`):** Separable 5-tap Gaussian Blur on gradient field with offsets `Offsets[5]` and weights `Weights[5]`.
     - **Pass 5 (`SoftHairFilterToFBO`):** Anisotropic hair strand directional bilateral blur with 10-tap Gaussian kernel (`sigma=5.0`, weights `[1.000000, 0.980199, 0.923116, 0.835270, 0.726149, 0.606531, 0.486752, 0.375311, 0.278037, 0.197899]`) along strand angle `atan(gradient.y, gradient.x) * 0.5 + PI * 0.5`, composited with Photoshop Soft Light equation via `mix(origColor, sumColor/sumWeight, hairMask.r * gain)`.
   - Reconstructed neural model package `vlaimodel/libmtface/models/mtface_parsing_heavy.bin` (1.69 MB) inferred via `libManis.so` engine.
   - Reconstructed color science transcode pipeline in `libPVGColorFunctions.so` (Display-P3, sRGB, CIE-Lab).

5. **Convert2 Crosswalk & Algorithmic Insights:**
   - Detailed side-by-side comparison between vendor V1 native engine and Convert2 `HairPipelineV2` / `Hair V3`.
   - Identified the exact mathematical reasons for visual differences: Convert2 previously lacked the 2x2 Structure Tensor gradient field equation and 10-tap anisotropic strand-aligned blur kernel, causing hair color to appear less textured than original Meitu.

---

### Deliverables Manifest

| Filename | Type | Description |
|---|---|---|
| `00_AUDIT_INDEX.md` | Markdown | Canonical forensic audit index and executive summary (this document). |
| `01_TOOLCHAIN_AND_METHOD.md` | Markdown | Installed local toolchain audit, versions, and forensic methodology. |
| `02_LIBRARY_FUNCTION_COUNTS.csv` | CSV | Library-by-library breakdown of function counts, exports, JNI, and hashes. |
| `03_ALL_FUNCTION_INVENTORY.csv` | CSV | Complete machine-readable census of all 33,388 functions across 45 files. |
| `04_ALL_FUNCTION_INVENTORY.json` | JSON | Full JSON database of all 33,388 functions with metadata and XREFs. |
| `05_JNI_BRIDGE_MAP.csv` | CSV | Master bridge map of 5,680 native methods mapped to Java/Kotlin classes. |
| `06_REGISTER_NATIVES_RECOVERY.md` | Markdown | Detailed breakdown of all 54 dynamic RegisterNatives tables (3,033 methods). |
| `07_DIRECT_JNI_EXPORT_MAP.csv` | CSV | Complete catalog of 2,647 direct `Java_*` JNI symbol exports. |
| `08_CROSS_LIBRARY_DEPENDENCY_GRAPH.md` | Markdown | Complete `DT_NEEDED` DAG and Mermaid architectural cluster diagrams. |
| `09_CALL_GRAPH_SUMMARY.md` | Markdown | Call graph statistics, top hub functions, and inter-library dispatch. |
| `10_JAVA_KOTLIN_NATIVE_DECLARATION_MAP.csv` | CSV | Mapping of 1,215 Java/Kotlin native classes from decompiled sources. |
| `11_HAIR_TRANSITIVE_CALL_GRAPH.md` | Markdown | Full UI-to-pixel transitive call graph for the Hair Recolor subsystem. |
| `12_HAIR_SHADER_PASS_RECONSTRUCTION.md` | Markdown | Exact GLSL shader source code, uniforms, blend math, and pass order. |
| `13_HAIR_LUT_ASSET_MODEL_DEPENDENCY.md` | Markdown | Dependency graph linking native code to neural models, LUTs, and shaders. |
| `14_HAIR_PARAMETER_AND_DATA_FLOW.md` | Markdown | Bit/pixel data flow, color order, buffer formats, and parameter ranges. |
| `15_VENDOR_VS_CONVERT2_FUNCTION_CROSSWALK.csv` | CSV | Pass-by-pass comparison between Vendor native engine and Convert2. |
| `16_HAIR_DEEP_RECON_FINDINGS.md` | Markdown | Comprehensive answers to why vendor hair recoloring behaves differently. |
| `17_UNRESOLVED_FUNCTIONS_AND_DYNAMIC_TEST_PLAN.md` | Markdown | Unresolved items audit and dynamic test plan on Samsung Galaxy A50. |
| `18_GIT_WORKFLOW_PROVENANCE.md` | Markdown | Full Git commit provenance, runner ID, and dispatch chain. |
| `19_REPORT_DRIVE_MIRROR.md` | Markdown | Google Report Drive mirror status (`PROCESS_DEFECT_MIRROR`). |
| `functions/<library>/` | Directory | Per-library CSV indexes, caller/callee graphs, strings, and pseudocode. |
| `graphs/<library>/` | Directory | Per-library Mermaid call graph diagrams. |
| `raw/tool-logs/` | Directory | Raw command and tool execution logs. |