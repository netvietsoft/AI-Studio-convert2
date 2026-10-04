// FUNCTION: native_native_open
// LIBRARY: libaicodec.so
// RVA: 0x106d8c | SIZE: 400 bytes | SHA256: 88DFED11938FE58BE4BC70949684855CC141FF73F838C6DC767C1D9D5019383B
// SEMANTIC_LABEL: REGISTER_NATIVES_TARGET | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: _ZN7MMCodec13MTMediaReaderD1Ev, _ZdlPv, _Znwm, _ZN7MMCodec13MTMediaReaderC1EPKcPKhm, _Znwm, _ZN7MMCodec14AICodecContextC1Ev, _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE, _ZN7MMCodec6AVIRef7releaseEv, _ZN7MMCodec13MTMediaReader4openEv, __android_log_print, _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz, _ZN7MMCodec13MTMediaReaderD1Ev, _ZdlPv, _ZdlPv, _ZdlPv
// STRING_XREFS: [%s(%d)]:> open media file : %s failed, com_meitu_media_FlyMediaReader_open, com_meitu_media_FlyMediaReader_open

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* native_native_open(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x106d8c
    // Call imported API: _ZN7MMCodec13MTMediaReaderD1Ev
    // Call imported API: _ZdlPv
    // Call imported API: _Znwm
    // Call imported API: _ZN7MMCodec13MTMediaReaderC1EPKcPKhm
    // Call imported API: _Znwm
    // Call imported API: _ZN7MMCodec14AICodecContextC1Ev
    // Call imported API: _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE
    // Call imported API: _ZN7MMCodec6AVIRef7releaseEv
    // Call imported API: _ZN7MMCodec13MTMediaReader4openEv
    // Call imported API: __android_log_print
    // Call imported API: _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz
    // Call imported API: _ZN7MMCodec13MTMediaReaderD1Ev
    // Call imported API: _ZdlPv
    // Call imported API: _ZdlPv
    // Call imported API: _ZdlPv
    // Literal reference: "[%s(%d)]:> open media file : %s failed"
    // Literal reference: "com_meitu_media_FlyMediaReader_open"
    // Literal reference: "com_meitu_media_FlyMediaReader_open"
    return (void*)0;
}
