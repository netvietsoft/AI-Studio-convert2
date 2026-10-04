// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1ef58
// Recovered Name: sub_1ef58
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1ef58 | Size: 1048 bytes | SHA256: 1e922f186bc7f389cae1a5de2d1041b21bfb03398d4cabc11cd804e42384f563
// Callers: 0 | Callees: 11 | Imports: 11

// Calls external APIs: abort, av_calloc, av_frame_copy_props, av_frame_free, av_get_bytes_per_sample, av_log, av_malloc_array, av_rescale_q, av_tx_init, cos, ff_get_audio_buffer
// Strings referenced:
//   "pot <= atempo->window"

void sub_1ef58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 262 instructions
    /* 0x1ef58 */ stp x29, x30, [sp, #0x20];
    /* 0x1ef5c */ stp x28, x27, [sp, #0x30];
    /* 0x1ef60 */ stp x26, x25, [sp, #0x40];
    /* 0x1ef64 */ stp x24, x23, [sp, #0x50];
    /* 0x1ef68 */ stp x22, x21, [sp, #0x60];
    /* 0x1ef6c */ stp x20, x19, [sp, #0x70];
    /* 0x1ef70 */ ldr x8, [x0, #0x10];
    /* 0x1ef74 */ ldrsw x11, [x1, #0x70];
    /* 0x1ef78 */ fmov d0, #0.50000000;
    /* 0x1ef7c */ str x1, [sp, #0x18];
    /* 0x1ef80 */ ldr x23, [x1];
    av_rescale_q();
    ff_get_audio_buffer();
    av_frame_copy_props();
    sub_20314();
    sub_202c8();
    sub_202a8();
    sub_1fa18();
    sub_20314();
    sub_202c8();
    sub_202a8();
    sub_1fbc0();
    sub_20324();
    sub_20324();
    sub_1f370();
    av_frame_free();
    return x0;
    av_get_bytes_per_sample();
    sub_1ff20();
    av_calloc();
    av_calloc();
    sub_2026c();
    sub_2026c();
    sub_2026c();
    sub_2026c();
    av_tx_init();
    av_tx_init();
    sub_2026c();
    av_calloc();
    av_calloc();
    av_malloc_array();
    cos();
    sub_1ff20();
    return x0;
    sub_202e0();
    sub_20258();
    av_log();
    abort();
}
