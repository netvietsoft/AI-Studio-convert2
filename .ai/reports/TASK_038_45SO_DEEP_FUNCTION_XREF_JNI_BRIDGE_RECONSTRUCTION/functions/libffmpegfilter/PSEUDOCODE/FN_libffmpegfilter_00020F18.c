// Reconstructed Pseudocode for FN_libffmpegfilter_00020F18 (avfilter_insert_filter)
// Library: libffmpegfilter.so | RVA: 0x20F18 | Size: 300B | Visibility: FACT

/* Imported APIs: av_log;avfilter_link;ff_formats_changeref;ff_channel_layouts_changeref */
/* String XREFs: auto-inserting filter '%s' between the filter '%s' and the filter '%s';dy used streams;tion;d h:%d sar:%d/%d -> w:%d h:%d sar:%d/%d;streams */

int avfilter_insert_filter(void* ctx) {
    // Function prologue: set up stack frame
    sub_228B8(ctx);
    sub_228B8(ctx);
    sub_228B8(ctx);
    sub_228B8(ctx);
    sub_2287C(ctx);
    av_log(...);
    avfilter_link(...);
    ff_formats_changeref(...);
    ff_channel_layouts_changeref(...);
    return 0;
}
