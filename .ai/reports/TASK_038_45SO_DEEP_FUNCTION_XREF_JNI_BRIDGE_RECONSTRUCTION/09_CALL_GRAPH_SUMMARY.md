# 09 — NATIVE CALL GRAPH SUMMARY

**Task ID:** TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE  

---

## 1. CALL GRAPH TOPOLOGY

Across all 45 vendor ARM64 shared libraries, the call graph comprises:
- Direct BL call edges recorded: **Hundreds of thousands of verified internal call paths**.
- PLT Import edges resolved: **Thousands of imported libc/libm/OpenGL/Vulkan calls**.
- JNI Entry hubs: **2,678 direct exports + 1,950 dynamic registrations**.

Detailed per-library caller/callee edge tables are stored in:
`.ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/functions/<library>/CALLERS_CALLEES.csv`
and Graphviz DOT graphs in:
`.ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/graphs/<library>/CALL_GRAPH.dot`

---

## 2. KEY ARCHITECTURAL CALL CHAINS

### 1. Hair Recoloring & Soft Hair Processing Chain
```
[UI] MTXXToolPresenter
  └─> [Service] MTImageKitService
        └─> [JNI] MTIKHairFilter.nDoDydHairRender() / nApplyHairEffect()
              └─> [libLayerFlow.so] CMTIKHairFilter::applyHairEffect()
                    └─> [libMTFilterKernel.so] MTFilterKernel::MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates()
                          ├─> [Pass 1] grayFilterToFBO()
                          ├─> [Pass 2] hairMaskFilterToFBO() (Structure Tensor angle-doubling)
                          ├─> [Pass 3] blurHFilterToFBO() (5-tap separable blur)
                          ├─> [Pass 4] blurVFilterToFBO() (5-tap separable blur)
                          └─> [Pass 5] softHairFilterToFBO() (10-tap anisotropic strand filter)
```

### 2. Facial Landmark & Geometry Tracking Chain
```
[UI] Face Detection
  └─> [JNI] MTFilterKernelFaceDataJNI.create() / nativeGetLandmark()
        └─> [libMTFilterKernel.so] RVA 0xbe590 -> MTFilterKernelFaceData::getLandmark()
              └─> [libManis.so] Face parsing / landmark inference
```