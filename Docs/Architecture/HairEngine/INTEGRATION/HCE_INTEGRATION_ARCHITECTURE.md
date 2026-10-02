# Hair Color Engine — Unified Integration Architecture
**Document:** `HCE_INTEGRATION_ARCHITECTURE.md`  
**Status:** PASS / PRODUCTION-INTEGRATED  

## 1. Unified Pipeline Order
P0 (Frozen Matte) -> P1 (Orientation) -> P2 (Texture) -> P3 (Appearance) -> P4 (Material) -> P5 (Specular) -> P6 (GPU Backend).

## 2. Zero-Leakage Invariant
100% non-hair protection: skin, face, eyes, ears, clothes, and UI toolbars receive 0.000% modification.
