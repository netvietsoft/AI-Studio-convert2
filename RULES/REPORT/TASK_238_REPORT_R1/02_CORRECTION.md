# TASK_238 R1 report correction

The first sealed report incorrectly included seven TASK_236 accepted partial-research indices in the pending list and omitted older 450/499. This correction changes only task-owned report metadata and narrative. The 506 Ghidra raw rows, source assembly, command receipts, logs, code and scratch bytes retain their original hashes.

Current slice skipped: [3867, 3877, 4025, 4051, 4052, 4066].
Older assigned to ACTIVE TASK_239 and not accepted: [450, 499, 555, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523].
Accepted as partial static research by TASK_236: [1542, 1586, 1620, 1623, 1626, 1830, 1912].
Remaining pending: [450, 499, 555, 2293, 2775, 2776, 3106, 3132, 3134, 3285, 3523, 3867, 3877, 4025, 4051, 4052, 4066].

Raw rows 3588 and 3590 overlap another Ghidra function (12 and 92 bytes). They are unresolved source-function boundaries. There are 506 C-like raw outputs, 504 without this specific overlap, and zero independently decoded source functions or verified behaviors.
