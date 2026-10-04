// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1edc8
// Recovered Name: sub_1edc8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1edc8 | Size: 224 bytes | SHA256: 0621142aa53f50c679e86e7e50c6376714c377c402a799a6e73523891d8ac2c8
// Callers: 1 | Callees: 1 | Imports: 3

// Calls external APIs: ff_get_audio_buffer, swr_convert, swr_next_pts

void sub_1edc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x1edc8 */ str x30, [sp, #-0x40]!;
    /* 0x1edcc */ stp x24, x23, [sp, #0x10];
    /* 0x1edd0 */ stp x22, x21, [sp, #0x20];
    /* 0x1edd4 */ stp x20, x19, [sp, #0x30];
    /* 0x1edd8 */ ldr x8, [x0];
    /* 0x1eddc */ mov w22, w1;
    /* 0x1ede0 */ mov w1, #0x1000;
    /* 0x1ede4 */ mov x21, x2;
    /* 0x1ede8 */ mov x19, x0;
    /* 0x1edec */ ldr x9, [x8, #0x20];
    /* 0x1edf0 */ ldr x24, [x8, #0x48];
    ff_get_audio_buffer();
    swr_next_pts();
    swr_convert();
    sub_1eed4();
    return x0;
}
