// Library: libffmpeg.so
// Function ID: libffmpeg::0x2121e8
// Recovered Name: avpriv_adts_header_parse
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2121e8 | Size: 132 bytes | SHA256: bcee808937b13f2be9425dbce7228a94382980744bee60863391e09a582e3504
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: av_freep, av_mallocz, ff_adts_header_parse_buf

void avpriv_adts_header_parse(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x2121e8 */ stp x30, x21, [sp, #-0x20]!;
    /* 0x2121ec */ stp x20, x19, [sp, #0x10];
    /* 0x2121f0 */ mov x19, x0;
    /* 0x2121f4 */ mov w0, #0xb1b7;
    /* 0x2121f8 */ movk w0, #0xbebb, lsl #16;
    /* 0x2121fc */ cbz x19, #0x212260;
    /* 0x212200 */ mov x20, x1;
    /* 0x212204 */ cbz x1, #0x212260;
    /* 0x212208 */ cmp x2, #7;
    /* 0x21220c */ b.lo #0x212260;
    /* 0x212210 */ ldr x21, [x19];
    av_mallocz();
    ff_adts_header_parse_buf();
    av_freep();
    return x0;
}
