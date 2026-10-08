# CEO controller tooling handoff — 2026-10-08

Implemented under `LEASE-CEO-TOOLSMITH-20261008`, fencing token 1008. Only controller.py, test_controller.py and this handoff were written; no commit, production edit, real task/report edit, registry mutation or legacy AGY-state write was performed by the toolsmith.

Canonical file read in full:
`F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`
Measured SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F` (v2.1.2).
Also read AGENTS.md, Docs/rules.md, PROJECT_ERROR.md (especially ERR-010 through ERR-014), ACQUIREMENTS.md (especially ACQ-006/009/010), README.md, relevant current task/plan, registry and Git status. The null-verdict regression discovered here was fixed and is covered by an offline dependency invalidation test; no durable production-error entry is warranted.

## Operator interface

Run with `python -B` to avoid writing bytecode outside the assigned scope. Default root is derived from the controller location; `--root` must precede the command.

```powershell
python -B .ai/ceo/controller.py scan
python -B .ai/ceo/controller.py status
python -B .ai/ceo/controller.py renew
python -B .ai/ceo/controller.py claim --task-id TASK_063 --agent-id ace29908-a2b0-4777-a070-6bd100509738 --standard-sha 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f
python -B .ai/ceo/controller.py ack-review --task-id TASK_063 --fingerprint <current-SHA> --disposition ACCEPTED --review-file .ai/ceo/reviews/TASK_063_R1.md
```

`scan` returns newly observed JSON events, current selected task summaries and readiness/findings; it persists observations in `.ai/ceo/state.json`. It does not accept tasks or issue/activate successors. Empty scans do not generate events. `status` is read-only and labels stored observations as potentially stale. `renew` renews only the still-live CEO lease for 12 hours, preserving its fencing token and every other lease. Expired/revoked CEO leases require deliberate recovery by the parent; this CLI cannot resurrect them. `claim` returns exit 2 and a persisted BLOCKED reason on a valid-transaction rejection, or grants/renews a 2-hour exact task scope lease. Same-owner renewal retains fencing; different-owner takeover, including after expiry, is forbidden. Orphaned/partial claims require a reviewed CEO handoff, never automatic cleanup. `ack-review` records only the CEO's explicit verdict: ACCEPTED, NEEDS_FIX or BLOCKED_INPUT. It is not a technical validation engine. Runtime session identities passed to the CLI are assertions, not authentication credentials.

The parent CEO lease must cover `.ai/ceo/state.json`, `.ai/ceo/control.guard`, `.ai/locks.json`, `.ai/locks.registry.guard`, and `.ai/locks.ceo.*.tmp`. Runtime lease identity defaults to `Codex_CEO`; optional config `ceo_lease_agent_id` changes that identity. Config `ceo_agent_id` identifies the reviewing runtime in recorded verdicts. `AGY_LEAD` requires metadata `agent_id` or config `agy_agent_id`; `AGY_TEAM`/`AGY` workers must appear in config `worker_ids` or be the configured lead. Exact agent assignees also work. The common registry guard is a permanent OS one-byte lock on Windows (`msvcrt`) or POSIX `flock`, matching parent/prior reviewer writers; it is never deleted, replaced or stolen. Control/state and registry writes serialize in that order, use content/revision CAS and atomic fsync + replace. Busy guards fail immediately; there is no busy wait. Controller state contains the durable deduplicated event log; no separate event file is currently emitted.

## Task/report contract

Only exact config task_ids are scanned. Unstructured legacy documents are ineligible. Leading human-readable task headings are supported, followed by fenced JSON metadata with schema_version 2.1.2, exact task_id, positive integer revision, exact status ACTIVE, assignee, priority, dependencies, files_allowed, files_forbidden and report_folder. Non-ACTIVE metadata cannot authorize a claim. Duplicate configured IDs fail closed. Dependency entries must be objects such as `{"task_id":"TASK_063","revision":1}`; a plain task ID does not specify an accepted revision and blocks dependency resolution.

Place exactly one `COMPLETE.json` or `FREEZE.json` in the exact declared report_folder. Examples use COMPLETE; FREEZE requires status FREEZE. Fields:

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_063",
  "revision": 1,
  "status": "COMPLETE",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "files": {"00_AUDIT_INDEX.md": "<actual-sha>", "01_MASTER_REPORT.md": "<actual-sha>"},
  "code_files": ["scripts/task063/generator.py"]
}
```

The files map must cover every final report file recursively, excluding the manifest itself and root-level volatile PROGRESS.json/PROGRESS.md. There may be no missing/extra paths or incorrect hashes. `00_AUDIT_INDEX.md` must contain the standard filename and current SHA; task instructions still require full path, read timestamp, identity and fence. A hash receipt verifies bytes and records the worker's assertion of reading; it cannot prove that the worker read or understood the law. `code_files` may also be a path-to-SHA map, which checks declared code hashes. Generator files under the task's `scripts/**` scopes are hashed even if omitted from code_files. Symlinks/path escapes in reports are rejected. Report/code paths are repository-relative. Optional task `source_files` accepts repository-relative concrete source files. Config `source_roots` is the exact directory whitelist for external SO inputs: every immediate `*.so` in each root is independently hashed (path, SHA-256, byte size) and bound to every final snapshot. Nested folders and other file types are not scanned; missing roots, empty roots, symlink inputs and read errors block final readiness. Source inputs are hashed once per scan and reused across that scan's dependency checks. External F:/TOOLS Ghidra write scopes are supported for collision detection but are not automatically scanned as source.

Readiness requires a valid manifest and identical task-byte/report/code/standard fingerprint on a second scan at least 60 seconds later. Mtime alone cannot establish or invalidate completion. Root-level progress updates are fingerprinted and notified separately without making a final report unstable. Readiness means eligible for CEO review, never PASS or ACCEPTED. A nonempty review file within `.ai/ceo/reviews` and exact current fingerprint are required to acknowledge a disposition. All dispositions currently require stable valid final packaging; malformed/intermediate packages produce findings rather than a verdict. ACCEPTED additionally requires fresh CEO acceptance of each declared dependency revision. Later task/report/source-code/standard edits or replacement of the review file invalidate an acceptance and block successors. Parent must keep the accepted task revision unchanged or perform an explicit revision/review cycle.

Scopes are normalized case-insensitively across relative/absolute paths and checked conservatively against every live registry lease. Research/diagnostic/audit/review claims reject production scopes; known frozen P0 files/model locations are forbidden in all modes. Conservative glob checking may block a safe but ambiguous scope; narrow it through a reviewed task revision. Maximum live claim concurrency defaults to three, or config concurrency_limit. Accepted worker leases must be explicitly released/revoked by the CEO after scoped Git publication, through the common guard/CAS, to avoid reserving capacity for the full two-hour TTL. This pass intentionally adds no automatic release or takeover CLI. The controller cannot enforce an agent's filesystem writes outside the scope; agents must check their current lease before each write.

## Validation and limits

`python -B .ai/ceo/test_controller.py -q`: **26/26 offline tests passed**, 7.465 seconds, exit 0, 2026-10-08. Test root, standard fixture, state/registry and clock are isolated in TemporaryDirectory; these tests make no SO45/product/physical-device PASS claim. Coverage includes false folder completion, exact ACTIVE/64A/64B IDs, leading task headers, 60s stability, content-vs-mtime, partial/malformed manifests, progress dedup, hash coverage, FREEZE/audit receipts, source edits, revision/stale-review rejection, review-file replacement, same-owner renewals, other-owner and stale-owner exclusion, standard/lead mismatch, CEO expiry, unchanged unrelated leases, frozen/research production scopes, parallel crossscope collision, permanent/busy guard and registry/fencing CAS, and END_AGENT_SESSION. Added regressions verify exact external SO-root content, source byte changes despite unchanged mtime, missing/empty roots, and ignored empty/FALSE/malformed end flags.

Read-only real `status` verified a live CEO lease and parent-created state. Read-only task parsing recognized TASK_063 ACTIVE and TASK_064A–G/TASK_065/TASK_066 PLANNED. No real mutating command was run by the toolsmith. Parent reports actual AGY TASK_063 claim token 1009 at 03:51 UTC and heartbeat 068c797c; this is parent-supplied runtime evidence, not an independent claim by the toolsmith. The helper is one-shot; the external Paseo session heartbeat must trigger it around every 60 seconds. `.ai/ceo/END_AGENT_SESSION.flag` stops scan/claim/review only when it contains explicit TRUE, literal JSON true, or END_AGENT_SESSION = TRUE (whitespace allowed). Empty/FALSE/invalid file content does not halt the campaign. Status still reads and renew remains an explicit maintenance operation.

Human/CEO review must independently check true binary bodies, arithmetic, JNI offsets/xrefs, manifests, reproduction commands, Git changed/staged coverage, branch/commit provenance, physical-device/product gates and residual blockers. The controller does not run builds, tests, Git commits/pushes, decompilation, proof sampling, V4 gates, or old command-bus runners. No automatic report mirroring or task issuance. External SO byte hashes establish input identity and review freshness; they do not establish correct native algorithm recovery or product acceptance.
