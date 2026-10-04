// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x659c
// Recovered Name: sub_659c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x659c | Size: 136 bytes | SHA256: 07bf433ece377b3295738e8ec84cf5117b678daa9746bf792adcd9eaaf9f4b15
// Callers: 10 | Callees: 1 | Imports: 3

// Calls external APIs: _Znwm, memmove, strlen

void sub_659c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0x659c */ str x30, [sp, #-0x30]!;
    /* 0x65a0 */ stp x22, x21, [sp, #0x10];
    /* 0x65a4 */ stp x20, x19, [sp, #0x20];
    /* 0x65a8 */ mov x19, x0;
    /* 0x65ac */ mov x0, x1;
    /* 0x65b0 */ mov x21, x1;
    strlen();
    /* 0x65b8 */ cmn x0, #0x10;
    /* 0x65bc */ b.hs #0x661c;
    /* 0x65c0 */ mov x20, x0;
    /* 0x65c4 */ cmp x0, #0x17;
    _Znwm();
    memmove();
    return x0;
    sub_74c4();
}
