# P1 — Hair Orientation & Flow Field Algorithm Specification
**Document:** `P1_ALGORITHM_SPEC.md`  

## 1. Mathematical Formulation
Structure tensor J = [[Ix^2, IxIy], [IxIy, Iy^2]] with Gaussian smoothing. Doubled-angle vector (vx, vy) where vx = -diff/num, vy = -2*jxy/num.

## 2. Boundary Condition Handling
- Zero alpha regions ($lpha < 0.05$): Output clamped to neutral zero.
- Translucent fringes ($0.05 \le lpha < 0.95$): Monotonic continuous blending.
- Core hair ($lpha \ge 0.95$): Full algorithm engagement.
