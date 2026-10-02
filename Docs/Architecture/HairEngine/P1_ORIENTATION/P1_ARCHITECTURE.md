# P1 — Hair Orientation & Flow Field Architecture Specification
**Phase:** P1 (Hair Orientation & Flow Field)  
**Document:** `P1_ARCHITECTURE.md`  
**Governing Standard:** HCE_CONTRACT_V1 / Development Workspace Standard V2.1.2  
**Status:** PASS / ACTIVE  

## 1. Executive Architecture
Calculates smooth, continuous tangent vector fields over valid hair regions using structure tensor analysis.

## 2. Component Boundaries
- **Input:** Consumes contract from upstream (P0 Matte / Upstream HCE phases).
- **Processing:** Realized in native C++ (`libmeitu_reborn_native.so`) with OpenMP acceleration.
- **Output:** Encapsulated in `P1` contract struct within `meitu_native::hce`.
- **Invariants:** Zero non-hair leakage, thread-safe re-entrancy, deterministic output.
