# TASK_060 continuation checkpoint

Task remains incomplete. Source baseline: 5eca94001b6b80fdff80f4ab0a1cea61cc8523b7. Observed pre-fix ACK: 13e7d39094e577ec045ab1209f622b596baf885e; observed worker run 37401017912 failed on AGY authentication. Current work is a local code correction and evidence package, not a resumed GitHub worker or TASK_059 technical completion.

Completed: current Drive intake; original-workspace read-only preflight; independent remote architecture/log audit; isolated checkout and file leases; failure-state/global-reconciliation correction; 46 passing local tests; independent bounded-source approval. Technical commit f9c7c814150596c2ed799452c7f8d835336b1b46 published on codex/task060-ack-failure-state-20261006; draft PR https://github.com/netvietsoft/AI-Studio-convert2/pull/2. No main merge or corrected live run occurred.

Remaining: verify report mirror; identify the approved unattended setup's location/method supplied by the user; verify AGY readiness in Network Service; full runner labels/environment, durable heartbeat, current-run ACK binding and TASK_059 ordering/handoff/resume gates. Do not reuse the stale CLI token, copy another profile's credentials, or retry technical lanes before readiness.

Recovery: reload AGENTS.md, Docs/rules.md, the dated workspace standard and canonical Drive docs 00–07; check this branch's exact Git SHA, leases and raw evidence; reconcile current remote main and matching GitHub jobs without overwriting newer claims. Read ERR-20261006-001/002 and ACQ-20261006-001. Resume the existing TASK_060 and TASK_059 identities; do not create TASK_061 or duplicate commands.

Next safe action: finish reviewable correction and wait for the authentication setup location. This checkpoint does not mark the task completed and does not authorize a protected-main merge or a new credential.

Concrete remaining mechanisms identified by /root/failure_state's read-only audit:

- Dispatcher ACK polling in scripts/command_bus_orchestrator.py accepts populated execution identity without matching current reservation token, dispatcher identity, worker github_run_id or lease expiry. Fetch status is not checked, and timeout rollback does not revalidate canonical reservation ownership. A diagnostic reads run_id while the writer stores github_run_id. Test stale ACKs, failed fetches and replaced reservation before any live rerun.
- Default claimed lease is 1,800 seconds while wrapper runtime timeout is 90 minutes and workflow timeout is 120 minutes. heartbeat_command currently changes a local command only; no wrapper/workflow heartbeat publication occurs. Reservation recovery uses 180 seconds while ACK polling defaults to 240. Require durable renewal, fenced heartbeat loss recovery and evidence beyond the original lease duration.
- Targeted reserve filters after priority/greedy readiness selection. Existing higher-priority TASK_059P can therefore exclude original TASK_059 even when specifically targeted. Implement canonical ordering and explicit scope/lease handoff without marking TASK_060 complete early or duplicating either command. Acceptance requires the existing original TASK_059's real durable RUNNING identity.

Likely next-gate scope: orchestrator, wrapper, worker/dispatcher workflows, existing TASK_059 command metadata and canonical lease/state records. Current code commit contains the bounded failure correction only. These findings are not implemented or fixture-verified yet.
