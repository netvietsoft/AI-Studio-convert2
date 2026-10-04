# TASK_044 — THIRD-PARTY OPEN SOURCE COMPONENT & LICENSE INVENTORY

| Component | Detected In | Upstream License | Usage in Vendor Binary | CONVERT2 Clean-Room Strategy |
|---|---|---|---|---|
| **FFmpeg** | `libffmpeg.so`, `libffavc.so` | LGPL v2.1+ / GPL v2+ | Audio/video demuxing & decoding | Clean-room Android MediaCodec NDK / FFmpeg build |
| **libwebp** | `libglide-webp.so` | BSD 3-Clause | WebP image decoding | Standard Android BitmapFactory / NDK libwebp |
| **FFTW3** | `libfftw3.so` | GPL v2+ | Fast Fourier Transform DSP | ARM NEON FFT or OpenCV discrete Fourier |
| **ByteHook** | `libbytehook.so` | MIT License | ByteDance PLT hook utility | Not required in CONVERT2 production |
| **Koom** | `libkoom-strip-dump.so` | Apache 2.0 | Kuaishou memory leak dumper | Diagnostic tool only |
| **LLVM libc++** | `libc++_shared.so` | Apache 2.0 with LLVM Exception | C++ Standard Library runtime | Replaced by NDK libc++_shared.so |
| **Huawei HiAI** | `libhiai.so`, `libhiai_ir.so` | Proprietary Huawei SDK | NPU hardware acceleration | Fallback to NNAPI / Vulkan Compute |
