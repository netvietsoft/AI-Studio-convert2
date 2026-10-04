// FUNCTION: native_native_checkIsHDR
// LIBRARY: libPVGCodec.so
// RVA: 0x1261d4 | SIZE: 200 bytes | SHA256: 9618E68E57A8DECCDA776922FEF3ED469F078FA98BEFC6ECBF6F0AA847F83618
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN3PVG17PVGImageTranscode10checkIsHDREv, pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz
// STRING_XREFS: PVGCodec, F[%s, L(%d)], T(%p):> get null native object, JNIPVGImageTranscode_native_checkIsHDR, %s/%s: F[%s, L(%d)], T(%p):> get null native object, PVGCodec, JNIPVGImageTranscode_native_checkIsHDR

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_checkIsHDR(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x1261d4
    // Call imported API: _ZN3PVG17PVGImageTranscode10checkIsHDREv
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "JNIPVGImageTranscode_native_checkIsHDR"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIPVGImageTranscode_native_checkIsHDR"
    return (void*)0;
}
