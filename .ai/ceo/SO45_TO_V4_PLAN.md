# CEO task graph: SO45 extraction → V4 readiness

Authority: Chairman Tony, direct instruction 08/10/2026. CEO: current Codex session; execution lead: existing AGY ace29908-a2b0-4777-a070-6bd100509738. Local task/report folders are canonical for this campaign.

**Every dispatch, heartbeat, resumed/revised task and newly spawned AGY worker MUST read in full:**
`F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`.
Expected SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`. Record current path/hash/read timestamp in 00_AUDIT_INDEX.md. A recorded hash does not prove understanding; CEO audits actual work.

| Task | Initial state | Result required | Dependency |
|---|---|---|---|
| TASK_063 | ACTIVE | Verified 45-SO inventory, ELF completeness, old-evidence correction, exact lane inputs/targets, working AGY heartbeat receipt | none |
| TASK_064A | PLANNED | Core hair/mask/material pipeline native recovery | CEO ACCEPTED TASK_063 |
| TASK_064B | PLANNED | AI/model/NPU contracts and mask provenance | CEO ACCEPTED TASK_063 |
| TASK_064C | PLANNED | Color/LUT/render/composite and AR integration recovery | CEO ACCEPTED TASK_063 |
| TASK_064D | PLANNED | Image decode/encode/memory/FFT/GIF integration recovery | CEO ACCEPTED TASK_063 |
| TASK_064E | PLANNED | Video/audio/codec pipeline and graphics reuse boundaries | CEO ACCEPTED TASK_063 |
| TASK_064F | PLANNED | Shared runtime/hook/lock/crash boundaries and verified open-source exclusions | CEO ACCEPTED TASK_063 |
| TASK_064G | PLANNED | Networking/security/config/mfx boundaries; missing-input truth | CEO ACCEPTED TASK_063 |
| TASK_065 | PLANNED | Integrate body-backed graph/spec, independent formula parity and close TASK_061 audit findings | all seven lane reports audited |
| TASK_066 | PLANNED | V4 readiness decision, backlog and acceptance contract; no V4 production implementation | TASK_065 audited; TASK_062 status explicitly evaluated |

No automatic completion by folder names, task sequence, PID, file count, CRC or hashes. No “all tasks up to N completed.” CSV inventory is not algorithm recovery. Each library is either recovered to an evidence-backed relevant boundary, a verified standard/open-source/runtime exclusion with justification, or explicitly PARTIAL/BLOCKED with residual work. Missing vendor binaries remain UNKNOWN. V4 code requires a later explicit ACTIVE implementation task with architecture/contract and files_allowed.

All initially issued tasks are RESEARCH/DIAGNOSTIC; production app/lib modules and P0 are frozen for them. Existing TASK_062 remains NEEDS_FIX from independent audit; work is not lost, and research may run independently. TASK_059/060 supersession remains authoritative; do not replay them or restart old runners. All writes require leases; state/registry use atomic locking. CEO state is .ai/ceo/state.json, not the stale legacy .ai/state.json.

AGY lead claims active task, writes truthful PROGRESS.json and generates result artifacts. Maximum three simultaneous heavy native-analysis workers, separate report/script/evidence/Ghidra project folders per lane. If real AGY sessions are available, delegate them with bounded scope; if unavailable, report the actual process-based execution mode rather than pretending multiple AI agents. Do not issue expensive duplicate decompilations of the same binary. CEO controls activation and review, so worker completion cannot self-open dependent tasks.

Report protocol: report_folder/00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, raw command logs, evidence manifest, scripts/code hashes, PROGRESS.json for intermediate updates, COMPLETE.json for frozen review candidate. COMPLETE.json contains schema_version, task_id, revision, status COMPLETE, standard_sha256, files mapping relative report paths to actual SHA-256 (excluding COMPLETE.json itself and volatile PROGRESS.json), code_files list of repo-relative generator/script paths. Final state is REVIEW_CANDIDATE_AWAITING_CEO, not product PASS. CEO independently reviews at least 10% of ordinary claims and all critical math/input/provenance claims, writes disposition bound to fingerprint, then authorizes commit/push on task branch. Record real commit only after it exists; update/rehash final provenance after commit. Do not stage/delete unrelated workspace changes.

Minute loop: CEO heartbeat reads rule → controller scan → inspect changed progress/code/report → independently verify → issue/revise bounded next task → notify Tony once per dispatch or material AGY progress. No messages for empty scans or repeated identical progress. AGY heartbeat reads rule → claim eligible exact ACTIVE revision → execute/report → return to scanner. Scheduler busy ticks are not successful scans. Persistent heartbeat records and first successful deliveries must be verified; do not claim continuous operation from registration alone.
