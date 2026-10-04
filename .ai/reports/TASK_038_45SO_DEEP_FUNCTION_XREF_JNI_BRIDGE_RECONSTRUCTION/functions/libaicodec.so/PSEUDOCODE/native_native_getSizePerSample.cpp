// FUNCTION: native_native_getSizePerSample
// LIBRARY: libaicodec.so
// RVA: 0x107ce8 | SIZE: 180 bytes | SHA256: 34B300CEF5122AECB7279C5EE8B7412649E3C59FAF42B97706EEB5395BCD82E8
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE, av_get_bytes_per_sample, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getSizePerSample, com_meitu_media_FlyMediaReader_getSizePerSample

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getSizePerSample(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x107ce8
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE
    // Call imported API: av_get_bytes_per_sample
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getSizePerSample"
    // Literal reference: "com_meitu_media_FlyMediaReader_getSizePerSample"
    return (void*)0;
}
