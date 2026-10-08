# TASK_063 CEO arithmetic correction

This addendum corrects the numeric W3C counterexample in the immutable R1 CEO review and earlier advisory. The original review and snapshot remain unchanged for audit history. Its other NEEDS_FIX findings remain applicable to R1.

For A = 1/16 and B = 3/4, exact rational arithmetic gives D(A) = 53/256 = 0.20703125, W3C SoftLight = 69/512 = 0.134765625, and the recovered shader = 5/32 = 0.15625. Their difference is 11/512 = 0.021484375. The earlier CEO value 0.1328125 was incorrect. R2's value 0.134765625 is correct and is not a rejection finding.

Primary formula: [W3C Compositing and Blending, Soft Light](https://www.w3.org/TR/compositing-1/#blendingsoftlight). Exact execution result is retained in `.ai/ceo/receipts/TASK_063_softlight_exact_fraction_check.json`. The formulas still differ for this input. Keep the literal recovered piecewise formula; do not attach an unverified named equivalence.

Owner: Codex CEO; TASK_063 campaign; lease LEASE-CEO-SO45-20261008, fencing token 1007. This is a correction of CEO evidence, not AGY or product acceptance. Project memory follow-up is retained here because PROJECT_ERROR.md and ACQUIREMENTS.md are outside this CEO lease.
