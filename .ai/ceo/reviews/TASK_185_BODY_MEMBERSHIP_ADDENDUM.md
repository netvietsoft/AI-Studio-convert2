# TASK_185 independent body-membership addendum

After accepting TASK_185 fingerprint `87d7d8512f7731bfd196246a2b065bb71060c7af26e61c0db0a2203cf9f555dd`, CEO found that another worker's endpoint-only Ghidra body check could miss an interior hole. Without changing the immutable accepted review or TASK_185 evidence, CEO ran `.ai/ceo/reviews/ReviewBodyRanges.java` read-only over all 128 TASK_185 pinned targets on the separate byte-verified CEO Ghidra project. Command/log/output are in `.ai/ceo/reviews/TASK_185_CEO_REPLAY/body_ranges/` and `body_ranges.ndjson`; the project remained byte-identical before and after.

Full address-set membership plus `getNumAddresses()==FDE_size` confirms **90 exact and 38 nonexact** bodies, exactly matching the worker's reported counts. Thus the later-discovered endpoint-only blind spot does not alter the TASK_185 bounded static-research verdict. This addendum adds evidence only; no behavior, pixel, Phase PASS, V4 or all-45-SO assertion is made.
