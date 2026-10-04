// FUNCTION: native_native_hasAudio
// LIBRARY: libaicodec.so
// RVA: 0x10725c | SIZE: 168 bytes | SHA256: BF818A85E9F42CE76FD47F421702BC7C10B4DB9019CE675B6E96D3A7DAEA4C1D
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_hasAudio, com_meitu_media_FlyMediaReader_hasAudio

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_hasAudio(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x10725c
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_hasAudio"
    // Literal reference: "com_meitu_media_FlyMediaReader_hasAudio"
    return (void*)0;
}
