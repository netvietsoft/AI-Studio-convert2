// FUNCTION: native_native_hasVideo
// LIBRARY: libaicodec.so
// RVA: 0x107304 | SIZE: 168 bytes | SHA256: 3C007E83F7C85F240F2BD0D1AE01E305F44BCEC4A15977917A4518B63386CE5A
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_hasVideo, com_meitu_media_FlyMediaReader_hasVideo

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_hasVideo(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107304
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_hasVideo"
    // Literal reference: "com_meitu_media_FlyMediaReader_hasVideo"
    return (void*)0;
}
