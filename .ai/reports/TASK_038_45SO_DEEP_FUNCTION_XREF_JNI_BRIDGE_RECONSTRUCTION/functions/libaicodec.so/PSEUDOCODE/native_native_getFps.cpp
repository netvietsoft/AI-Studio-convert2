// FUNCTION: native_native_getFps
// LIBRARY: libaicodec.so
// RVA: 0x10770c | SIZE: 176 bytes | SHA256: 679690FE301B47DA2D53A28A336FA2EA67D9AC88BE328E744CBF97811B74AC0D
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getFps, com_meitu_media_FlyMediaReader_getFps

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getFps(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x10770c
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getFps"
    // Literal reference: "com_meitu_media_FlyMediaReader_getFps"
    return (void*)0;
}
