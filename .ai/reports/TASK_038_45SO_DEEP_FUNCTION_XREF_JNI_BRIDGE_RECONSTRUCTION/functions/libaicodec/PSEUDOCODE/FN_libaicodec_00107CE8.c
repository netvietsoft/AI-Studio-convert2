// Reconstructed Pseudocode for FN_libaicodec_00107CE8 (native_native_getSizePerSample_(J)J)
// Library: libaicodec.so | RVA: 0x107CE8 | Size: 180B | Visibility: FACT

/* Imported APIs: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv;_ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE;av_get_bytes_per_sample;__android_log_print;_ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz */
/* String XREFs: MTMV_AICodec;[%s(%d)]:> get nativeObject error;com_meitu_media_FlyMediaReader_getSizePerSample;%s/MTMV_AICodec: [%s(%d)]:> get nativeObject error;com_meitu_media_FlyMediaReader_getSizePerSample */

int native_native_getSizePerSample_(J)J(void* ctx) {
    // Function prologue: set up stack frame
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...);
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...);
    av_get_bytes_per_sample(...);
    __android_log_print(...);
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...);
    return 0;
}
