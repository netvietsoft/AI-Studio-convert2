// FUNCTION: native_getVersion
// LIBRARY: libMTLReportTool.so
// RVA: 0xb9a0 | SIZE: 260 bytes | SHA256: B40E3477884ABA7467F572A9DB73E15FD6BAF45867EB56327E32AA1B46F210AF
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN13VLLogMediator11getInstanceEv, _ZN13VLLogMediator15getVllogVersionEv, __android_log_print, __cxa_begin_catch, __android_log_print, __cxa_end_catch, __cxa_end_catch
// STRING_XREFS: vllogmediatorLog-JNI, VLLog version: %s, vllogmediatorLog-JNI, vllogGetVersion failed: %s, java/lang/RuntimeException

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_getVersion(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0xb9a0
    // Call imported API: _ZN13VLLogMediator11getInstanceEv
    // Call imported API: _ZN13VLLogMediator15getVllogVersionEv
    // Call imported API: __android_log_print
    // Call imported API: __cxa_begin_catch
    // Call imported API: __android_log_print
    // Call imported API: __cxa_end_catch
    // Call imported API: __cxa_end_catch
    // Literal reference: "vllogmediatorLog-JNI"
    // Literal reference: "VLLog version: %s"
    // Literal reference: "vllogmediatorLog-JNI"
    // Literal reference: "vllogGetVersion failed: %s"
    // Literal reference: "java/lang/RuntimeException"
    return (void*)0;
}
