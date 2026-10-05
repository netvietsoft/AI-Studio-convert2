"""
TASK_058 Constants & Canonical Identifiers
Authority: Chairman Tony
Target Task: TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION_ACTIVE
"""

from pathlib import Path
from datetime import timezone, timedelta

REPO_ROOT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")
REPORTS_ROOT = REPO_ROOT / ".ai" / "reports"
TASK058_DIR = REPORTS_ROOT / "TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION"
RAW_EV_DIR = TASK058_DIR / "raw_evidence"
STATE_FILE = REPO_ROOT / ".ai" / "state.json"
APP_IMAGE_DIR = Path(r"F:\App\Image")
SO_DIR = REPO_ROOT / "lib-core-graphics" / "src" / "main" / "jniLibs" / "arm64-v8a"

VN_TZ = timezone(timedelta(hours=7))

# Canonical Identifiers
TASK_ID = "TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION_ACTIVE"
TASK_DOC_ID = "1A3IhiG76ZWmQEte2Nulsqlhh3KvypD71C4e20cEIfpI"
TASK_MODIFIED_TIME = "2026-10-05T07:15:49.039000+07:00"

GITHUB_RUN_ID = "37246754606"
DISPATCHER_RUN_ID = "37246658920"
RUNNER_IDENTITY = "CONVERT2-WINDOWS-02"
DISPATCH_COMMAND_ID = "TASK_058_SO45_CONTINUATION_20261005T072500+0700"
BASELINE_COMMIT_SHA = "c3cdf29aa0a65d3fa929ab4f737100c644b1ada4"
DISPATCH_COMMIT_SHA = "c3cdf29aa0a65d3fa929ab4f737100c644b1ada4"
ANTI_DUPLICATE_KEY = "TASK_058_TASK055_EVIDENCE_COMPLIANCE_AND_SO45_CONTINUATION_ACTIVE:2026-10-05T07:15:49+07:00"

REPORT_DRIVE_FOLDER_ID = "13xDIqiI-vyP10pkypLI_6palmeJS-QRg"
TASK_DRIVE_FOLDER_ID = "1T9_2fbCGa-q8N6kOZ69WAztLlGmJu60h"

PACKAGE_ZIP_NAME = "CONVERT2_TASK058_REPORT_PACKAGE.zip"
PACKAGE_SHA_NAME = "CONVERT2_TASK058_REPORT_PACKAGE.zip.sha256"

# 7 Distinct Parallel Lane Worker Specifications (Lanes A through G)
LANES_SPEC = {
    "LANE_A": {
        "worker_id": "WORKER_LANE_A_JNI_DEX_XREF",
        "name": "Lane A: JNI/RegisterNatives + DEX XREF Mapping",
        "script": "lane_a_worker.py",
        "deliverable": "raw_evidence/lane_a_jni_xref.json",
        "receipt": "raw_evidence/lane_a_receipt.json"
    },
    "LANE_B": {
        "worker_id": "WORKER_LANE_B_CFG_CALLGRAPH",
        "name": "Lane B: Native Call Graph, CFG & Function Boundary Analysis",
        "script": "lane_b_worker.py",
        "deliverable": "raw_evidence/lane_b_callgraphs.json",
        "receipt": "raw_evidence/lane_b_receipt.json"
    },
    "LANE_C": {
        "worker_id": "WORKER_LANE_C_GLSL_SHADERS",
        "name": "Lane C: GLSL/Shader & Effect Pipeline Kernel Extraction",
        "script": "lane_c_worker.py",
        "deliverable": "raw_evidence/lane_c_shaders.json",
        "receipt": "raw_evidence/lane_c_receipt.json"
    },
    "LANE_D": {
        "worker_id": "WORKER_LANE_D_IMAGE_EFFECTS",
        "name": "Lane D: Image Effect Graph & Parameter Semantics",
        "script": "lane_d_worker.py",
        "deliverable": "05_IMAGE_EFFECT_GRAPH_DELTA.md",
        "receipt": "raw_evidence/lane_d_receipt.json"
    },
    "LANE_E": {
        "worker_id": "WORKER_LANE_E_DECOMPILER_CONFIDENCE",
        "name": "Lane E: Decompiler Evidence & Rigorous Confidence Grading",
        "script": "lane_e_worker.py",
        "deliverable": "04_SO45_DELTA_MATRIX.md",
        "receipt": "raw_evidence/lane_e_receipt.json"
    },
    "LANE_F": {
        "worker_id": "WORKER_LANE_F_CROSS_APP_MINING",
        "name": "Lane F: F:\\App\\Image Cross-App Native & Source Mining",
        "script": "lane_f_worker.py",
        "deliverable": "06_F_APP_IMAGE_DELTA.md",
        "receipt": "raw_evidence/lane_f_receipt.json"
    },
    "LANE_G": {
        "worker_id": "WORKER_LANE_G_EVIDENCE_AUDITOR",
        "name": "Lane G: Integrator & Independent Evidence Auditor",
        "script": "lane_g_integrator.py",
        "deliverable": "00_AUDIT_INDEX.md",
        "receipt": "raw_evidence/lane_g_receipt.json"
    }
}

# The 8 Mandatory Law Documents with exact SHA-256 hashes
LAW_DOCS = [
    {
        "name": "00_AGENT_WORKFLOW_MASTER_CONSTITUTION",
        "path": REPO_ROOT / "scratch" / "law_docs" / "00_AGENT_WORKFLOW_MASTER_CONSTITUTION.txt",
        "doc_id": "1L8Fxp0g4D9kZhkxL5i6fEjbIhBhoHzhTkD4ufvXtkmA",
        "expected_sha256": "05783EDBB6F012C8D09FED7F6914EB82CF07D619291767D65A150EF163A16739"
    },
    {
        "name": "01_TASK_INTAKE_EXECUTION_STANDARD",
        "path": REPO_ROOT / "scratch" / "law_docs" / "01_TASK_INTAKE_EXECUTION_STANDARD.txt",
        "doc_id": "1667NJFOZCl8pMOmIjcehwy-b4HTFvOQ9acZyF8yARGE",
        "expected_sha256": "A22F87C717F9B9C71F86562E7C6844E98CB90E4D2F050A7C13779B450AD3CDD2"
    },
    {
        "name": "02_REPORT_EVIDENCE_SUBMISSION_STANDARD",
        "path": REPO_ROOT / "scratch" / "law_docs" / "02_REPORT_EVIDENCE_SUBMISSION_STANDARD.txt",
        "doc_id": "1NcQEpQu-9vf0KrT4yBus0OXfCRf6PSGguk6LUnVdA-M",
        "expected_sha256": "65C8A05E9929B2DE7CEE2BC8DA31B9E6F1DBBDBF89C10A3B4F4238B6A24329FE"
    },
    {
        "name": "03_GIT_COMMIT_CODE_AUDIT_STANDARD",
        "path": REPO_ROOT / "scratch" / "law_docs" / "03_GIT_COMMIT_CODE_AUDIT_STANDARD.txt",
        "doc_id": "1Z4Td8OS_JFvR19bLsb3jWp9mc1xP2GAacV8yoFEJTBQ",
        "expected_sha256": "AE8119C920753BB3C59AC880220566A0214311772B169977C56E4795E466A307"
    },
    {
        "name": "04_STATE_MACHINE_HANDOFF_STANDARD",
        "path": REPO_ROOT / "scratch" / "law_docs" / "04_STATE_MACHINE_HANDOFF_STANDARD.txt",
        "doc_id": "1438pbLdxBDvXxC8b7w2KjIUQRnkzdaILsX6mhBO91AM",
        "expected_sha256": "6EF1B73ABD0159641E0568CD31EEAB339AEC813DFCDD0D2A74A2E1F47593CC46"
    },
    {
        "name": "05_AGENT_STARTUP_CHECKLIST",
        "path": REPO_ROOT / "scratch" / "law_docs" / "05_AGENT_STARTUP_CHECKLIST.txt",
        "doc_id": "1B69KP_NrXhLY0zo2V8C55HnN7ySpNwOi_BdSd1AccDI",
        "expected_sha256": "5C4003955E06BCFCD3D4EBB81728E1F0542D7EF4D359AD8D5589BF84BD3A68B3"
    },
    {
        "name": "06_AGENT_MEMORY_BOOTSTRAP_SNIPPET",
        "path": REPO_ROOT / "scratch" / "law_docs" / "06_AGENT_MEMORY_BOOTSTRAP_SNIPPET.txt",
        "doc_id": "1rdCI9qUlhfQTpSsfU831NGfqY6NPp3rDXn9T4SExLXw",
        "expected_sha256": "230E100D2617535EEDDF71EA3AA0841A883527FBB8F2CD635493E2FB8E6C5978"
    },
    {
        "name": "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt",
        "path": REPO_ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt",
        "doc_id": "LOCAL_WORKSPACE",
        "expected_sha256": "10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F"
    }
]
