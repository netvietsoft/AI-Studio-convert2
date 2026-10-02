# P6 — GPU Production Backend & Quality Tiers Architecture Specification
**Phase:** P6 (GPU Production Backend & Quality Tiers)  
**Document:** `P6_ARCHITECTURE.md`  
**Governing Standard:** HCE_CONTRACT_V1 / Development Workspace Standard V2.1.2  
**Status:** PASS / ACTIVE  

## 1. Executive Architecture
GPU compute abstraction supporting Vulkan and Metal with strict CPU reference parity.

## 2. Component Boundaries
- **Input:** Consumes contract from upstream (P0 Matte / Upstream HCE phases).
- **Processing:** Realized in native C++ (`libmeitu_reborn_native.so`) with OpenMP acceleration.
- **Output:** Encapsulated in `P6` contract struct within `meitu_native::hce`.
- **Invariants:** Zero non-hair leakage, thread-safe re-entrancy, deterministic output.
