# P6 — GPU Production Backend & Quality Tiers Algorithm Specification
**Document:** `P6_ALGORITHM_SPEC.md`  

## 1. Mathematical Formulation
Tier A (High-End GPU), Tier B (Mid-Range ROI), Tier C (CPU OpenMP fallback). Max abs diff = 0.000, 100% parity.

## 2. Boundary Condition Handling
- Zero alpha regions ($lpha < 0.05$): Output clamped to neutral zero.
- Translucent fringes ($0.05 \le lpha < 0.95$): Monotonic continuous blending.
- Core hair ($lpha \ge 0.95$): Full algorithm engagement.
