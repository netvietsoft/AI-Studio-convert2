// FUNCTION: native_native_getDuration
// LIBRARY: libaicodec.so
// RVA: 0x1073ac | SIZE: 176 bytes | SHA256: EC25BB1208B2D74E02C6E94510C98C70156C6EE8727DEC89A1F72AFA7250326E
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
// STRING_XREFS: [%s(%d)]:> get nativeObject error, com_meitu_media_FlyMediaReader_getDuration, com_meitu_media_FlyMediaReader_getDuration

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_getDuration(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x1073ac
    // Call imported API: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Literal reference: "[%s(%d)]:> get nativeObject error"
    // Literal reference: "com_meitu_media_FlyMediaReader_getDuration"
    // Literal reference: "com_meitu_media_FlyMediaReader_getDuration"
    return (void*)0;
}
