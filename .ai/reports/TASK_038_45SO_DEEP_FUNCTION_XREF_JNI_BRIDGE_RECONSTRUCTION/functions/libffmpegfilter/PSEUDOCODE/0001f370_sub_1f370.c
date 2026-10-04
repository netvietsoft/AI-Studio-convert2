// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1f370
// Recovered Name: sub_1f370
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1f370 | Size: 128 bytes | SHA256: de3725fa2b9af0d3ae554709c4fce609f1a18bf573e3c32fc62a76460f5a2a4c
// Callers: 2 | Callees: 0 | Imports: 2

// Calls external APIs: av_rescale_q, ff_filter_frame

void sub_1f370(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x1f370 */ stp x30, x23, [sp, #-0x30]!;
    /* 0x1f374 */ stp x22, x21, [sp, #0x10];
    /* 0x1f378 */ stp x20, x19, [sp, #0x20];
    /* 0x1f37c */ ldr x22, [x0, #0x108];
    /* 0x1f380 */ ldr w8, [x1, #0x40];
    /* 0x1f384 */ mov x21, x1;
    /* 0x1f388 */ mov w9, #1;
    /* 0x1f38c */ mov w19, w2;
    /* 0x1f390 */ mov x20, x0;
    /* 0x1f394 */ str w8, [x22, #0xc0];
    /* 0x1f398 */ ldr x23, [x0, #0x30];
    av_rescale_q();
    ff_filter_frame();
    return x0;
}
