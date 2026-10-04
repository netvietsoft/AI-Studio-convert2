# TASK_039: CONVERT WORKSPACE SOURCE TREE DISCOVERY & CLASSIFICATION — AUDIT INDEX

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_CLASSIFICATION_ACTIVE`  
**Command ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_20261004T103500+0700`  
**Protocol**: `CONVERT2_COMMAND_V2`  
**Execution Lane**: `workspace-source-discovery`  
**Runner Identity**: `GITHUB_ACTIONS_37178649576` / Physical Runner `CONVERT2-WINDOWS-02`  
**Authoritative Scan Root**: `F:\CONVERT` (Entire Storage Tree per Owner Directive)  
**Initial Narrow Scope Rectified**: Corrected from `F:\CONVERT\com.mt.mtxx.mtxx` to entire `F:\CONVERT` tree  
**Audit Status**: COMPLETE (READ-ONLY FORENSIC ENUMERATION & CLASSIFICATION)  
**Verdict**: **PASS — PHYSICAL RUNNER FULL F:\CONVERT ROOT ENUMERATION COMPLETE**

---

## 1. Executive Summary & Mandatory Answers to Done Condition

In accordance with Owner Directive and Protocol `CONVERT2_COMMAND_V2`, Agent 0 conducted a root-to-leaf forensic enumeration and classification of all project-relevant source, decompile, native binary, and reverse-engineering directories across the authoritative root `F:\CONVERT`.

### Direct Answers to the 6 Done Condition Questions:

#### 1. How many distinct source/decompile/native candidate directories exist?
- **24 distinct candidate directories** were discovered, enumerated, and classified across `F:\CONVERT`:
  - **Reconstructed Android App Source Projects (Category B):** 4 (`com.mt.mtxx.mtxx\CONVERT2`, `com.mt.mtxx.mtxx\CONVERT`, `com.mt.mtxx.mtxx\CONVERT\apps\android`, `com.lightricks.facetune.free\CONVERT`).
  - **Original Source Projects (Category A):** 1 (`com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp` — C++ Engine origin).
  - **Decompiled Java/Kotlin Source Trees (Category C):** 4 (`com.mt.mtxx.mtxx\SOURCE`, `com.mt.mtxx.mtxx\SOURCE\jadx_src`, `com.lightricks.facetune.free\SOURCE`, `com.lightricks.facetune.free\SOURCE\jadx_out`).
  - **Smali Bytecode & Resource Decompiles (Category D):** 2 (`com.mt.mtxx.mtxx\SOURCE\apktool_out`, `com.lightricks.facetune.free\SOURCE\apktool_out`).
  - **Native Binary Extracts (Category E):** 4 (`com.mt.mtxx.mtxx\SOURCE\extracted_native_libs`, `com.mt.mtxx.mtxx\SOURCE\dex_files`, `com.lightricks.facetune.free\SOURCE\extracted_xapk`, `com.mt.mtxx.mtxx\CONVERT\reconstruction-input\native-libs`).
  - **Native Pseudocode / Reverse Output (Category F):** 2 (`com.mt.mtxx.mtxx\SOURCE\Redesign`, `com.lightricks.facetune.free\SOURCE\Redesign`).
  - **Asset & Resource Extracts (Category G):** 5 (`com.mt.mtxx.mtxx\SOURCE\extracted_assets`, `com.mt.mtxx.mtxx\SOURCE\mitu`, `com.mt.mtxx.mtxx\beard_assets_10_png`, `com.mt.mtxx.mtxx\Yeucau`, `com.mt.mtxx.mtxx\ẢNH`, `Material Image Editor\Mitu\material`).
  - **Duplicate Copies & Backups (Category I):** 1 (`com.mt.mtxx.mtxx\_stray_backup_w9`).
  - **Tools & Unknown/Review (Category J):** 2 (`tools`, `com.lightricks.facetune.free\Report`).
- In addition, **11 root governing documents and technical specifications** reside directly in `F:\CONVERT` (notably `1.txt`, `2.txt`, `3.txt`-`5.txt`, and `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`).

#### 2. Which folder the user likely meant by "another source folder"?
- **Primary Target (Meitu Reborn):** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android` (and its parent project `CONVERT`).
  - *Rationale*: While `CONVERT2` is the active 8-module repository (`meitu-convert`, 143 Kotlin files), `CONVERT\apps\android` is the predecessor reconstructed 26-module Android project (`mtxx-reborn`) containing **884 Kotlin files**, **274 C/C++ files**, **28 Gradle KTS build files**, and **27 XML layouts/manifests**.
  - In addition, `CONVERT\apps\android\core\native-bridge\src\main\cpp` contains **50 complete native C++ files** including `hair_v2_*.cpp`, `hair_matting_engine.cpp`, `hair_strand_dye.cpp`, and a massive **159 KB** `jni_bridge.cpp`.
- **Sibling Target (Facetune):** `F:\CONVERT\com.lightricks.facetune.free\SOURCE` (and its reconstructed counterpart `com.lightricks.facetune.free\CONVERT`).
  - *Rationale*: Explicitly designated as source code by Chairman Tony in `F:\CONVERT\1.txt` (*"Đây là thư mục mã nguồn F:\CONVERT\com.lightricks.facetune.free\SOURCE : sử dụng tất cả tài nguyên có thể dùng ở đây"*).

#### 3. Is it actual editable source, decompiled source, smali, native binaries, or reverse output?
- **Actual Editable Source:**
  - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android`: Clean Architecture multi-module Kotlin & modern C++ source code.
  - `F:\CONVERT\com.lightricks.facetune.free\CONVERT`: 11-module Android Kotlin & C++ source project.
  - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\services\api`: TypeScript/Node.js backend service (1,851 files).
- **Decompiled Java Source:**
  - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src`: JADX output containing 106,466 obfuscated Java files.
  - `F:\CONVERT\com.lightricks.facetune.free\SOURCE\jadx_out`: JADX decompiled Java tree (26,020 files).
- **Smali Decompile:**
  - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\apktool_out`: Apktool disassembled smali classes (classes to classes9) and decoded XML resources.
  - `F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out`: Apktool disassembled smali bytecode.
- **Native Binaries:**
  - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs`: 45 ELF `.so` libraries for arm64-v8a.
  - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\dex_files`: Raw classes.dex partitions.
  - `F:\CONVERT\com.lightricks.facetune.free\SOURCE\extracted_xapk`: Vendor native libraries and split APK binaries.
- **Reverse Output / Pseudocode:**
  - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\mitu`: Curated reverse engineering directory (models, lua scripts, shaders).
  - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\Redesign`: UI prototype specs and token definitions.

#### 4. What unique files exist there that are not already in CONVERT2?
- **In `CONVERT\apps\android`**:
  - **741+ unique Kotlin files** across 15 complete feature modules not in `CONVERT2` (`feature:community`, `feature:videoedit`, `feature:album`, `feature:idphoto`, `feature:livephoto`, `feature:puzzle`, `feature:poster`, `feature:tools`, `feature:settings`, `feature:drafts`, `feature:aiphoto`, `feature:home`, `feature:templates`, `feature:profile`, `feature:vip`).
  - **32 unique C++ implementation files** in `core/native-bridge/src/main/cpp`, including:
    - `hair_v2_barrier.cpp`
    - `HairBeardDyeEngine.cpp`
    - `pbd_cloth_simulator.cpp` (PBD cloth simulation per `2.txt`)
    - `virtual_tryon_engine.cpp` (Virtual try-on per `2.txt`)
    - `ndk_video_decoder.cpp` & `video_timeline_compositor.cpp` (VideoCore per `2.txt`)
    - `optical_flow_tracker.cpp`
    - `beauty_video_connector.cpp`
    - 159 KB `jni_bridge.cpp` with 377 JNI registration entries.
- **In `CONVERT\services\api`**: 1,851 TypeScript/Node.js files (Fastify, Prisma, MQTT/SSE).
- **In `com.lightricks.facetune.free\CONVERT`**: 1,377 unique Kotlin files across 11 modules (`lib-filters`, `lib-video-engine`, `lib-image-editing`, `feature-ai-retouch`, etc.).

#### 5. Does it contain higher-value Hair/JNI evidence than the current SOURCE folder?
- **For Vendor APK Ground Truth:** NO. `SOURCE\jadx_src` contains the canonical vendor JNI class `MTIKABHairFilter.java` calling native methods `nSetTraditionHairDyeIntensityAndShine` and `nSetHairEffectMaterial`, and `SOURCE\extracted_native_libs` contains the original 45 vendor ELF `.so` binaries (`libMTFilterKernel.so`, `libarkernel3.so`, `libManis.so`).
- **For Reconstructed Integration Code:** YES! `CONVERT\apps\android\core\native-bridge\src\main\cpp` contains the complete early C++ Hair Engine (`hair_v2_pipeline.cpp`, `hair_v2_matting.cpp`, `hair_strand_dye.cpp`, `bisenet_face_parser.cpp`) and the massive 159 KB `jni_bridge.cpp` with 377 JNI registrations that provide immediate blueprint architecture for CONVERT2.

#### 6. Which directory should TASK_038 or a follow-up task analyze next?
- **For TASK_038 (Deep JNI Xref & Vendor Hair Decompile):**
  1. Primary: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources\com\meitu\mtimagekit\filters\specialFilters\abHairFilter\MTIKABHairFilter.java`
  2. Secondary: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\` (`libMTFilterKernel.so`, `libarkernel3.so`)
  3. Cross-reference: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\jni_bridge.cpp`
- **For Feature Expansion beyond Hair:**
  1. `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\feature\` (`videoedit`, `idphoto`, `poster`, `puzzle`)
  2. `F:\CONVERT\com.lightricks.facetune.free\CONVERT\` (Facetune filter & retouch engines)

---

## 2. Deliverables Manifest

| Deliverable File | Type | Description |
|---|---|---|
| [`00_AUDIT_INDEX.md`](00_AUDIT_INDEX.md) | Markdown | Master executive index, Done Condition answers, deliverable index. |
| [`01_WORKSPACE_TREE.md`](01_WORKSPACE_TREE.md) | Markdown | Full root-to-leaf hierarchical directory tree across `F:\CONVERT`. |
| [`02_DIRECTORY_CLASSIFICATION.csv`](02_DIRECTORY_CLASSIFICATION.csv) | CSV | Complete metadata, classification (A–J), sizes, files, scores for all 24 candidates. |
| [`03_SOURCE_FILETYPE_COUNTS.csv`](03_SOURCE_FILETYPE_COUNTS.csv) | CSV | File extension census (.kt, .java, .cpp, .c, .h, .so, etc.) per candidate. |
| [`04_BUILD_MARKERS_AND_PROJECTS.md`](04_BUILD_MARKERS_AND_PROJECTS.md) | Markdown | Deep analysis of Gradle, CMake, Node/NPM, and Apktool build systems detected. |
| [`05_DUPLICATE_VS_UNIQUE_SOURCE.md`](05_DUPLICATE_VS_UNIQUE_SOURCE.md) | Markdown | Hash comparisons, exact duplicate mirrors, and unique files vs CONVERT2. |
| [`06_HAIR_RELEVANT_SOURCE_HITS.md`](06_HAIR_RELEVANT_SOURCE_HITS.md) | Markdown | Search results across trees for 16 canonical Hair/JNI keywords. |
| [`07_RECOMMENDED_NEXT_SOURCE_TO_ANALYZE.md`](07_RECOMMENDED_NEXT_SOURCE_TO_ANALYZE.md) | Markdown | Actionable roadmap and priority sequence for TASK_038 and subsequent tasks. |
| [`08_GIT_PROVENANCE.md`](08_GIT_PROVENANCE.md) | Markdown | Git repository inventory, branches, commit SHAs, and immutability record. |
| [`09_REPORT_DRIVE_MIRROR.md`](09_REPORT_DRIVE_MIRROR.md) | Markdown | Google Report Drive sync status and local transfer package verification. |
| `raw/` | Directory | Machine-readable datasets (`candidates_audit.json`, `cpp_comparison.json`, etc.). |
