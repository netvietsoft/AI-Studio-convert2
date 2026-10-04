// FUNCTION: native_native_setListener
// LIBRARY: libPVGCodec.so
// RVA: 0x1299a8 | SIZE: 520 bytes | SHA256: B3FBA59C2062D9ACCB97EF7F1B6DA92DADD47E06A8EDFC420660B0BEF0D02F13
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _Znwm, _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG6PVGRef7releaseEv, pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG6PVGRef7releaseEv, pthread_self, __android_log_print, pthread_self, _ZN3PVG19logCallbackInternalEiPKcz, _ZdlPv
// STRING_XREFS: PVGCodec, F[%s, L(%d)], T(%p):> get null native object, JNIPVGWaterMark_native_setListener, %s/%s: F[%s, L(%d)], T(%p):> get null native object, PVGCodec, JNIPVGWaterMark_native_setListener, PVGCodec, F[%s, L(%d)], T(%p):> listener setObj failed, JNIPVGWaterMark_native_setListener, %s/%s: F[%s, L(%d)], T(%p):> listener setObj failed, PVGCodec, JNIPVGWaterMark_native_setListener

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_setListener(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x1299a8
    // Call imported API: _Znwm
    // Call imported API: _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE
    // Call imported API: _ZN3PVG6PVGRef7releaseEv
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Call imported API: _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE
    // Call imported API: _ZN3PVG6PVGRef7releaseEv
    // Call imported API: pthread_self
    // Call imported API: __android_log_print
    // Call imported API: pthread_self
    // Call imported API: _ZN3PVG19logCallbackInternalEiPKcz
    // Call imported API: _ZdlPv
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "JNIPVGWaterMark_native_setListener"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIPVGWaterMark_native_setListener"
    // Literal reference: "PVGCodec"
    // Literal reference: "F[%s, L(%d)], T(%p):> listener setObj failed"
    // Literal reference: "JNIPVGWaterMark_native_setListener"
    // Literal reference: "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
    // Literal reference: "PVGCodec"
    // Literal reference: "JNIPVGWaterMark_native_setListener"
    return (void*)0;
}
