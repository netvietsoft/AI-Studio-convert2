// FUNCTION: native_native_getAudioDuration
// LIBRARY: libaicodec.so
// RVA: 0x10750c | SIZE: 176 bytes | SHA256: 166C3CE35A3706E19D3DF5AA85A20538B42120CB57448CF73BD0FACFBF37678A
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getAudioDuration, com_meitu_media_FlyMediaReader_getAudioDuration

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getAudioDuration(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x10750c
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getAudioDuration"
    // Literal reference: "com_meitu_media_FlyMediaReader_getAudioDuration"
    return (void*)0;
}
