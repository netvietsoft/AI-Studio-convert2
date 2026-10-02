# P3 — Appearance, Shadow & Highlight Preservation Architecture Specification
**Phase:** P3 (Appearance, Shadow & Highlight Preservation)  
**Document:** `P3_ARCHITECTURE.md`  
**Governing Standard:** HCE_CONTRACT_V1 / Development Workspace Standard V2.1.2  
**Status:** PASS / ACTIVE  

## 1. Executive Architecture
Decomposes illumination to preserve deep curl shadows and natural specular highlights.

## 2. Component Boundaries
- **Input:** Consumes contract from upstream (P0 Matte / Upstream HCE phases).
- **Processing:** Realized in native C++ (`libmeitu_reborn_native.so`) with OpenMP acceleration.
- **Output:** Encapsulated in `P3` contract struct within `meitu_native::hce`.
- **Invariants:** Zero non-hair leakage, thread-safe re-entrancy, deterministic output.
