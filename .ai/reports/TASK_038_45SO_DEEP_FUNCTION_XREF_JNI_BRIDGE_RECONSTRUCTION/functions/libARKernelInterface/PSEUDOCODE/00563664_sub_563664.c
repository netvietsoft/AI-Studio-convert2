// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x563664
// Recovered Name: sub_563664
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x563664 | Size: 156 bytes | SHA256: 4642191becdefae516796e90a73fec8363a3987bbf2c05d79fa6597d22f88d9e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetBodySlim3DSparseDataCount(JI)V (table at 0x10cc728)
// Calls external APIs: _ZdlPv

jlong sub_563664(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x563664 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x563668 */ str x21, [sp, #0x10];
    /* 0x56366c */ stp x20, x19, [sp, #0x20];
    /* 0x563670 */ mov x29, sp;
    /* 0x563674 */ cbz x2, #0x5636f0;
    /* 0x563678 */ mov x0, x2;
    /* 0x56367c */ mov x10, #0x37a7;
    /* 0x563680 */ mov x19, x2;
    /* 0x563684 */ ldp x8, x20, [x0, #0xf0]!;
    /* 0x563688 */ movk x10, #0xe9bd, lsl #16;
    /* 0x56368c */ movk x10, #0x6f4d, lsl #32;
    _ZdlPv();
    return x0;
}
