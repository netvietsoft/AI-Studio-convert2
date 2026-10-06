# TASK_060 infrastructure correction checkpoint

Verdict: BLOCKED for live execution; source correction independently reviewed and verified by 46 passing local tests. This does not mark TASK_060 or TASK_059 complete.

Technical target commit: f9c7c814150596c2ed799452c7f8d835336b1b46. Draft PR: https://github.com/netvietsoft/AI-Studio-convert2/pull/2. Report Drive checkpoint: https://drive.google.com/drive/folders/1sNti6NnRw69l0igohJl32H0tfDX1GHWp. Package mirror verification is recorded separately after upload; folder creation alone is not a verified package mirror.

The inspected real worker did persist durable ACK before long execution. Dispatcher run 37400905046 succeeded; worker run 37401017912 started on CONVERT2-WINDOWS-01 under NT AUTHORITY\NETWORK SERVICE and committed ACK 13e7d39094e577ec045ab1209f622b596baf885e. AGY 1.2.17 then requested authentication, timed out after 60 seconds and exited 1. Thus the current observed blocker occurs after ACK. The API and log timestamp differences are retained without an unsupported clock-alignment claim.

The wrapper published its task branch before marking failure and never published the later FAILED mutation. Source baseline 5eca94001b6b80fdff80f4ab0a1cea61cc8523b7 therefore still contained RUNNING after the real job failed. The orchestrator also omitted global failure reconciliation, and contended Windows lock acquisition leaked handles. Local regression tests reproduced these defects. Review additionally identified zero-exit rejected start/complete transitions and an attempt-branch namespace conflict with legacy agent/COMMAND branches.

The bounded correction records FAILED before task-branch publication, publishes only lifecycle metadata from fresh canonical main, validates both current lease and GitHub run identity, retries normal pushes only after observed concurrent main advancement, and retains failed publication worktrees for inspection. It preserves newer per-task/global execution and completed results. Attempt branches have unique sibling names, normal pushes and no transient .bus.lock. CLI start/complete/fail rejection returns nonzero; wrapper requires explicit accepted transition output. No runtime retry occurs during publication retries. Source/evidence integration remains on the existing review path.

Required acceptance gaps:

- Approved unattended authentication setup exists per user; its configuration location or setup method is still pending. No credentials were copied, created or printed.
- Complete registered runner label inventory and intended Windows routing remain unverified. Job labels report requirements, not all registered labels.
- Required toolchain/path access must be checked inside an authenticated job under the actual service profile.
- Durable heartbeat, dispatcher ACK binding to the current reservation/run and resilience beyond the bounded failure correction remain unresolved.
- Corrected code has not been integrated or exercised in a new real GitHub job.
- TASK_059 ordering, safe scope handoff and real durable RUNNING proof remain unresolved. Existing TASK_059/TASK_059P identities were not duplicated.

Local fixture verification cannot satisfy the live A–E gates. No app build or physical-device acceptance is claimed for this command-bus checkpoint. P0, app source and hair-engine thresholds were untouched.

Next actions: finalize and publish the independently reviewed branch/report; receive the approved setup location/method; verify it without exposing credentials in the Network Service environment; resolve remaining A–D gates with bounded real execution; then resume the existing TASK_059 identity and its substantive lanes. Completion records remain unchanged. Scanner must return after genuine task completion; this blocked checkpoint is not a completion event.
