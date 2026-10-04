// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xc880
// Recovered Name: sub_c880
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc880 | Size: 96 bytes | SHA256: eb8dcf332c73000ccfc990cb396dc911aced397a132d54bdb5b6555189b60203
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __cxa_atexit, pthread_key_create

void sub_c880(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0xc880 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc884 */ adrp x0, #0x87000;
    /* 0xc888 */ mov x29, sp;
    /* 0xc88c */ stp x19, x20, [sp, #0x10];
    /* 0xc890 */ adrp x20, #0x88000;
    /* 0xc894 */ ldr x0, [x0, #0xe60];
    /* 0xc898 */ add x19, x20, #0x328;
    /* 0xc89c */ strb wzr, [x19, #4];
    /* 0xc8a0 */ cbz x0, #0xc8c0;
    /* 0xc8a4 */ adrp x1, #0x27000;
    /* 0xc8a8 */ mov x0, x19;
    pthread_key_create();
}
