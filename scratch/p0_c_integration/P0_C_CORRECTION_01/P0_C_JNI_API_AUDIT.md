# PHASE P0-C CORRECTION — JNI API SAFETY & CONTRACT AUDIT
**Document ID:** `P0_C_JNI_API_AUDIT.md`  
**Phase:** Phase P0-C Corrective Audit & Remediation  
**Task ID:** TASK-P0C-F06  
**Owner:** Agent 0 — CEO / Orchestrator  
**Date:** 2026-10-02  
**Audit Scope:** Real Production JNI Surface in `lib-core-graphics` and `MeituNativeEngine.kt`  

---

## 1. EXECUTIVE AUDIT SUMMARY

An exhaustive line-by-line audit of all actual JNI symbols connecting Android Kotlin to the native C++ graphics core (`libcoregraphics.so`) was conducted. Prior reporting inaccuracies regarding non-existent class package prefixes (`com_meitu_library_graphics_HairMattingEngine`) have been eliminated; all verified JNI entry points reside under `com.meitu.core.nativeengine.MeituNativeEngine`.

| JNI Symbol / Function | Verification Dimension | Result | Status |
| :--- | :--- | :--- | :--- |
| `nativeInitHairMatting` | String Pin/Release & Model Initialization | Paired `ReleaseStringUTFChars` on all paths | **PASS** |
| `nativeSetP0B2REnabled` | Atomic Feature Flag Toggle | `std::atomic<bool>` memory safety | **PASS** |
| `nativeIsP0B2REnabled` | Atomic Feature Flag Query | Lock-free thread-safe query | **PASS** |
| `nativeExtractHairMatte` | Bitmap Lock/Unlock & Direct Alpha Extraction | `AndroidBitmap_unlockPixels` unconditional | **PASS** |
| `nativeApplyHairStrandDye` | Pipeline Integration & Shader Invocation | Zero-leak buffer lifecycle, Fused geometry | **PASS** |
| `nativeApplyCustomHairDye` | Custom Color & Bleaching Engine | Proper clamping and RAII buffers | **PASS** |
| `nativeDyeHair` | AI Hair Daub Legacy Pipeline | Memory pinned with explicit `JNI_ABORT` | **PASS** |
| `nativeApplyHair` | Classical Hair Region Tuning | Paired lock/unlock, zero dangling refs | **PASS** |

---

## 2. JNI SAFETY CHECKLIST (§12)

- [x] **JNI Signature Exact Match:** Verified against `javah`/`javac -h` naming convention for `com.meitu.core.nativeengine.MeituNativeEngine`.
- [x] **Native Registration / Export Exact:** Declared with `extern "C" JNIEXPORT ... JNICALL`.
- [x] **No Dangling Pointers:** All local buffers (`std::vector<float>`, `std::vector<uint8_t>`) are scoped to function execution and freed on return.
- [x] **Paired Pin and Release:** Every `GetStringUTFChars`, `GetByteArrayElements`, and `GetFloatArrayElements` is strictly paired with its corresponding `Release*`.
- [x] **Bitmap Lock/Unlock Pairing:** Every invocation of `AndroidBitmap_lockPixels` is unconditionally paired with `AndroidBitmap_unlockPixels` before return.
- [x] **No Return Path Skips Release:** All error branches release locks and references prior to returning error codes.
- [x] **Color Channel Byte Ordering:** Explicitly verified as `ANDROID_BITMAP_FORMAT_RGBA_8888` with explicit unpack macros `RGBA_R`, `RGBA_G`, `RGBA_B`, `RGBA_A`.
- [x] **Stride Handling:** Checked against `info.stride` and `info.width * 4`.
- [x] **Rotation / Orientation Contract:** Documented that input bitmap must be oriented upright before native submission (handled by camera/gallery EXIF pipeline).
- [x] **Null and Invalid Input Handling:** Null checks on bitmap, pointers, and dimensions ($W \le 0, H \le 0$) return controlled failure codes without SIGSEGV.
- [x] **No Stale Buffer Reuse:** Fresh allocation and deterministic deallocation on every inference pass.
- [x] **Feature Flag Thread Safety:** `sP0B2REnabled` is an atomic boolean (`std::atomic<bool>`).
- [x] **Re-entry / Lifecycle Behavior:** Stateless execution per frame invocation; safe across Activity `onPause`, `onResume`, and concurrent frame processing.

---

## 3. AUDIT CONCLUSION

The JNI interface surface for P0 Hair Matting in `lib-core-graphics` satisfies all memory safety, threading, lifecycle, and contract requirements without defect.
