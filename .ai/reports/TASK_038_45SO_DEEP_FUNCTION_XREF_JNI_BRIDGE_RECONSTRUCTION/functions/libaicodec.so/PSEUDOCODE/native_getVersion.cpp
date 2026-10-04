// FUNCTION: native_getVersion
// LIBRARY: libaicodec.so
// RVA: 0x105e44 | SIZE: 452 bytes | SHA256: A74EAA3D1F13DB81753C94F41B3BEF2F22DE0987F44274633916B069DA525FE4
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN7MMCodec10JniUtility12getJavaClassEPKc, __android_log_print, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: <init>, (IIII)V, [%s(%d)]:> Couldn't find class %s, com_meitu_media_aicodec_AICodec_getVersion, com_meitu_media_aicodec_AICodec_getVersion, [%s(%d)]:> Couldn't find class %s constructor, com_meitu_media_aicodec_AICodec_getVersion, com_meitu_media_aicodec_AICodec_getVersion

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_getVersion(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x105e44
    // Call imported API: _ZN7MMCodec10JniUtility12getJavaClassEPKc
    // Call imported API: __android_log_print
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "<init>"
    // Literal reference: "(IIII)V"
    // Literal reference: "[%s(%d)]:> Couldn't find class %s"
    // Literal reference: "com_meitu_media_aicodec_AICodec_getVersion"
    // Literal reference: "com_meitu_media_aicodec_AICodec_getVersion"
    // Literal reference: "[%s(%d)]:> Couldn't find class %s constructor"
    // Literal reference: "com_meitu_media_aicodec_AICodec_getVersion"
    // Literal reference: "com_meitu_media_aicodec_AICodec_getVersion"
    return (void*)0;
}
