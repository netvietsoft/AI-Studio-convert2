# Observed timeline

| Event | Evidence |
|---|---|
| Dispatcher run 37400905046 | Completed successfully; raw dispatcher ACK excerpt |
| Worker run 37401017912 | Completed with failure; job 112067979241 |
| Claim/start | Embedded log 2026-10-06 01:47:26 UTC; reservation token and run recorded in command snapshot |
| Durable ACK commit | 13e7d39094e577ec045ab1209f622b596baf885e |
| ACK pushed to main | Embedded log 01:47:31 UTC |
| AGY launch | Embedded log 01:47:32 UTC |
| Authentication timeout | Embedded log 01:48:32 UTC |
| Runtime exit 1 | Embedded log 01:48:33 UTC |
| Task branch pushed | Embedded log 01:48:36 UTC, before fail_command |
| Failure mutation | Wrapper subsequently invoked fail_command, then exited; mutation never published |

Job API started_at/completed_at values differ from timestamps embedded in the logs. Both originals are retained; clock alignment is not asserted.

Reservation, lease and execution identity are recorded in raw_evidence/task060_command_at_5eca940.json. An ACK demonstrates that the worker started; it does not demonstrate successful long execution or TASK_059 resumption.

