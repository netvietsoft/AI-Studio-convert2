// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x6852c
// Recovered Name: sub_6852c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6852c | Size: 48 bytes | SHA256: ca9984e53abc08b896bd1d495bea7ed522d0f2d4dba4f18bb0f408aec9740ad7
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk15mutexD1Ev, _ZdlPv

void sub_6852c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x6852c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x68530 */ str x19, [sp, #0x10];
    /* 0x68534 */ mov x29, sp;
    /* 0x68538 */ adrp x8, #0x139000;
    /* 0x6853c */ add x8, x8, #0x168;
    /* 0x68540 */ mov x19, x0;
    /* 0x68544 */ str x8, [x0], #8;
    _ZNSt6__ndk15mutexD1Ev();
    /* 0x6854c */ mov x0, x19;
    /* 0x68550 */ ldr x19, [sp, #0x10];
    /* 0x68554 */ ldp x29, x30, [sp], #0x20;
}
