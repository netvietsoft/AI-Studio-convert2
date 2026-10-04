// FUNCTION: native_native_getOutDuration
// LIBRARY: libPVGCodec.so
// RVA: 0x11f440 | SIZE: 196 bytes | SHA256: 487829ACEC4829B9386B68889F1BAE1080F3B534F1F697EE32B3C2A6C3041966
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz
// STRING_XREFS: PVGCodec, F[%s, L(%d)], T(%p):> get null native object, JNIMediaCombiner_native_getOutDuration, %s/%s: F[%s, L(%d)], T(%p):> get null native object, PVGCodec, JNIMediaCombiner_native_getOutDuration

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getOutDuration(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x11f440
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "JNIMediaCombiner_native_getOutDuration"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIMediaCombiner_native_getOutDuration"
    return (void*)0;
}
