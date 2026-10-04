# 07. RECOMMENDED NEXT SOURCE TO ANALYZE

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_CLASSIFICATION_ACTIVE`  
**Command ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_20261004T103500+0700`  
**Authoritative Scan Root**: `F:\CONVERT`  

---

## 1. Prioritized Roadmap for Downstream Tasks

Based on the empirical classification of all 20 candidate directories across `F:\CONVERT`, distinct source directories are recommended for subsequent engineering tracks:

```
                    ┌──────────────────────────────────────────────┐
                    │       TASK_039 DISCOVERY CENSUS             │
                    └──────────────────────┬───────────────────────┘
                                           │
           ┌───────────────────────────────┴──────────────────────────────┐
           ▼                                                              ▼
┌─────────────────────────────────────┐        ┌──────────────────────────────────────┐
│ TRACK 1: VENDOR NATIVE FORENSICS    │        │ TRACK 2: FUTURE FEATURE EXPANSION   │
│ (TASK_038 / TASK_045 Pipeline)      │        │ (Post-Hair V2 / Phase P7+)           │
├─────────────────────────────────────┤        ├──────────────────────────────────────┤
│ Target: com.mt.mtxx.mtxx\SOURCE     │        │ Target: com.mt.mtxx.mtxx\CONVERT     │
│ Subtrees:                           │        │ Subtrees:                            │
│  - extracted_native_libs/ (45 .so)  │        │  - apps/android/feature/ (19 mods)   │
│  - jadx_src/ (Decompiled Bytecode)  │        │  - native-bridge/src/ (Cloth/Video)  │
│  - apktool_out/ (Shader Binaries)   │        │  - prototype/ (Web Experience)       │
└─────────────────────────────────────┘        └──────────────────────────────────────┘
```

---

## 2. Immediate Priority: TASK_038 (Vendor 45 .so JNI Reconstruction)

### Primary Target Directory:
**`F:\CONVERT\com.mt.mtxx.mtxx\SOURCE`**

#### Key Subtrees & Required Intake:
1. **`F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs`**:
   - Contains all **45 vendor ARM64 shared libraries**.
   - Immediate intake target for IDA / Ghidra / `readelf` / `objdump` deep disassembly, symbol resolution, and function xref mapping.
   - Core libraries for Hair: `libhair_segment.so`, `libmatting.so`, `libface_parsing.so`, `libbisenet.so`.
2. **`F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src`**:
   - Contains 106,466 decompiled Java classes.
   - Authoritative source for identifying `System.loadLibrary(...)` calls, native method signatures, and JNI class bindings (`MTSoftHairFilter`, `HairMaskFilterToFBO`, `MakeupHairSoftPart`).

#### Why NOT `CONVERT\apps\android\core\native-bridge` for TASK_038?
As formally audited and corrected in TASK_041:
- `CONVERT\apps\android\core\native-bridge` is **synthetic reconstructed C++ code** authored by the project team.
- Its JNI bridge (`jni_bridge.cpp`) binds to `MeituNativeEngine`, an artificial facade that does not exist in the vendor APK.
- Using V1 native bridge as vendor ground truth for TASK_038 would lead to false assumptions and architectural deviations.

---

## 3. Secondary Priority: Post-Hair / Phase P7 Feature Intake

### Primary Target Directory:
**`F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android`**

When the project advances beyond the Phase P1-P6 Hair Color Engine into full-app Meitu Reborn capabilities, this V1 workspace provides ready-to-integrate source modules:

1. **Android Feature Modules (19 Modules)**:
   - `feature:community`: Complete social network feed, search, and publication UI wired to Ktor backend.
   - `feature:idphoto`: Professional ID portrait generation, background removal, and formal suit overlay.
   - `feature:puzzle`: Photo collages and multi-image puzzle grids.
   - `feature:livephoto`: Live motion photo capture and playback.
   - `feature:videoedit`: Multi-track video timeline and clip transitions.
2. **Specialized Native C++ Engines (21 Files Missing from CONVERT2)**:
   - `full_body_beauty_engine.cpp`: Full-body proportions and slimming.
   - `media/cloth/pbd_cloth_simulator.cpp`: Position Based Dynamics cloth simulation for virtual try-on.
   - `media/cloth/virtual_tryon_engine.cpp`: Clothing transfer and mesh deformation.
   - `media/video/video_timeline_compositor.cpp`: NDK-based high-performance video compositor.

---

## 4. Summary Table of Next Steps

| Task / Objective | Authoritative Directory to Analyze | Action | Gate / Constraint |
|---|---|---|---|
| **TASK_038** (JNI Bridge Recon) | `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE` | Decompile & map 45 vendor .so exports to Java JNI tables. | **MANDATORY**: Must use genuine vendor binaries, not V1 synthetic code. |
| **Full-Body Expansion** | `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` | Extract `full_body_beauty_engine.cpp` into CONVERT2. | Requires explicit ACTIVE task authorization from Tony. |
| **Virtual Try-On / Cloth** | `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` | Port `pbd_cloth_simulator.cpp` into CONVERT2. | Requires explicit ACTIVE task authorization from Tony. |
| **Material Pack Migration** | `F:\CONVERT\Material Image Editor` | Import 12 category material packs (2014-5002) into CONVERT2 assets. | Asset validation & licensing verification required. |
