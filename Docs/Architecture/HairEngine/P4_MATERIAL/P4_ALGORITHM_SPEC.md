# P4 — Hair Dye Material & Color Response Algorithm Specification
**Document:** `P4_ALGORITHM_SPEC.md`  

## 1. Mathematical Formulation
sRGB -> Linear -> LMS -> OKLab. Melanin lift = (targetL - origL)*bleach*creviceDepth. Chromatic blend = mix(orig, target, intensity*creviceDepth).

## 2. Boundary Condition Handling
- Zero alpha regions ($lpha < 0.05$): Output clamped to neutral zero.
- Translucent fringes ($0.05 \le lpha < 0.95$): Monotonic continuous blending.
- Core hair ($lpha \ge 0.95$): Full algorithm engagement.
