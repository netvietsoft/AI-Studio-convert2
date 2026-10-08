# TASK068 R1 independent research review: NEEDS_FIX

Fingerprint: 670293d31a96cec42b13a1327328f1520cd91656f4359685d66e4ef81819c974

Canonical standard fully reread; SHA25610968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F. Independent prior real read-only reviewers personally checked tracked sources, retained command outputs, selected licenses/modules, decoded APK SoftLight expressions and fraction controls. Root repeated all2695sourceSHA256 and Gitblob identities,58reporthashes,3indexhashes,24command receipts and current3checkout HEAD/origin/fsck/clean; persisted TASK_068_ROOT_SOURCE_REVIEW.json. These checks support source acquisition integrity, not app readiness.

Concrete correction: COMPARISON_MAP labels0x2344e8 as native blur entry. The historical Ghidra text names FilterToFBO at that address, but literal0x2344e8 is not inside a file-backed executable PT_LOAD of the currently bound arm64 ELF. Address-space/base/ABI correspondence has not been proven. Do not infer a relocation delta or claim native pointer/body correspondence from the matching filename. R2 must label this as historical Ghidra text identifier, mapping to current ELF UNKNOWN, and limit guided filtering to an external mask-processing candidate. Preserve exact hashes and original evidence; no decompilation/reacquisition/baseline recovery.

Correction task: TASK068 revision2, same three pinned reference checkouts; only clarify comparison/index/report provenance, reuse hash-verified acquisition receipts, no production/P0 writes. One bounded correction route. No SO45 baseline, Phase PASS or V4 authorization.
