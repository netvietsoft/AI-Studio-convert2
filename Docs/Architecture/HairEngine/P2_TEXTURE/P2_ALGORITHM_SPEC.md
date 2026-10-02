# P2 — Flow-Aware Hair Texture Algorithm Specification
**Document:** `P2_ALGORITHM_SPEC.md`  

## 1. Mathematical Formulation
Frequency separation L = LowFreq + HighFreq. Directional ridge filtering across flow normal: ridge = 2*center - (valP + valM).

## 2. Boundary Condition Handling
- Zero alpha regions ($lpha < 0.05$): Output clamped to neutral zero.
- Translucent fringes ($0.05 \le lpha < 0.95$): Monotonic continuous blending.
- Core hair ($lpha \ge 0.95$): Full algorithm engagement.
