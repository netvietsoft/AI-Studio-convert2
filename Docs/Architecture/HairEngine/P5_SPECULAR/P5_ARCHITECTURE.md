# P5 — Anisotropic Specular & Strand Reflection Architecture Specification
**Phase:** P5 (Anisotropic Specular & Strand Reflection)  
**Document:** `P5_ARCHITECTURE.md`  
**Governing Standard:** HCE_CONTRACT_V1 / Development Workspace Standard V2.1.2  
**Status:** PASS / ACTIVE  

## 1. Executive Architecture
Applies Marschner R-lobe directional glint along hair strands anchored to physical scene highlights.

## 2. Component Boundaries
- **Input:** Consumes contract from upstream (P0 Matte / Upstream HCE phases).
- **Processing:** Realized in native C++ (`libmeitu_reborn_native.so`) with OpenMP acceleration.
- **Output:** Encapsulated in `P5` contract struct within `meitu_native::hce`.
- **Invariants:** Zero non-hair leakage, thread-safe re-entrancy, deterministic output.
