# Local verification of bounded failure correction

Source target commit: f9c7c814150596c2ed799452c7f8d835336b1b46.

Actual command in isolated checkout:

```text
python -B -m unittest tests.test_command_bus_failure_state tests.test_command_bus_orchestrator tests.test_command_bus_state_reconciliation tests.test_command_bus_lifecycle_invariants tests.test_state_truth_and_gate_consistency tests.test_runner_failure_publication -v
```

Result: 46 tests passed in 92.914 seconds; native exit code 0. Suites: failure state 13, orchestrator 10, state reconciliation 5, lifecycle invariants 6, state truth 5, runner publication 7. Full PowerShell-hosted output is raw_evidence/local_regression_tests.log. PowerShell formats the initial Python stderr line as NativeCommandError; the test process actually exited 0 and reported OK. This host formatting is not a failed test or suppressed failure.

New regressions verify stale lease rejection without mutation, exact failed execution records, preservation of newer active/completed same-task state, concurrent failure records, contended Windows handle cleanup, actual rejected/accepted CLI transitions, lifecycle-only publication, concurrent main advancement, replaced canonical lease/run fencing, non-concurrent push denial, legacy branch preservation, nonzero executable preflight, zero-exit rejected start, and exclusion of the advisory lock. Git/PowerShell publication fixtures use real local repositories and processes with an explicitly MOCK AGY runtime. They do not authenticate or execute technical task work.

PowerShell AST parsing passed without errors. Python compile() passed for the orchestrator and two new test files without writing bytecode. Whole-worktree git diff --check passed; normal LF-to-CRLF warnings are not findings.

No app build, benchmark, physical-device acceptance or corrected live Actions execution is claimed. Directory-uniqueness checks do not prove that a worker is alive. TASK_060 A–E acceptance and TASK_059 resume remain unresolved.
