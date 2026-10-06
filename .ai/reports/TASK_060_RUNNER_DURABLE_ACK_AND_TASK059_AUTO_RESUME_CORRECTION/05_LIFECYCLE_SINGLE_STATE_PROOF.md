# Lifecycle truth

At source snapshot 5eca94001b6b80fdff80f4ab0a1cea61cc8523b7, TASK_060 exists in running with its prior execution identity, while the matching GitHub job is completed with failure. The worker's existing six lifecycle tests pass because directory uniqueness does not establish a live worker.

The wrapper pushed its task branch before fail_command and threw afterward. fail_command also omitted global-state reconciliation. The proposed correction publishes terminal lifecycle metadata after runtime failure, validates the current canonical lease before publication, and preserves a different or newer command's global state. Only lifecycle metadata is published; task source/evidence requires the existing integration review path.

Validation of the correction and its exact test results will be recorded in TEST_REPORT.md. Local fake AGY fixtures are labeled MOCK and do not constitute live runner acceptance.

