// Reconstructed Pseudocode for FN_libffmpeg_0022A6A0 (ff_h264_queue_decode_slice)
// Library: libffmpeg.so | RVA: 0x22A6A0 | Size: 9932B | Visibility: FACT

/* Imported APIs: av_log;ff_h264_parse_ref_count;ff_h264_decode_ref_pic_list_reordering;ff_h264_pred_weight_table;ff_h264_decode_ref_pic_marking;ff_h264_execute_decode_slices;memcpy;ff_h264_field_end;ff_thread_report_progress;ff_refstruct_replace */
/* String XREFs:   )081*#$+29:3 %&-4;<5.'/6=>7?;÷I>³Ô;ts for offsets into frame statistics buffer */ #define COST_EST    0 #define COS;slice type %d too large at %d;pps_id %u out of range */

int ff_h264_queue_decode_slice(void* ctx) {
    // Function prologue: set up stack frame
    sub_22F1B8(ctx);
    sub_22E340(ctx);
    sub_22E3CC(ctx);
    sub_22F304(ctx);
    sub_22E414(ctx);
    av_log(...);
    ff_h264_parse_ref_count(...);
    ff_h264_decode_ref_pic_list_reordering(...);
    ff_h264_pred_weight_table(...);
    ff_h264_decode_ref_pic_marking(...);
    return 0;
}
