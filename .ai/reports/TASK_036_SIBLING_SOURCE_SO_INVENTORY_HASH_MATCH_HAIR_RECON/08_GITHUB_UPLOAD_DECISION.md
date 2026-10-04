# 08 — GITHUB UPLOAD DECISION & REPOSITORY HYGIENE AUDIT

## 1. Governing Policies & Mandates

The autonomous execution directive for `TASK_036` defines the binary upload policy as follows:
> **`raw_binary_upload_policy`:**
> `NO_DUPLICATE_HASH; ONLY_AUTHORIZED_SOURCE_ONLY_BINARIES_IF_REPO_SIZE_POLICY_PERMITS; OTHERWISE_UPLOAD_HASH_METADATA_ONLY`

Furthermore, standard Git repository governance mandates:
1. Prevent unnecessary repository bloat caused by large binary commits.
2. Avoid Git LFS unless specifically pre-configured for the repository.
3. Guarantee that no existing file is overwritten without justification.
4. Provide complete cryptographic traceability for all project assets.

---

## 2. Binary Inventory Evaluation

The forensic audit conducted under `TASK_036` established the following classification:

| Classification | File Count | Action Required |
|---|---|---|
| **`EXACT_MATCH`** | 45 | **DO NOT UPLOAD.** Files are already tracked in Git with identical hashes. |
| **`SAME_NAME_DIFFERENT_HASH`** | 0 | **NONE.** Zero version drifts or hash conflicts detected. |
| **`SOURCE_ONLY`** | 0 | **NONE.** Zero native libraries exist in the sibling source that are missing from GitHub. |
| **`GITHUB_ONLY`** | 1 (`libomp.so`) | **RETAIN AS-IS.** Already checked into Git (`lib-core-graphics/.../libomp.so`). |

---

## 3. Formal Decision & Execution

1. **Zero Binary Duplication:**
   - Because all 45 vendor binaries from `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a` are 100% byte-for-byte identical to the binaries already in `lib-core-graphics/src/main/jniLibs/arm64-v8a/`, **no `.so` binaries were copied into the repository**.
   - Any re-commit of these files would directly violate the `NO_DUPLICATE_HASH` rule.

2. **Commit Deliverable Scope:**
   - Commit and push **only**:
     - Complete cryptographic audit manifests (`02_SO_HASH_MATCH.csv`, `03_ELF_METADATA_INVENTORY.csv`, `04_JNI_EXPORT_MAP.csv`, `06_HAIR_RELEVANCE_RANKING.csv`).
     - Technical reconstruction findings (`00_AUDIT_INDEX.md`, `01_SIBLING_SOURCE_DISCOVERY.md`, `05_NEEDED_DEPENDENCY_GRAPH.md`, `07_HAIR_RECON_FINDINGS.md`, `08_GITHUB_UPLOAD_DECISION.md`, `09_GIT_PROVENANCE.md`).
     - Machine-readable master metadata (`SO_INVENTORY.json`).
     - Raw disassembly and symbol dumps in `raw/`.
     - State tracking artifacts (`.ai/state/tasks/...`, `.ai/commands/...`, `.ai/state.json`, `TASK_LOG.md`).

3. **Repository Impact:**
   - Binary additions: **0 bytes**
   - Documentation & forensic metadata additions: **~1.2 MB** (textual markdown, CSV, JSON, symbol dumps)
   - Git repository hygiene: **100% compliant with zero churn**.
