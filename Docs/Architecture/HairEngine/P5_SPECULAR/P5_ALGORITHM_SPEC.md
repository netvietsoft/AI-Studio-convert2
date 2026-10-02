# P5 — Anisotropic Specular & Strand Reflection Algorithm Specification
**Document:** `P5_ALGORITHM_SPEC.md`  

## 1. Mathematical Formulation
Glint = apparentShine * highlightMask * (0.65 + 0.35*confidence). Dielectric white reflection mixed with dye tint. Zero glint in deep crevices.

## 2. Boundary Condition Handling
- Zero alpha regions ($lpha < 0.05$): Output clamped to neutral zero.
- Translucent fringes ($0.05 \le lpha < 0.95$): Monotonic continuous blending.
- Core hair ($lpha \ge 0.95$): Full algorithm engagement.
