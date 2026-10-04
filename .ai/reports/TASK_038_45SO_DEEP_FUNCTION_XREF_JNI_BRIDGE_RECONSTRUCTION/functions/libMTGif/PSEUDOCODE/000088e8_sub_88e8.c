// Library: libMTGif.so
// Function ID: libMTGif::0x88e8
// Recovered Name: sub_88e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x88e8 | Size: 340 bytes | SHA256: 7311cbddf4d352559b9ea3b6f4f23961434096269e98e846527166f087533cd6
// Callers: 0 | Callees: 0 | Imports: 7

// Calls external APIs: __stack_chk_fail, av_frame_alloc, av_frame_free, av_freep, av_image_alloc, exit, sws_scale

void sub_88e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 85 instructions
    /* 0x88e8 */ stp x29, x30, [sp, #0x10];
    /* 0x88ec */ str x23, [sp, #0x20];
    /* 0x88f0 */ stp x22, x21, [sp, #0x30];
    /* 0x88f4 */ stp x20, x19, [sp, #0x40];
    /* 0x88f8 */ add x29, sp, #0x10;
    /* 0x88fc */ mrs x22, tpidr_el0;
    /* 0x8900 */ ldr x8, [x22, #0x28];
    /* 0x8904 */ str x8, [sp, #8];
    /* 0x8908 */ cbz x1, #0x89f4;
    /* 0x890c */ ldr x8, [x1];
    /* 0x8910 */ mov x19, x1;
    av_frame_alloc();
    av_image_alloc();
    sws_scale();
    av_freep();
    av_frame_free();
    av_freep();
    av_frame_free();
    return x0;
    exit();
    __stack_chk_fail();
}
