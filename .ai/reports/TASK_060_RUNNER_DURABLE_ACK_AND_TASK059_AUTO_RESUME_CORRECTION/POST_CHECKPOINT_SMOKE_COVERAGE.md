# Post-checkpoint smoke-script coverage

This addendum and its log were created after the 28-entry checkpoint archive was frozen. They are not part of that archive or FREEZE.sha256. The canonical ZIP and its verified Drive bytes remain unchanged.

The suspected joined invocation/exit-code assignment was a display artifact. Raw bytes and PowerShell AST show separate statements in both baseline5eca940 and the corrected wrapper. No production defect was reproduced and no production code changed.

Two new regressions exercise command-specified native PowerShell scripts through actual local bare Git and Windows PowerShell. Exit9 publishes canonical FAILED, retains exact command/task binding and skips integration. Exit0 requests only a local MOCK gh integrator and leaves canonical RUNNING; it does not assert real integration or completion.

Root independently ran both new test methods: 2/2 passed in32.401 seconds, native exit0. Actual output is post_checkpoint_smoke_tests.log. Implementing agent also ran the entire affected wrapper suite: 9/9 passed in139.159 seconds. Combined with the earlier 39 non-wrapper tests, 48 unique local cases are covered across the recorded runs; no new combined48 run is claimed.

Reviewer /root/workspace_preflight independently approved the coverage additions, compilation and scoped whitespace checks. Production wrapper SHA256 remains D1392124328B6889F4E299921AFF99762D4045499749A9E9E2FF0272C1F15AA6; orchestrator FB90FC6F68BFF71ED85C7BB991D67FB7F3B9FC48527A7E870C0A5F9527D6C27C. Updated wrapper test hash is17447404A502687850D677BFE453CA5E16A90EB3F917CD4CF6054E8C9C94A647.

Runtime upstream is explicitly MOCK. No authenticated service smoke, live Actions dispatch, TASK_059 resume or TASK_060 acceptance is established. Approved setup location remains pending.

Log SHA256: 3688707ef3eb8deb3cd16f7db5ab2b516fb6845f6c75adf45ac2e496031351dd
