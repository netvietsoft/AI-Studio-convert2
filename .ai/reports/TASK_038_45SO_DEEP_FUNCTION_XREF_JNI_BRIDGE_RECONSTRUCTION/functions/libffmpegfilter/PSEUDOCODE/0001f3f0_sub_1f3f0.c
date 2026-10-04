// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1f3f0
// Recovered Name: sub_1f3f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1f3f0 | Size: 848 bytes | SHA256: c66e350ebb91f1a0c1de0326c267ed7a6016f21987cd318aec71530a587b3018
// Callers: 0 | Callees: 3 | Imports: 4

// Calls external APIs: abort, av_log, memcpy, memset
// Strings referenced:
//   "atempo->position[0] <= stop_here"
//   "nsamples <= zeros + na + nb"
//   "read_size <= atempo->ring || atempo->tempo > 2.0"

void sub_1f3f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 212 instructions
    /* 0x1f3f0 */ str x30, [sp, #-0x60]!;
    /* 0x1f3f4 */ stp x28, x27, [sp, #0x10];
    /* 0x1f3f8 */ stp x26, x25, [sp, #0x20];
    /* 0x1f3fc */ stp x24, x23, [sp, #0x30];
    /* 0x1f400 */ stp x22, x21, [sp, #0x40];
    /* 0x1f404 */ stp x20, x19, [sp, #0x50];
    /* 0x1f408 */ ldr x9, [x0, #0xc8];
    /* 0x1f40c */ mov w8, #0x30;
    /* 0x1f410 */ ldr w10, [x0, #0x44];
    /* 0x1f414 */ mov x19, x0;
    /* 0x1f418 */ and x24, x9, #1;
    sub_202e0();
    sub_20258();
    av_log();
    abort();
    memcpy();
    memcpy();
    memset();
    memcpy();
    memcpy();
    sub_202ec();
    return x0;
    sub_202e0();
    sub_20258();
    av_log();
    abort();
    sub_202e0();
    sub_20258();
    av_log();
    abort();
}
