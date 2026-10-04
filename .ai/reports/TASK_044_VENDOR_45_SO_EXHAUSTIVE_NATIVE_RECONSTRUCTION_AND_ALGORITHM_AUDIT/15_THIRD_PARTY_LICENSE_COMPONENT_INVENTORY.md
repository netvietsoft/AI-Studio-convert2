# 15. THIRD-PARTY & OPEN SOURCE LICENSE COMPONENT INVENTORY

**Status**: AUDITED
**Scope**: Legal / License Compliance Audit of 45 Vendor Native Libraries

| Component | Contained in Library | Detected License | Upstream Origin | Clean-Room Strategy in CONVERT2 |
|---|---|---|---|---|
| FFmpeg | `libffmpeg.so`, `libffavc.so`, `libffmpegfilter.so` | LGPL v2.1+ / GPL v2+ | FFmpeg project | Replace with Android NDK MediaCodec Hardware API |
| FFTW3 | `libfftw3.so` | GPL v2+ | FFTW project | Replace with permissive KissFFT (BSD) or Vulkan FFT |
| LLVM libc++ | `libc++_shared.so` | Apache 2.0 with LLVM Exception | LLVM project | Standard Android NDK r28 toolchain runtime |
| libwebp | `libglide-webp.so` | BSD 3-Clause | Google WebP | Standard Android platform WebP support |
| ByteHook | `libbytehook.so` | MIT License | ByteDance open-source | Excluded (Not needed in clean-room engine) |
| KOOM | `libkoom-strip-dump.so` | Apache 2.0 | Kuaishou open-source | Excluded (Replaced with Android Studio Profiler) |
| HiAI DDK | `libhiai.so`, `libhiai_ir.so`, `libhiai_ir_build.so` | Proprietary Huawei DDK | Huawei Technologies | Replaced with cross-platform NCNN / NNAPI / Vulkan |
| Manis | `libManis.so`, `libmanis_npu_adapter.so` | Vendor Proprietary | Meitu / Tencent AI Lab | Replaced with Tencent NCNN open-source (BSD 3-Clause) |
| Color Transfer / Math | `libPVGColorFunctions.so` | Vendor Proprietary | Meitu / ArcSoft | Reconstructed clean-room in CONVERT2 `lib-core-graphics` |
| AR Kernel | `libarkernel3.so`, `libARKernelInterface.so` | Vendor Proprietary | Meitu AR Lab | Replaced with Google MediaPipe Face Mesh (Apache 2.0) |
