// FUNCTION: native_native_getVideoBitrate
// LIBRARY: libaicodec.so
// RVA: 0x107960 | SIZE: 168 bytes | SHA256: 745DAB67005483AEBEAC4FBF532803B2A89E6DBD9F1C635984C3792B918247B6
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getVideoBitrate, com_meitu_media_FlyMediaReader_getVideoBitrate

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getVideoBitrate(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107960
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoBitrate"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoBitrate"
    return (void*)0;
}
