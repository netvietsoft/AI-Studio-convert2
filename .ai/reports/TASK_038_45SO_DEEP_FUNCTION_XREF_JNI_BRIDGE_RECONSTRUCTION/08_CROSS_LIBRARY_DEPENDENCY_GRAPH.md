# 08 — CROSS-LIBRARY DEPENDENCY GRAPH

**Task ID:** TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE  

---

## 1. ARCHITECTURAL SUBSYSTEMS & CLUSTERS

The 45 vendor ARM64 shared libraries form 5 tightly coupled functional clusters:

```mermaid
graph TD
    subgraph UI_AND_FRAMEWORK["UI & ImageKit Framework"]
        LF[libLayerFlow.so]
        AR3[libarkernel3.so]
        ARI[libARKernelInterface.so]
        AR3A[libarkernel3_android.so]
        AR3C[libarkernel3_c.so]
        ARSPM[libARSPM.so]
    end

    subgraph CORE_GRAPHICS_FILTERS["Core Filter & Graphics Engine"]
        FK[libMTFilterKernel.so]
        VER[libVERenderer.so]
        BMP[libbmpKit.so]
        GIF[libMTGif.so]
    end

    subgraph AI_AND_VISION["Neural AI & Computer Vision"]
        MANIS[libManis.so]
        NPU[libmanis_npu_adapter.so]
        AIMODEL[libAIModelKit.so]
        AISEARCH[libAIModelSearchKit.so]
        AIDET[libaidetectionplugin.so]
        HIAI[libhiai.so]
        HIAI_IR[libhiai_ir.so]
    end

    subgraph MEDIA_CODECS["Media Codecs & Color Management"]
        FFMPEG[libffmpeg.so]
        AICODEC[libaicodec.so]
        PVGC[libPVGCodec.so]
        PVGI[libPVGImageCodec.so]
        PVGV[libPVGVideoCodec.so]
        PVGL[libPVGLive.so]
        PVGCLR[libPVGColorFunctions.so]
    end

    subgraph RUNTIME_SYSTEM["Runtime & Security"]
        CPP[libc++_shared.so]
        BYTE[libbytehook.so]
        DEXVMP[libdexvmp.so]
        KOOM[libkoom-strip-dump.so]
        SIGN[libMtlabSign.so]
    end

    LF --> ARI
    LF --> MANIS
    LF --> PVGCLR
    ARI --> AR3
    AR3 --> FK
    AR3 --> MANIS
    FK --> PVGCLR
    MANIS --> NPU
    AIMODEL --> MANIS
    FFMPEG --> AICODEC
    PVGI --> PVGC
    LF --> CPP
    FK --> CPP
    AR3 --> CPP
```

---

## 2. CENTRAL HUBS & FAN-IN ANALYSIS
- **`libc++_shared.so`**: Fan-in = 44 (Used by all C++ libraries for STL, exceptions, and memory).
- **`libManis.so`**: Central Neural Inference Engine. Consumed by `libLayerFlow.so`, `libARKernelInterface.so`, `libarkernel3.so`, and `libAIModelKit.so`.
- **`libMTFilterKernel.so`**: Core GPU Image Filter & Soft Hair engine. Consumed by `libarkernel3.so` and `libLayerFlow.so`.
- **`libPVGColorFunctions.so`**: Color space transformation and Display P3 / sRGB transcode hub.