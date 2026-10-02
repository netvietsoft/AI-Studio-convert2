# P4 — Hair Dye Material & Color Response Architecture Specification
**Phase:** P4 (Hair Dye Material & Color Response)  
**Document:** `P4_ARCHITECTURE.md`  
**Governing Standard:** HCE_CONTRACT_V1 / Development Workspace Standard V2.1.2  
**Status:** PASS / ACTIVE  

## 1. Executive Architecture
Perceptual dye color transformation in OKLab color space preserving shadow depth and melanin lifting.

## 2. Component Boundaries
- **Input:** Consumes contract from upstream (P0 Matte / Upstream HCE phases).
- **Processing:** Realized in native C++ (`libmeitu_reborn_native.so`) with OpenMP acceleration.
- **Output:** Encapsulated in `P4` contract struct within `meitu_native::hce`.
- **Invariants:** Zero non-hair leakage, thread-safe re-entrancy, deterministic output.
