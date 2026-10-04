// FUNCTION: native_native_finalize
// LIBRARY: libPVGCodec.so
// RVA: 0x1298cc | SIZE: 220 bytes | SHA256: FA69392986D4F1F7CC3BF3CCAB9D0F1514C4859FECC3425F929A38C5B1C4E8EF
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN3PVG12PVGWaterMarkD1Ev, _ZdlPv, pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz
// STRING_XREFS: PVGCodec, F[%s, L(%d)], T(%p):> get null native object, JNIPVGWaterMark_native_finalize, %s/%s: F[%s, L(%d)], T(%p):> get null native object, PVGCodec, JNIPVGWaterMark_native_finalize

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_finalize(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x1298cc
    // Call imported API: _ZN3PVG12PVGWaterMarkD1Ev
    // Call imported API: _ZdlPv
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "JNIPVGWaterMark_native_finalize"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIPVGWaterMark_native_finalize"
    return (void*)0;
}
