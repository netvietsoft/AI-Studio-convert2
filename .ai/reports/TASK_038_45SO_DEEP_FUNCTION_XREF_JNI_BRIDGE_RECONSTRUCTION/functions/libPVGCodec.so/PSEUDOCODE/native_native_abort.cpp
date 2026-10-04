// FUNCTION: native_native_abort
// LIBRARY: libPVGCodec.so
// RVA: 0x12a87c | SIZE: 200 bytes | SHA256: 04DFB3F17B2929F2A799CDED2FA09027AF832F690D66AC7A0E15925B8B69DBF0
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN3PVG12PVGWaterMark5abortEv, pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz
// STRING_XREFS: PVGCodec, F[%s, L(%d)], T(%p):> get null native object, JNIPVGWaterMark_native_abort, %s/%s: F[%s, L(%d)], T(%p):> get null native object, PVGCodec, JNIPVGWaterMark_native_abort

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_abort(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x12a87c
    // Call imported API: _ZN3PVG12PVGWaterMark5abortEv
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "JNIPVGWaterMark_native_abort"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIPVGWaterMark_native_abort"
    return (void*)0;
}
