// FUNCTION: native_native_getAudioBitrate
// LIBRARY: libaicodec.so
// RVA: 0x107b98 | SIZE: 168 bytes | SHA256: AB527466D20107342A0A566C8EC3A4653DAD5B90C8D380D2CEFAAFB9ADDBA25B
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getAudioBitrate, com_meitu_media_FlyMediaReader_getAudioBitrate

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getAudioBitrate(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107b98
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getAudioBitrate"
    // Literal reference: "com_meitu_media_FlyMediaReader_getAudioBitrate"
    return (void*)0;
}
