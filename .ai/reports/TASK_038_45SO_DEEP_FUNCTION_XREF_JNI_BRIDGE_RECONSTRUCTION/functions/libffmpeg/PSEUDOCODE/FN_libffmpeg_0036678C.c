// Reconstructed Pseudocode for FN_libffmpeg_0036678C (ff_mediacodec_dec_init)
// Library: libffmpeg.so | RVA: 0x36678C | Size: 2428B | Visibility: FACT

/* Imported APIs: ff_AMediaCodec_createDecoderByType;av_strdup;ff_get_format;ff_mediacodec_surface_ref;ff_AMediaCodecProfile_getProfileFromAVCodecContext;av_log;ff_AMediaCodecList_getCodecNameByType;ff_AMediaCodec_createCodecByName;ff_mediacodec_dec_close;abort */
/* String XREFs: Unsupported or unknown profile;Found decoder %s;Failed to getCodecNameByType;Failed to create media decoder for mime %s;MediaCodec %p started successfully */

int ff_mediacodec_dec_init(void* ctx) {
    // Function prologue: set up stack frame
    sub_367C98(ctx);
    sub_367C98(ctx);
    sub_367CE4(ctx);
    sub_367D58(ctx);
    sub_367CE4(ctx);
    ff_AMediaCodec_createDecoderByType(...);
    av_strdup(...);
    ff_get_format(...);
    ff_mediacodec_surface_ref(...);
    ff_AMediaCodecProfile_getProfileFromAVCodecContext(...);
    return 0;
}
