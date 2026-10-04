// Reconstructed Pseudocode for FN_libffmpeg_0033A980 (av_bsf_init)
// Library: libffmpeg.so | RVA: 0x33A980 | Size: 260B | Visibility: FACT

/* Imported APIs: avcodec_parameters_copy;avcodec_descriptor_get;av_log;avcodec_get_name */
/* String XREFs: unknown;Codec '%s' (%d) is not supported by the bitstream filter '%s'. Supported codecs ;%s (%d);ltas[AV1_REF_FRAME_LAST3] */

int av_bsf_init(void* ctx) {
    // Function prologue: set up stack frame
    sub_33B258(ctx);
    sub_33B24C(ctx);
    avcodec_parameters_copy(...);
    avcodec_descriptor_get(...);
    av_log(...);
    avcodec_get_name(...);
    return 0;
}
