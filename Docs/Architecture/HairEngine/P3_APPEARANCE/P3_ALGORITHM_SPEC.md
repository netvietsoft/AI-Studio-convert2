# P3 — Appearance, Shadow & Highlight Preservation Algorithm Specification
**Document:** `P3_ALGORITHM_SPEC.md`  

## 1. Mathematical Formulation
Macro ambient luma estimation baseL. Crevice factor = (Y - floor)/(baseL*0.92). Highlight mask = (Y - baseL*1.15)/(255 - baseL*1.15).

## 2. Boundary Condition Handling
- Zero alpha regions ($lpha < 0.05$): Output clamped to neutral zero.
- Translucent fringes ($0.05 \le lpha < 0.95$): Monotonic continuous blending.
- Core hair ($lpha \ge 0.95$): Full algorithm engagement.
