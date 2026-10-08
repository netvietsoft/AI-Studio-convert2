# Chairman Bash popup investigation — CHAIR_BASH_POPUP_20261008

Observed command: Git Bash running ralph-wiggum/1.0.0/hooks/stop-hook.sh. The measured original snapshot contained five root bin/bash processes and five child usr/bash processes with that exact hook; PID reuse prevents inferring a current parent from old PID alone. Later those processes were already absent before the CEO changed configuration; CEO killed no process.

Source order: stop-hook reads HOOK_INPUT=$(cat) before checking .claude/ralph-loop.local.md. The state file was absent in this workroot. Waiting on open stdin in an inactive hook is a supported explanation; exact low-level launch flags of the original parent are not proven.

Reversible mitigation: only plugins.ralph-wiggum@claude-code-plugins.enabled changed true to false in the user's Codex profile. A complete backup remains outside the repository. Parsed deep equality confirmed every other configuration value unchanged. Native Paseo Stop hooks and schedules were preserved. No plugin-cache source edit, daemon restart, process kill, or production/P0 change was performed.

Verification: .ai/ceo/receipts/BASH_POPUP_RALPH_HOOK_FIX_20261008.json binds config hashes, backup path and measured UTC/process count. At 2026-10-08T07:08:55.3767190Z the exact Ralph hook Bash process count was zero, Ralph enabled was false, and native Paseo Stop hook remained present. Cached-runtime/long-term popup absence is not yet proven. Do not publish the profile or its backup: they can contain unrelated credentials.

Authority: Chairman's explicit Bash investigation/fix request. Host maintenance lease LEASE-CEO-HOST-BASH-POPUP-20261008/fence1017 was acquired for the exact external configuration/backup scope and released after the change. This report/checkpoint uses the live CEO lease/fence1007. Audit source: canonical Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt, SHA25610968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F; AGENTS.md, Docs/rules.md and CEO plan were reread on current wake. No product build/device gate applies to this host-only mitigation. No independent final verdict is claimed for the interrupted read-only helper session.

Operationally separate issue: actual native schedule receipts repeatedly report daemon restarts before scheduled runs complete; AGY provider also reports connectivity errors. The Ralph mitigation does not prove continuous successful heartbeat delivery. Existing native CEO heartbeat9ed2909e and AGY068c797c remain registered; no duplicate heartbeat was created.
