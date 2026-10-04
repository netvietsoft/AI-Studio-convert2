# 06. JNI BRIDGE PROVENANCE & VENDOR MAPPING AUDIT

## 1. Files Under Audit
- **V1 Candidate**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\src\jni_bridge.cpp` (159,018 bytes, ~4,200 lines)
- **CONVERT2 Current**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\cpp\src\jni_bridge.cpp` (169,051 bytes, 4,539 lines)

---

## 2. JNI Registration Mechanism & Class Target

Both V1 and CONVERT2 `jni_bridge.cpp` use direct JNI export naming:

```cpp
extern "C" {
JNIEXPORT <return_type> JNICALL
Java_com_meitu_core_nativeengine_MeituNativeEngine_<methodName>(JNIEnv* env, jclass clazz, ...)
```

### Analysis of Target Class:
- **Registered Class Path**: `com.meitu.core.nativeengine.MeituNativeEngine`
- **Kotlin/Java Declaration in CONVERT2**:
  `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\kotlin\com\meitu\core\nativeengine\MeituNativeEngine.kt`
- **Kotlin/Java Declaration in V1**:
  `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\java\com\meitu\core\nativeengine\MeituNativeEngine.kt`

---

## 3. Cross-Check with Decompiled Vendor APK (`jadx_src`)

A complete search across all 16 DEX directories in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src` proves:

1. **`com.meitu.core.nativeengine.MeituNativeEngine` DOES NOT EXIST in the original Meitu APK.**
2. The package `com.meitu.core.nativeengine` does not exist in vendor bytecode.
3. The original Meitu APK accessed native beauty and hair algorithms through completely different class interfaces:
   - **Hair Dye & Effects**:
     - `com.layer.flow.datas.LFEffectDenseHairData` -> `libLayerFlow.so`
     - `com.meitu.mfxkit.MTImitationMakeupTrack` -> `libmfxkit.so`
   - **Filter Kernels & Rendering**:
     - `com.meitu.core.MTFilterKernelRender` -> `libMTFilterKernel.so`
     - `com.meitu.core.types.NativeBitmap` -> `libMTFilterKernel.so`
   - **AR & Face Tracking**:
     - `com.meitu.arkernel.*` -> `libarkernel3.so` / `libARKernelInterface.so`
   - **AI Inference Runtime**:
     - `com.meitu.manis.*` -> `libManis.so`

---

## 4. Definitive Provenance Determination

1. **`jni_bridge.cpp` is a Project Reconstructed Facade**:
   It was engineered in CONVERT to provide a unified, clean C++ native API for Android UI components without requiring dozens of fragmented vendor classes.
2. **Method Names are Project Inventions**:
   Methods like `nativeDyeHair`, `nativeApply3DRelight`, `nativeSegmentHair`, `nativeLiquifyWarp` are project-defined signatures.
3. **Implications for TASK_038**:
   - `TASK_038` must **NOT** search the 45 vendor `.so` files for symbols named `Java_com_meitu_core_nativeengine_MeituNativeEngine_*`. They will never be found.
   - `TASK_038` must reverse the vendor binaries (`libLayerFlow.so`, `libMTFilterKernel.so`, etc.) based on their **actual exported symbols** and `jadx_src` JNI bindings.
   - `jni_bridge.cpp` serves as the target **adapter specification** for how reconstructed C++ connects to our Android app, not as vendor ground truth.
