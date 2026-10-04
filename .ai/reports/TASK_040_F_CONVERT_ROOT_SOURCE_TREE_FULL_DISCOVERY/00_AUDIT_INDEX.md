# TASK_040: F:\CONVERT ROOT SOURCE TREE FULL DISCOVERY — AUDIT INDEX

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY_ACTIVE`  
**Protocol**: `CONVERT2_COMMAND_V2`  
**Execution Lane**: `f-convert-root-source-discovery`  
**Runner Identity**: `CONVERT2-WINDOWS-03`  
**Scan Timestamp**: `2026-10-04T11:51:19.697934+07:00`  
**Authoritative Scan Root**: `F:\CONVERT`  
**Superseded Narrow Scope**: `TASK_039` (limited to `F:\CONVERT\com.mt.mtxx.mtxx`)  
**Verdict**: **PASS — PHYSICAL RUNNER FULL F:\CONVERT ROOT ENUMERATION COMPLETE**

---

## 1. Executive Summary

In compliance with Owner Directive `TASK_040`, Agent 0 and physical runner `CONVERT2-WINDOWS-03` conducted a comprehensive, root-level enumeration across the entire `F:\CONVERT` storage volume.

### Key Discoveries:
1. **Four Primary Top-Level Direct Children** under `F:\CONVERT`:
   - `F:\CONVERT\com.mt.mtxx.mtxx`: Meitu Reborn primary workspace, containing active `CONVERT2`, sibling ancestor `CONVERT` (V1), reverse tree `SOURCE`, requirement golden ground truth `Yeucau`, and asset packs.
   - `F:\CONVERT\com.lightricks.facetune.free`: Facetune workspace, containing reconstructed Android project `CONVERT`, decompilation tree `SOURCE` (`jadx_out`, `apktool_out`, `extracted_xapk`), and engineering reports `Report`.
   - `F:\CONVERT\Material Image Editor`: Dedicated asset repository containing `Mitu\material` with Apple camera filters, 12 online material categories (2014-5002), stickers, mosaics, and LUTs.
   - `F:\CONVERT\tools`: Infrastructure tooling (Docker Desktop installer, MinIO, WSL install scripts).
   - Plus **11 root-level governing documents and scripts**, notably `1.txt` (CEO/Owner operating charter and reference to `com.lightricks.facetune.free\SOURCE`), `2.txt` (distillation references), `3.txt`-`5.txt` (skin & slider requirements), and `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`.

2. **The "Missing" Additional Source Folder Identified**:
   - **Strongest Hair / JNI Candidate**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp`.
     Contains **50+ complete native C++ engine files**, including `hair_v2_*.cpp`, `hair_matting_engine.cpp`, `hair_strand_dye.cpp`, and a 159 KB `jni_bridge.cpp` with exact JNI registration tables!
   - **Facetune Source Folder**: `F:\CONVERT\com.lightricks.facetune.free\SOURCE` as explicitly designated in `F:\CONVERT\1.txt`.

---

## 2. Report Deliverables Directory

| File | Description |
|---|---|
| [`00_AUDIT_INDEX.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/00_AUDIT_INDEX.md) | This master audit index and executive verdict. |
| [`01_F_CONVERT_TOP_LEVEL_TREE.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/01_F_CONVERT_TOP_LEVEL_TREE.md) | Complete census of direct children and root files of `F:\CONVERT`. |
| [`02_ALL_CANDIDATE_DIRECTORIES.csv`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/02_ALL_CANDIDATE_DIRECTORIES.csv) | Full metadata, file counts, sizes, and scores for all 24 candidates. |
| [`03_PROJECT_MARKERS.csv`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/03_PROJECT_MARKERS.csv) | Build system and project marker file detection per candidate. |
| [`04_SOURCE_FILETYPE_COUNTS.csv`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/04_SOURCE_FILETYPE_COUNTS.csv) | Exact source extension census (.kt, .java, .cpp, .so, etc.). |
| [`05_GIT_REPOSITORY_INVENTORY.csv`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/05_GIT_REPOSITORY_INVENTORY.csv) | Git repositories, branches, commit SHAs, and remotes. |
| [`06_DUPLICATE_UNIQUE_CLASSIFICATION.csv`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/06_DUPLICATE_UNIQUE_CLASSIFICATION.csv) | Overlap classification and unique source evidence. |
| [`07_HAIR_JNI_SOURCE_HITS.csv`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/07_HAIR_JNI_SOURCE_HITS.csv) | Exact keyword occurrences across trees for Hair and JNI symbols. |
| [`08_HIGH_VALUE_SOURCE_DIRECTORIES.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/08_HIGH_VALUE_SOURCE_DIRECTORIES.md) | Deep analysis of high-value source trees. |
| [`09_RECOMMENDED_ANALYSIS_ORDER.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/09_RECOMMENDED_ANALYSIS_ORDER.md) | Prioritized sequence for subsequent engineering and TASK_038 intake. |
| [`10_TASK039_SCOPE_MISMATCH_RECONCILIATION.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/10_TASK039_SCOPE_MISMATCH_RECONCILIATION.md) | Formal reconciliation explaining why TASK_039 was narrow and how TASK_040 fixes it. |
| [`11_WORKFLOW_PROVENANCE.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/11_WORKFLOW_PROVENANCE.md) | Immutable command bus lease, execution, and dispatch audit trail. |
| [`12_REPORT_DRIVE_MIRROR.md`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY/12_REPORT_DRIVE_MIRROR.md) | Report Drive upload and local mirroring status. |
