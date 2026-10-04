// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d0b0
// Recovered Name: sub_5d0b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5d0b0 | Size: 60 bytes | SHA256: 3097bfccd676a722a63a1d9852231808150044de24e0ccf8277ffdd1d938971f
// Callers: 2 | Callees: 0 | Imports: 1

// Calls external APIs: memcpy

void sub_5d0b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5d0b0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5d0b4 */ stp x20, x19, [sp, #0x10];
    /* 0x5d0b8 */ mov x29, sp;
    /* 0x5d0bc */ adrp x20, #0x82000;
    /* 0x5d0c0 */ adrp x1, #0x7b000;
    /* 0x5d0c4 */ mov w2, #0x100;
    /* 0x5d0c8 */ ldr x19, [x20, #0x248];
    /* 0x5d0cc */ ldr x1, [x1, #0x1a8];
    /* 0x5d0d0 */ mov x0, x19;
    memcpy();
    /* 0x5d0d8 */ add x8, x19, #0x100;
    return x0;
}
