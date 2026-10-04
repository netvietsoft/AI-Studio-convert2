// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6edcc
// Recovered Name: _ZN17MMDetectionPlugin17ExDenseHairModuleD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6edcc | Size: 36 bytes | SHA256: 88a5ffabc01b0d0a90118fd4a03b32296f8645f1545ade9d871f8eb926b0b397
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN17MMDetectionPlugin17ExDenseHairModuleD1Ev, _ZdlPv

void _ZN17MMDetectionPlugin17ExDenseHairModuleD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x6edcc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x6edd0 */ str x19, [sp, #0x10];
    /* 0x6edd4 */ mov x29, sp;
    /* 0x6edd8 */ mov x19, x0;
    _ZN17MMDetectionPlugin17ExDenseHairModuleD1Ev();
    /* 0x6ede0 */ mov x0, x19;
    /* 0x6ede4 */ ldr x19, [sp, #0x10];
    /* 0x6ede8 */ ldp x29, x30, [sp], #0x20;
    /* 0x6edec */ b #0x799b0;
}
