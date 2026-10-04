// Reconstructed Pseudocode for FN_libffmpegfilter_00020B6C (ff_filter_config_links)
// Library: libffmpegfilter.so | RVA: 0x20B6C | Size: 780B | Visibility: FACT

/* Imported APIs: ff_filter_config_links;av_buffer_ref;av_log;abort */
/* String XREFs: Not all input and output are properly linked (%d).;circular filter chain detected;Failed to configure output pad on %s;Failed to configure input pad on %s;Source filters and filters with more than one input must set config_props() call */

int ff_filter_config_links(void* ctx) {
    // Function prologue: set up stack frame
    sub_22858(ctx);
    sub_22844(ctx);
    ff_filter_config_links(...);
    av_buffer_ref(...);
    av_log(...);
    abort(...);
    return 0;
}
