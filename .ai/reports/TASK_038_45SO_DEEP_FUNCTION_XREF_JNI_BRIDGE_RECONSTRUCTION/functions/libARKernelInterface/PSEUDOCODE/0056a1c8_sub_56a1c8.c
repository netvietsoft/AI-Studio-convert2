// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a1c8
// Recovered Name: sub_56a1c8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a1c8 | Size: 208 bytes | SHA256: cfc8971985f78bf206162e3f5a3463b7faf3857e2793c276153a44c347b31098
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetLeftEarLandmark2D(JI[F)V (table at 0x10cd118)
// Calls external APIs: memcpy

jlong sub_56a1c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x56a1c8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x56a1cc */ str x23, [sp, #0x10];
    /* 0x56a1d0 */ stp x22, x21, [sp, #0x20];
    /* 0x56a1d4 */ stp x20, x19, [sp, #0x30];
    /* 0x56a1d8 */ mov x29, sp;
    /* 0x56a1dc */ cbz x2, #0x56a284;
    /* 0x56a1e0 */ mov w21, w3;
    /* 0x56a1e4 */ cmp w3, #0x13;
    /* 0x56a1e8 */ b.hi #0x56a284;
    /* 0x56a1ec */ ldr x8, [x0];
    /* 0x56a1f0 */ mov x1, x4;
    memcpy();
    return x0;
}
