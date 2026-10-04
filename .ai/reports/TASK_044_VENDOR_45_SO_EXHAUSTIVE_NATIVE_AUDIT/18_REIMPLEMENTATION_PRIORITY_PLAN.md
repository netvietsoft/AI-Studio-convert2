# 18. CLEAN-ROOM REIMPLEMENTATION PRIORITY PLAN

**Status**: APPROVED ROADMAP FOR CONVERT2

To achieve 100% clean-room native independence without vendor binary dependencies, the 45 libraries are prioritized into four implementation tiers:

### Tier 1: Core Graphics, Color Transformations & Hair Engine (CRITICAL — ACTIVE IN CONVERT2)
- **Target Libraries**: `libPVGColorFunctions.so`, `libMTFilterKernel.so`, `libLayerFlow.so`, `libVERenderer.so`
- **CONVERT2 Module**: `lib-core-graphics`
- **Status**: Implemented clean-room in C++ Native Core with Vulkan compute acceleration. Verified on SM-A075F and SM-A507FN.

### Tier 2: Neural Network Inference & Face Tracking (HIGH — ACTIVE IN CONVERT2)
- **Target Libraries**: `libManis.so`, `libarkernel3.so`, `libarkernel3_android.so`, `libARKernelInterface.so`
- **CONVERT2 Module**: `lib-ai-engine`, `lib-photo-editor`
- **Status**: Replaced with NCNN BiSeNet P0 segmentation and MediaPipe Face Landmarker.

### Tier 3: Media Container & Audio/Video Codecs (NORMAL — PLANNED)
- **Target Libraries**: `libffmpeg.so`, `libffavc.so`, `libPVGCodec.so`, `libPVGVideoCodec.so`, `libKKMusicFX.so`
- **CONVERT2 Module**: `lib-video-engine`
- **Status**: Clean-room implementation using Android NDK MediaCodec Hardware APIs.

### Tier 4: Proprietary Diagnostics & Telemetry (DECOMMISSIONED)
- **Target Libraries**: `libkoom-strip-dump.so`, `libfntvcrash.so`, `libMTLReportTool.so`, `liblabdeviceinfo.so`, `libbytehook.so`, `libMtlabSign.so`, `libdexvmp.so`
- **Disposition**: Omitted from CONVERT2. Replaced with standard Android Jetpack telemetry and Android Studio Profiler.
