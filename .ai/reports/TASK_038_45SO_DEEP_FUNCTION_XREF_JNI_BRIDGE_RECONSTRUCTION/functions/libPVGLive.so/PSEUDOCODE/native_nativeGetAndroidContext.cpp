// FUNCTION: native_nativeGetAndroidContext
// LIBRARY: libPVGLive.so
// RVA: 0x8a414 | SIZE: 88 bytes | SHA256: 14DBCF480587245BC2D0E1927513D4960A07BA47E653739E25F07AE9AA94A267
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN7PVGLIVE9PVGGlobal11getInstanceEv, _ZN7PVGLIVE9PVGGlobal17getAndroidContextEv, _ZN7PVGLIVE9PVGGlobal21releaseAndroidContextEv
// STRING_XREFS: None

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_nativeGetAndroidContext(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x8a414
    // Call imported API: _ZN7PVGLIVE9PVGGlobal11getInstanceEv
    // Call imported API: _ZN7PVGLIVE9PVGGlobal17getAndroidContextEv
    // Call imported API: _ZN7PVGLIVE9PVGGlobal21releaseAndroidContextEv
    return (void*)0;
}
