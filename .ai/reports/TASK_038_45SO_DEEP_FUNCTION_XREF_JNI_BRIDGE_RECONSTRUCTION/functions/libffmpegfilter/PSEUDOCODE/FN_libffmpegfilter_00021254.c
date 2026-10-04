// Reconstructed Pseudocode for FN_libffmpegfilter_00021254 (sub_21254)
// Library: libffmpegfilter.so | RVA: 0x21254 | Size: 260B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: av_strdup;av_expr_parse;av_expr_free;av_free */
/* String XREFs: Timeline ('enable' option) not supported with filter '%s';Error when evaluating the expression '%s' for enable */

int sub_21254(void* ctx) {
    // Function prologue: set up stack frame
    sub_228E8(ctx);
    sub_228AC(ctx);
    sub_22918(ctx);
    av_strdup(...);
    av_expr_parse(...);
    av_expr_free(...);
    av_free(...);
    return 0;
}
