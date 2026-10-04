// FUNCTION: native_native_getVideoDuration
// LIBRARY: libaicodec.so
// RVA: 0x10745c | SIZE: 176 bytes | SHA256: 951FE72B3B018F776AEB2840511608888A4CEA3BE68BF38C59B93667EC43E5C1
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getVideoDuration, com_meitu_media_FlyMediaReader_getVideoDuration

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getVideoDuration(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x10745c
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoDuration"
    // Literal reference: "com_meitu_media_FlyMediaReader_getVideoDuration"
    return (void*)0;
}
