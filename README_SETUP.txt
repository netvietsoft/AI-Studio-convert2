CONVERT2 EVENT BUS PACKAGE

Copy to repo:
- convert2-command-bus.yml -> .github/workflows/convert2-command-bus.yml
- run_agent_from_github_command.ps1 -> scripts/run_agent_from_github_command.ps1
- CONVERT2_EVENT_PROTOCOL.md -> docs/CONVERT2_EVENT_PROTOCOL.md

Then:
1. Register Windows self-hosted GitHub Actions runner.
2. Add label: convert2
3. Keep runner service online.
4. Create .ai/commands/NEXT_COMMAND.json using the sample from the protocol.
5. Create one persistent control PR.
6. Configure ChatGPT Work to trigger on PR activity containing CONVERT2_EVENT_V1.
7. Keep V3 watchdog only as fallback.

IMPORTANT:
The command JSON is only a wake-up signal.
Task Drive STATUS=ACTIVE remains the authorization source.
