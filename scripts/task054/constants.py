"""
TASK_054 Constants & Canonical Identifiers
Authority: Chairman Tony
Target Task: TASK_054_TASK053_EXECUTION_IDENTITY_STATE_AND_CONTINUOUS_SO45_CORRECTION_ACTIVE
"""

from pathlib import Path
from datetime import timezone, timedelta

REPO_ROOT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")
REPORTS_ROOT = REPO_ROOT / ".ai" / "reports"
TASK054_DIR = REPORTS_ROOT / "TASK_054_TASK053_EXECUTION_IDENTITY_STATE_AND_CONTINUOUS_SO45_CORRECTION"
RAW_EV_DIR = TASK054_DIR / "raw_evidence"
REV_ENG_DIR = REPO_ROOT / ".ai" / "reverse_engineering"
STATE_FILE = REPO_ROOT / ".ai" / "state.json"
DOCS_RECON_DIR = REPO_ROOT / "Docs" / "Reconstruction"

VN_TZ = timezone(timedelta(hours=7))

# Canonical Execution Identifiers
TASK_ID = "TASK_054_TASK053_EXECUTION_IDENTITY_STATE_AND_CONTINUOUS_SO45_CORRECTION_ACTIVE"
TASK_DOC_ID = "1c9VCsGTP-Yd-S5yjDe1yyleKY9dri45ThFkYB20h1A8"
TASK_MODIFIED_TIME = "2026-10-05T05:57:52.416000+07:00"

GITHUB_RUN_ID = "37237229130"
JOB_ID = "111538927164"
RUNNER_IDENTITY = "CONVERT2-WINDOWS-02"
DISPATCH_COMMAND_ID = "TASK_054_SO45_CONTINUOUS_CORRECTION_20261005T055800+0700"
BASELINE_COMMIT_SHA = "284cd0c5f33cfa4f324332510ed2425ce6979b5d"
DISPATCH_COMMIT_SHA = "284cd0c5f33cfa4f324332510ed2425ce6979b5d"
ANTI_DUPLICATE_KEY = "TASK_054_TASK053_EXECUTION_IDENTITY_STATE_AND_CONTINUOUS_SO45_CORRECTION_ACTIVE:2026-10-05T05:57:52+07:00"

CANONICAL_BASELINE_COMMIT_SHA = BASELINE_COMMIT_SHA
CANONICAL_DISPATCH_COMMIT_SHA = DISPATCH_COMMIT_SHA
CANONICAL_GITHUB_RUN_ID = GITHUB_RUN_ID

REPORT_DRIVE_FOLDER_ID = "13xDIqiI-vyP10pkypLI_6palmeJS-QRg"
TASK_DRIVE_FOLDER_ID = "1T9_2fbCGa-q8N6kOZ69WAztLlGmJu60h"

PACKAGE_ZIP_NAME = "CONVERT2_TASK054_REPORT_PACKAGE.zip"
PACKAGE_SHA_NAME = "CONVERT2_TASK054_REPORT_PACKAGE.zip.sha256"

# 7 Distinct Parallel Lane Worker Identities
LANES_SPEC = {
    "LANE_A": {
        "worker_id": "WORKER_LANE_A_ELF_METRICS",
        "name": "Lane A: ELF Header, Symbols, Relocations, Build-ID, and Section Analysis",
        "focus": "Comprehensive metadata audit of all 45 vendor .so libraries",
        "output_files": ["02_45_SO_MASTER_MATURITY_MATRIX.csv"]
    },
    "LANE_B": {
        "worker_id": "WORKER_LANE_B_CFG_DISASM",
        "name": "Lane B: Disassembly, CFG, Function Boundaries, and Caller-Callee Chains",
        "focus": "Deep disassembly of priority functions (Hair, Face, Skin, Body, Render)",
        "output_files": ["03_FUNCTION_MASTER_REGISTRY.csv", "04_CALLER_CALLEE_XREF_GRAPH.csv"]
    },
    "LANE_C": {
        "worker_id": "WORKER_LANE_C_DEX_JNI",
        "name": "Lane C: DEX Bytecode, JNI Exports, and Dynamic RegisterNatives Mapping",
        "focus": "End-to-end tracing from Android Kotlin UI down to C++ native function addresses",
        "output_files": ["05_DEX_JNI_REGISTER_NATIVES_GRAPH.csv"]
    },
    "LANE_D": {
        "worker_id": "WORKER_LANE_D_SHADER_MODEL",
        "name": "Lane D: Shaders, Neural Models, Rodata Strings, and Mathematical Constants",
        "focus": "Extracting embedded GLSL, Gaussian kernels, color matrices, neural runtime graphs",
        "output_files": ["06_SHADER_MODEL_CONSTANT_EVIDENCE.csv"]
    },
    "LANE_E": {
        "worker_id": "WORKER_LANE_E_CLEANROOM",
        "name": "Lane E: Clean-Room C++ Semantic Pseudocode and Reimplementability",
        "focus": "Pure Clean-Room C++ specifications adhering strictly to Rule 11",
        "output_files": ["07_PSEUDOCODE_REIMPLEMENTABILITY_REGISTRY.csv"]
    },
    "LANE_F": {
        "worker_id": "WORKER_LANE_F_EFFECT_GRAPH",
        "name": "Lane F: Unified Image Effect Graph, Next Probes, and Ablation Plan",
        "focus": "8-stage image effect pipeline, unknown cluster probes, and A/B verification strategy",
        "output_files": ["08_IMAGE_EFFECT_GRAPH.md", "09_UNKNOWN_CLUSTERS_AND_NEXT_PROBES.md", "13_ABLATION_AB_VERIFICATION_PLAN.md"]
    },
    "LANE_G": {
        "worker_id": "WORKER_LANE_G_AUDITOR",
        "name": "Lane G: Independent Evidence, Provenance, and Non-Fabrication Auditor",
        "focus": "Cross-verifying raw dumps, ensuring zero unsupported claims, auditing timestamps",
        "output_files": ["10_MULTI_AGENT_LANE_PROVENANCE.md"]
    }
}

LAW_FILES = [
    {
        "name": "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt",
        "path": REPO_ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt",
        "expected_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
    },
    {
        "name": "Development_Workspace_Standard_V2.1_Design_Gated.txt",
        "path": REPO_ROOT / "Development_Workspace_Standard_V2.1_Design_Gated.txt",
        "expected_sha256": "016fa11c002cb04b36349599de8e54ee768715621bc104d1f89e4df24a61b650"
    },
    {
        "name": "AGENTS.md",
        "path": REPO_ROOT / "AGENTS.md",
        "expected_sha256": "90d29b6113dfbe07fcdd6fbc6a50d93790c77bde718b5932884989712d0181fa"
    },
    {
        "name": "GEMINI.md",
        "path": REPO_ROOT / "GEMINI.md",
        "expected_sha256": "0fd343b8ca821ec3e65c792d7fddf13c5a0bafef798dcd1dcb16051ff90ab0ae"
    },
    {
        "name": "scratch/07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD.txt",
        "path": REPO_ROOT / "scratch" / "07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD.txt",
        "expected_sha256": "60a3646a9efc7ca150a85909c9186c9a114a3d669bb24d4440914f624908c9ff"
    }
]
