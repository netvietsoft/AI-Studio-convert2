// FUNCTION: native_native_getAudioSampleRate
// LIBRARY: libaicodec.so
// RVA: 0x107c40 | SIZE: 168 bytes | SHA256: 4CDAC8FF49F002898FEEFDEED96236D6F061A7E5AEB7304277A3BC009F2F1187
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getAudioSampleRate, com_meitu_media_FlyMediaReader_getAudioSampleRate

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getAudioSampleRate(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107c40
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getAudioSampleRate"
    // Literal reference: "com_meitu_media_FlyMediaReader_getAudioSampleRate"
    return (void*)0;
}
