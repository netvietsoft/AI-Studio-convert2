// Library: libARSPM.so
// Function ID: libARSPM::0x12cc28
// Recovered Name: _Z25ARSPMDestroySkottieHandleRPv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x12cc28 | Size: 56 bytes | SHA256: aab711724e07cca2c5af3c0910101a74a1dfb0abe17d801c614852a3d01a79b8
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _Z25ARSPMDestroySkottieHandleRPv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x12cc28 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x12cc2c */ stp x20, x19, [sp, #0x10];
    /* 0x12cc30 */ mov x29, sp;
    /* 0x12cc34 */ ldr x20, [x0];
    /* 0x12cc38 */ cbz x20, #0x12cc54;
    /* 0x12cc3c */ mov x19, x0;
    /* 0x12cc40 */ mov x0, x20;
    sub_1313dc();
    /* 0x12cc48 */ mov x0, x20;
    _ZdlPv();
    /* 0x12cc50 */ str xzr, [x19];
    return x0;
}
