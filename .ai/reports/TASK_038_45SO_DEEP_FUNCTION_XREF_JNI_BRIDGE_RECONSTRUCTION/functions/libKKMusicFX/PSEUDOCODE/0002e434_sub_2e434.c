// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e434
// Recovered Name: sub_2e434
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e434 | Size: 48 bytes | SHA256: 49798bac444ab7cba5b32d1b24a33b17893cc1a1aacfb84217506ae18dae5915
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt11logic_errorC2EPKc

void sub_2e434(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x2e434 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e438 */ str x19, [sp, #0x10];
    /* 0x2e43c */ mov x29, sp;
    /* 0x2e440 */ mov x19, x0;
    _ZNSt11logic_errorC2EPKc();
    /* 0x2e448 */ adrp x8, #0x81000;
    /* 0x2e44c */ ldr x8, [x8, #0xcd8];
    /* 0x2e450 */ add x8, x8, #0x10;
    /* 0x2e454 */ str x8, [x19];
    /* 0x2e458 */ ldr x19, [sp, #0x10];
    /* 0x2e45c */ ldp x29, x30, [sp], #0x20;
    return x0;
}
