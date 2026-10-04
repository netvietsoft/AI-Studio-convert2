// FUNCTION: native_native_getFramesNumber
// LIBRARY: libaicodec.so
// RVA: 0x107a08 | SIZE: 168 bytes | SHA256: 75BBDC4B0DB7E10237D55D7C8840E9214B8AA829F14F6DB759D781C29B59EBEF
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getFramesNumber, com_meitu_media_FlyMediaReader_getFramesNumber

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getFramesNumber(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107a08
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getFramesNumber"
    // Literal reference: "com_meitu_media_FlyMediaReader_getFramesNumber"
    return (void*)0;
}
