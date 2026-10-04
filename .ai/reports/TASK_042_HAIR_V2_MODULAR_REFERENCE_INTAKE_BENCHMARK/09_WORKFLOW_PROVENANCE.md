# 09. WORKFLOW PROVENANCE & COMMAND BUS LIFECYCLE

**Task**: TASK_042 — HAIR V2 MODULAR REFERENCE INTAKE & BENCHMARK  
**Authority**: Tony  
**Protocol**: CONVERT2_COMMAND_V2  
**Canonical Standard**: `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`  

---

## 1. Identity & Execution Provenance

| Parameter | Value |
|---|---|
| **Command ID** | `TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_20261004T121700+0700` |
| **Task ID** | `TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_ACTIVE` |
| **Task URL** | `https://docs.google.com/document/d/1AgkgdN34EVnE6tZNjUo6yoR07xYrjdFD4xXvK_yOiG4/edit` |
| **Task Revision** | `2026-10-04T12:17:00+07:00` |
| **Dispatch SHA** | `2281b60e2715cb511d6ea6546c5112a24e72279c` |
| **Baseline SHA** | `ff14b3e5f998051436d330202df5297b0070de3d` |
| **Execution Lane** | `hair-v2-modular-reference-intake-benchmark` |
| **Runner Label** | `CONVERT2-WINDOWS-02` |
| **Runner Identity** | `GITHUB_ACTIONS_37179547870` |
| **GitHub Run ID** | `37179547870` |
| **Dispatcher Run ID** | `37179498681` |
| **Predecessor Task** | `TASK_041_TASK040_SOURCE_TRUTH_CORRECTION_V1_NATIVE_CPP_PROVENANCE_ACTIVE` |
| **Anti-Duplicate Key** | `TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_ACTIVE:2026-10-04T12:17:00+07:00` |

---

## 2. Command Bus Lifecycle Transitions

```
[TASK_SCANNER] -> ACTIVE Task Detected (TASK_042, Status: ACTIVE)
       |
       v
[PREFLIGHT] -> Validate Dependencies (TASK_041 PASS verified)
       |
       v
[LEASE & CLAIM] -> Leased at 2026-10-04T12:26:52.055370+07:00 (Expires: 12:56:52)
       |
       v
[EXECUTE] -> Analyze 16 V1 modules, build 01 inventory & 02 crosswalk CSVs
       |
       v
[BENCHMARK] -> Run isolated benchmark harness across 9 canonical portraits on physical devices (SM-A075F, SM-A507FN)
       |
       v
[EVIDENCE & VISUALS] -> Collect 54 comparative images, native execution logs, and timing metrics
       |
       v
[REPORT & SPECIFICATION] -> Draft deliverables 00-10, compile report zip and SHA256 manifest
       |
       v
[HANDOFF] -> Update task status to COMPLETED, state to IDLE_WAIT_FOR_TASK
```

---

## 3. Allowed Paths Compliance

All generated artifacts and modified files conform strictly to `allowed_paths` defined in the command specification:
- `.ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK/**` (Deliverables 00–10 + raw evidence)
- `.ai/state/tasks/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_ACTIVE.json` (State update)
- `.ai/commands/**` (Index & running status update)
- `.ai/state.json` (Master state update)
- `TASK_LOG.md` (Operational audit log)
- `scratch/task042/**` (Benchmark scripts and temporary files)

Zero modifications were made to production source directories (`lib-core-graphics/`, `app/`).
