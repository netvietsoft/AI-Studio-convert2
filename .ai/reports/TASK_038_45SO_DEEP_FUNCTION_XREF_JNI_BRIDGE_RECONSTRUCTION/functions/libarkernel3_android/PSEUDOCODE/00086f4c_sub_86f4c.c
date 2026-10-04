// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x86f4c
// Recovered Name: sub_86f4c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x86f4c | Size: 140 bytes | SHA256: e418024cb60253dd704e58c6d336bd7b23dbcab09c5ebb2de7a807c5a889ad6f
// Callers: 27 | Callees: 1 | Imports: 3

// Calls external APIs: _Znwm, memmove, strlen

void sub_86f4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x86f4c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x86f50 */ stp x22, x21, [sp, #0x10];
    /* 0x86f54 */ stp x20, x19, [sp, #0x20];
    /* 0x86f58 */ mov x29, sp;
    /* 0x86f5c */ mov x19, x0;
    /* 0x86f60 */ mov x0, x1;
    /* 0x86f64 */ mov x21, x1;
    strlen();
    /* 0x86f6c */ cmn x0, #0x10;
    /* 0x86f70 */ b.hs #0x86fd0;
    /* 0x86f74 */ mov x20, x0;
    _Znwm();
    memmove();
    return x0;
    sub_86fd8();
}
