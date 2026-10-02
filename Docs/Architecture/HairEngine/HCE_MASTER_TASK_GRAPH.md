# HAIR COLOR ENGINE (HCE) — MASTER TASK GRAPH
**Document:** `Docs/Architecture/HairEngine/HCE_MASTER_TASK_GRAPH.md`  
**Version:** 1.0.0  
**Authority:** Agent 0 (CEO / Orchestrator) — Phê chuẩn theo ủy quyền Chủ tịch Tony  
**Execution Model:** PARALLEL DEVELOPMENT — GATED INTEGRATION  
**Status:** ACTIVE  

---

## 1. Phả Hệ Phụ Thuộc (Top-Level Dependency Graph)

```
[ P0 HAIR MATTE — FROZEN (P0_FINAL_PASS_RECONFIRMED) ]
                           |
                           v  (START_DEPENDENCY)
             [ HCE-C0: SHARED CONTRACT FREEZE ]
                           |
        +------------------+------------------+
        | (CONTRACT_DEP)   | (CONTRACT_DEP)   | (CONTRACT_DEP)
        v                  v                  v
   [ P1 FLOW ]        [ P3 APPEARANCE ]  [ P6 GPU BASE ]
        |                  |                  |
        |                  |                  |
        +-----> [ P2 TEXTURE ]  +-----> [ P4 MATERIAL ]  |
        |             |               |       |
        |             +-------+-------+       |
        |                     |               |
        +--------------> [ P5 SPECULAR ] <----+
                              |
                              v  (MERGE_DEPENDENCY)
                   [ HCE-INTEGRATION WORKTREE ]
                              |
                              v  (ACCEPTANCE_DEPENDENCY)
                   [ HCE-E2E-TEST & REVIEW ]
                              |
                              v
                  [ HAIR COLOR V1 ACCEPTANCE ]
```

---

## 2. Ma Trận Phân Loại Phụ Thuộc (Dependency Matrix)

| Task ID | Task Name | START_DEP | CONTRACT_DEP | MERGE_DEP | ACCEPTANCE_DEP | Assigned Agent |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **HCE-C0-CONTRACT** | Shared Contract Freeze | P0_FROZEN | None | None | Architecture Audit | Agent_1 (Architect) |
| **HCE-P1-ARCH** | P1 Orientation Architecture | HCE-C0 | HCE_CONTRACT_V1 | None | P1 Spec Review | Agent_P1 |
| **HCE-P1-IMPL** | P1 Orientation C++ Core | HCE-P1-ARCH | P0 Adapter | None | Continuity & Flow Pass | Agent_P1 |
| **HCE-P1-TEST** | P1 Orientation Validation | HCE-P1-IMPL | Vector Field Spec | None | Continuous Pi-Periodic | Agent_Tester |
| **HCE-P2-ARCH** | P2 Flow-Aware Texture Arch | HCE-C0 | HCE_CONTRACT_V1 | None | Texture Spec Review | Agent_P2 |
| **HCE-P2-IMPL** | P2 Texture C++ Core | HCE-P2-ARCH | Mock Flow OK | HCE-P1-IMPL | Real P1 Flow Integration | Agent_P2 |
| **HCE-P2-TEST** | P2 Texture Validation | HCE-P2-IMPL | Texture Metric | None | Strand Preservation Pass | Agent_Tester |
| **HCE-P3-ARCH** | P3 Appearance Arch | HCE-C0 | HCE_CONTRACT_V1 | None | Lighting Spec Review | Agent_P3 |
| **HCE-P3-IMPL** | P3 Appearance C++ Core | HCE-P3-ARCH | P0 Alpha | None | Shadow/Highlight Separ. | Agent_P3 |
| **HCE-P3-TEST** | P3 Appearance Validation | HCE-P3-IMPL | Contrast Metric | None | Depth Preservation Pass | Agent_Tester |
| **HCE-P4-ARCH** | P4 Dye Material Arch | HCE-C0 | HCE_CONTRACT_V1 | None | Color Space Spec Review | Agent_P4 |
| **HCE-P4-IMPL** | P4 Dye Material C++ Core | HCE-P4-ARCH | Appearance Mock OK | HCE-P3-IMPL | Real P3 Appearance Integ| Agent_P4 |
| **HCE-P4-TEST** | P4 Dye Material Validation | HCE-P4-IMPL | Salon Palette | None | DeltaE & Gamut Pass | Agent_Tester |
| **HCE-P5-ARCH** | P5 Anisotropic Specular Arch | HCE-C0 | HCE_CONTRACT_V1 | None | Shading Spec Review | Agent_P5 |
| **HCE-P5-IMPL** | P5 Anisotropic C++ Core | HCE-P5-ARCH | Flow/Mat Mock OK | HCE-P1, P3, P4 | Real P1+P3+P4 Integ | Agent_P5 |
| **HCE-P5-TEST** | P5 Specular Validation | HCE-P5-IMPL | Specular Metric | None | Strand Alignment Pass | Agent_Tester |
| **HCE-P6-ARCH** | P6 GPU Vulkan/Metal Arch | HCE-C0 | HCE_CONTRACT_V1 | None | GPU Interface Review | Agent_P6 |
| **HCE-P6-IMPL** | P6 GPU Compute Kernels | HCE-P6-ARCH | Compute Shaders | HCE-P1..P5 | GPU Native Integration | Agent_P6 |
| **HCE-P6-BENCH** | P6 Parity & Benchmark | HCE-P6-IMPL | CPU Reference | None | Parity < 1e-3, FPS >= 30 | Agent_Tester |
| **HCE-INTEGRATION**| Cross-Phase Pipeline Assembly | HCE-P1..P6 IMPL| All Contracts | All Phases | Unified C++ Engine Bridge | Agent_Integ |
| **HCE-E2E-TEST** | End-to-End Validation Suite | HCE-INTEGRATION| Real Production | All Upstreams | 62 Ground Truth Samples | Agent_Tester |
| **HCE-VISUAL-REV** | Photographic Visual Audit | HCE-E2E-TEST | 14 Required Artifacts | None | 8-Point Gate (Zero Leak) | Agent_Reviewer |
| **HCE-PERF** | Thermal & Latency Profiling | HCE-INTEGRATION| Device SM-A075F | None | Cold/Warm/P95 Budget | Agent_Tester |
| **HCE-FINAL-REV** | Master Acceptance Review | All Gates Pass | All Evidence | All Manifests | Full Compliance Checklist | Agent_Reviewer |
| **HCE-FINAL-FREEZE**| Final Cryptographic Freeze | HCE-FINAL-REV | None | None | 100% Checksum Verification | Agent_0 (CEO) |

---

## 3. Quy Định Song Song Hóa (Parallel Concurrency Protocol)
1. **Giai đoạn Contract Freeze (HCE-C0):**
   - Agent 1 (Architect) chủ trì audit mã nguồn và freeze `HCE_CONTRACT_V1.md`.
   - Các implementation task ở trạng thái `READY_FOR_START` hoặc `READY_FOR_MOCK_START`.
2. **Giai đoạn Thực thi Song song (Phases P1–P6 Parallel):**
   - **Stream A (Hình học & Hướng):** Agent P1 thi công P1 Orientation -> Unblock real flow cho P2 Texture & P5 Specular.
   - **Stream B (Quang học & Màu sắc):** Agent P3 thi công P3 Appearance -> Unblock real appearance cho P4 Material & P5 Specular.
   - **Stream C (Hạ tầng GPU & Tăng tốc):** Agent P6 thi công khung Vulkan/Compute kernels độc lập trên mock buffers.
3. **Giai đoạn Hội tụ (Gated Integration):**
   - Chỉ Agent Integration mới được quyền lắp ráp pipeline tổng trong `hair-integration`.
   - Thay thế toàn bộ mock bằng real upstream: P2 nhận P1 thật; P4 nhận P3 thật; P5 nhận P1, P3, P4 thật; P6 nhận đồ thị hoàn chỉnh.
