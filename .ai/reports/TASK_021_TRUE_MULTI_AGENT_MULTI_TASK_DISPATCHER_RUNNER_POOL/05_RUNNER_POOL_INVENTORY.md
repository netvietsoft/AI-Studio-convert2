# 05. SELF-HOSTED RUNNER POOL INVENTORY & HARDWARE TOPOLOGY
**Task ID:** `TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_DISPATCHER_RUNNER_POOL_ACTIVE`  
**Command ID:** `TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_20261003T074500+0700`  
**Date:** 2026-10-03  
**Status:** COMPLETE & VERIFIED

---

## 1. HOST SPECIFICATIONS
- **Host Name:** `OSIN`
- **Host Operating System:** Microsoft Windows 11 Enterprise / Pro (64-bit)
- **Host User:** `PC` (`PC.DESKTOP-81LIH38`)
- **Primary Repository:** `netvietsoft/AI-Studio-convert2`

---

## 2. REGISTERED RUNNER INVENTORY
All 3 self-hosted Windows runners are registered with the GitHub Actions repository backend:

| Runner ID | Runner Name | Installation Directory | Work Directory | Labels | Status |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **2** | `CONVERT2-WINDOWS-01` | `C:\actions-runner` | `C:\actions-runner\convert2` | `self-hosted`, `Windows`, `X64`, `convert2`, `worker-1` | **Online / Active** |
| **3** | `CONVERT2-WINDOWS-02` | `C:\actions-runner-02` | `C:\actions-runner-02\_work` | `self-hosted`, `Windows`, `X64`, `convert2`, `worker-2` | **Online / Idle** |
| **4** | `CONVERT2-WINDOWS-03` | `C:\actions-runner-03` | `C:\actions-runner-03\_work` | `self-hosted`, `Windows`, `X64`, `convert2`, `worker-3` | **Online / Idle** |

---

## 3. HOST TOOLCHAIN VERIFICATION
Each runner instance has verified access to the core toolchain required by CONVERT2:

| Tool | Path | Verified Version | Purpose |
| :--- | :--- | :--- | :--- |
| **Git** | `D:\SetupC\Git\cmd\git.exe` | 2.47.1.windows.2 | Branching, merging, commit provenance |
| **Python** | `C:\Python314\python.exe` | 3.14.0a2 | Orchestrator, metrics calculation, verification |
| **GitHub CLI** | `C:\Program Files\GitHub CLI\gh.exe` | 2.67.0 | Runner tokens, API dispatch, auth setup |
| **Antigravity CLI** | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\agy\bin\agy.exe` | 1.15.5 | Autonomous subagent execution engine |
| **Android ADB** | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe` | 35.0.2 | Physical test device automation & capture |

---

## 4. PHYSICAL TEST DEVICE CONNECTIVITY
The host machine maintains active wireless ADB connections to the designated physical target devices:

```text
List of devices attached
192.168.1.18:40159     device product:a07xx model:SM_A075F device:a07 transport_id:2
192.168.1.2:41775      device product:a50sxx model:SM_A507FN device:a50s transport_id:1
```

- **Primary Phone (Galaxy A07):** Samsung Galaxy A07 (SM-A075F)
- **Secondary Phone (Galaxy A50s):** Samsung Galaxy A50s (SM-A507FN)
- **Status:** Both devices verified attached and accessible via `scripts/acceptance/test_device_connectivity.ps1`.

---

## 5. AUTOMATED POOL MANAGEMENT
The pool is managed by [`scripts/bootstrap_convert2_runner_pool.ps1`](file:///C:/actions-runner/convert2/AI-Studio-convert2/AI-Studio-convert2/scripts/bootstrap_convert2_runner_pool.ps1), which provides:
1. Dynamic registration token retrieval from GitHub API (`repos/netvietsoft/AI-Studio-convert2/actions/runners/registration-token`).
2. Verification of installation folders and configuration parameters.
3. Health monitoring and automated restart of background listener processes (`run.cmd`).
4. Toolchain and environment variable propagation (`ANDROID_HOME`, `AGY_BIN`).

---

## 6. VERDICT
**VERDICT: PASS**  
The CONVERT2 self-hosted runner pool provides genuine 3-way concurrent capacity with full toolchain availability and physical device connectivity.
