// FUNCTION: native_native_checkIsSRGB
// LIBRARY: libPVGCodec.so
// RVA: 0x12610c | SIZE: 200 bytes | SHA256: 5BC2CEFBC11B15727A5C5F0FE602F9A2316CF2E05FCBEEC197BA096BAEB8089C
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN3PVG17PVGImageTranscode11checkIsSRGBEv, pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz
// STRING_XREFS: PVGCodec, F[%s, L(%d)], T(%p):> get null native object, JNIPVGImageTranscode_native_checkIsSRGB, %s/%s: F[%s, L(%d)], T(%p):> get null native object, PVGCodec, JNIPVGImageTranscode_native_checkIsSRGB

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_checkIsSRGB(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x12610c
    // Call imported API: _ZN3PVG17PVGImageTranscode11checkIsSRGBEv
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "JNIPVGImageTranscode_native_checkIsSRGB"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIPVGImageTranscode_native_checkIsSRGB"
    return (void*)0;
}
