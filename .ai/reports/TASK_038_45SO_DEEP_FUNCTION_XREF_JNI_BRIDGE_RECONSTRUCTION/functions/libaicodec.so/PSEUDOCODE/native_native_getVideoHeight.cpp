// FUNCTION: native_native_getVideoHeight
// LIBRARY: libaicodec.so
// RVA: 0x107664 | SIZE: 168 bytes | SHA256: EE0C2D7A1550BD904C4D07BE7DA8FE160E7B47ECFEC3AA0239FC9A0AFBA3C74F
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getVideoHeight, com_meitu_media_FlyMediaReader_getVideoHeight

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getVideoHeight(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107664
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoHeight"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoHeight"
    return (void*)0;
}
