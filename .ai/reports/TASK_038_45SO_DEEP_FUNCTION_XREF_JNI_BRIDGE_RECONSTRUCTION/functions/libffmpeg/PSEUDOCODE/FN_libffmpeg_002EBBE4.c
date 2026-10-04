// Reconstructed Pseudocode for FN_libffmpeg_002EBBE4 (sub_2EBBE4)
// Library: libffmpeg.so | RVA: 0x2EBBE4 | Size: 940B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: av_log;ff_mpv_encode_init;av_mul_q;av_gcd;av_nearer_q;av_timecode_init_from_string */
/* String XREFs: %s does not support resolutions above %dx%d;Width / Height is invalid for MPEG2;Width or Height are not allowed to be multiples of 4096 add '-strict %d' if you ;Set profile and level;Only High(1) and 4:2:2(0) profiles support 4:2:2 color sampling */

int sub_2EBBE4(void* ctx) {
    // Function prologue: set up stack frame
    sub_2EC734(ctx);
    sub_2EC734(ctx);
    sub_2EC734(ctx);
    sub_2EC734(ctx);
    av_log(...);
    ff_mpv_encode_init(...);
    av_mul_q(...);
    av_gcd(...);
    av_nearer_q(...);
    return 0;
}
