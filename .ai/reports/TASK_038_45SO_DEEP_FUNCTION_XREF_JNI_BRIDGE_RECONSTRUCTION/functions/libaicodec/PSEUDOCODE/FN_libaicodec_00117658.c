// Reconstructed Pseudocode for FN_libaicodec_00117658 (native_native_init_(Ljava/lang/String;J)J)
// Library: libaicodec.so | RVA: 0x117658 | Size: 572B | Visibility: FACT

/* Imported APIs: _ZN7MMCodec10MediaParam14getVideoRotateEv;_ZN7MMCodec10MediaParam14setVideoRotateEi;_ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_;_Znwm;_ZN7MMCodec14AICodecContextC1Ev;_ZN7MMCodec13MediaRecorderC1EPNS_14AICodecContextEPKcRKNS_10MediaParamE;_ZN7MMCodec6AVIRef7releaseEv;_ZN7MMCodec13MediaRecorder11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE;_ZdlPv;__android_log_print */
/* String XREFs: rotate;MTMV_AICodec;[%s(%d)]:> MediaParam native handle is null;com_meitu_media_encoder_FlyMediaRecorder_native_init;%s/MTMV_AICodec: [%s(%d)]:> MediaParam native handle is null */

int native_native_init_(Ljava/lang/String;J)J(void* ctx) {
    // Function prologue: set up stack frame
    sub_1F00EC(ctx);
    _ZN7MMCodec10MediaParam14getVideoRotateEv(...);
    _ZN7MMCodec10MediaParam14setVideoRotateEi(...);
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...);
    _Znwm(...);
    _ZN7MMCodec14AICodecContextC1Ev(...);
    return 0;
}
