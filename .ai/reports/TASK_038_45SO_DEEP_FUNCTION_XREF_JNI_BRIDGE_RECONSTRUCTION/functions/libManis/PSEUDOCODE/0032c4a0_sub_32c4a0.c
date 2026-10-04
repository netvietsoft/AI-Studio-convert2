// Library: libManis.so
// Function ID: libManis::0x32c4a0
// Recovered Name: sub_32c4a0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32c4a0 | Size: 44 bytes | SHA256: d5d6ed99cf55bc89425b92ff925d9df68555d6540f064337daa2f0913204a931
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdaPv

void sub_32c4a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x32c4a0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x32c4a4 */ str x19, [sp, #0x10];
    /* 0x32c4a8 */ mov x29, sp;
    /* 0x32c4ac */ mov x19, x0;
    /* 0x32c4b0 */ mov x0, x8;
    _ZdaPv();
    /* 0x32c4b8 */ mov x0, x19;
    /* 0x32c4bc */ ldr x19, [sp, #0x10];
    /* 0x32c4c0 */ ldp x29, x30, [sp], #0x20;
    /* 0x32c4c4 */ str xzr, [x0];
    return x0;
}
