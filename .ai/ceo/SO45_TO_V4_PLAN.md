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

## CEO escalation recorded 2026-10-08

TASK063 R3 fingerprint2041a6a220c14965c37a6f9634e160f7ef5ac5ef91675fd134fb0ded9c2e0f10 is independently NEEDS_FIX. The final bounded correction route is now BLOCKED/ESCALATION_REQUIRED; token1011 revoked, immutable R3 task/report/scripts/review snapshot retained, original max_fix_cycles3 and attempts1–3 unchanged. Read .ai/ceo/reviews/TASK_063_R3_2041a6a2_NEEDS_FIX.md and RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_063_R3_REVIEW_AND_ESCALATION.md.

TASK067 revision1 is a distinct one-attempt/45-minute causal diagnostic: reproduce input classifier, retained-disassembly parser and critical-provenance failures; measured counterexamples and repair recommendation only. It must not regenerate baseline/lane assignments, edit R3, reset retries or auto-reopen063. Acceptance of067 cannot satisfy064 dependencies. CEO must separately record the recovery disposition after diagnostic review;064A..G/065/066 remain PLANNED and V4 remains gated.

Actual persistent diagnostic worker:7de71900-89f8-4633-97a9-3efaf42ea6b8, codex/gpt-6.1-sol, workspace wks_4ed49b4b5b9607c2. This is a Codex worker under AGY coordination, not another Antigravity session. Antigravity provider availability fluctuates and recent native runs failed on connectivity/provider errors; report actual dated status, never infer success from registration. Existing CEO heartbeat supervises067; no duplicate heartbeat. Before dispatch inspect the actual worker status: only send exact ACTIVE revision if idle and not acknowledged; never resend while running. The read-only boot prompt is not a task claim. All writes require exact controller claim and nonoverlapping scopes.

TASK067 current execution revision is **R2**, an actor-identity handoff before any diagnostic attempt, not a second retry. The Antigravity lead issued an invalid claim using the other worker's ID;1012 was revoked and that lead's affected turn canceled. Actual Codex BOOT confirms no writes/claim. External Paseo ID7de71900-89f8-4633-97a9-3efaf42ea6b8 maps to native CODEX_THREAD_ID01a119f1-f400-7441-8b7a-26375ae0f459; these identifier types must not be confused. Only the actual assigned recipient receives a private dispatch challenge, whose hash/task/revision is in config. A bound worker must supply --dispatch-token to claim/renew; NEVER log or publish the nonce. Metadata IDs alone do not prove who issued a claim. Revoked state claims/leases cannot reactivate their old fencing token. Current R2 reports RULES/REPORT/TASK_067_REPORT_R2, scripts/task067_diagnostic_r2/**, evidenceTASK_067_R2/**. R2 exact prompt sent to verified idle actual worker; successful claim still needs actual worker evidence. Lead ace29908-a2b0-4777-a070-6bd100509738 has no assigned ACTIVE edit task, must scan only for its own identity, never copy another task's agent_id. Native heartbeat updates through schedule API are not found; no replacement heartbeat was registered. Read TASK_067_IDENTITY_REBIND.md and current task before further action.


## TASK068 reference acquisition - Chairman direct instruction2026-10-08
PhotoCraft/LightCraft/FilmCraft pinned sources acquired by actual CEO root under separate exact task lease; read-only collaboration reviewers inspect mapping/integrity. No simulated AGY worker. External references live beside evidence under .ai/reconstruction/reference_sources/storytold and indexDocs/Reconstruction/References/storytold. This supplementary task has no baseline replacement or V4/064 authorization. TASK067 remains independent. See exactTASK068 ACTIVE. Do not dispatch this CEO-assigned task to Antigravity lead orTASK067 worker.
