// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56339c
// Recovered Name: sub_56339c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56339c | Size: 712 bytes | SHA256: 1ab0b5750dd680886a20cebc96aef9544ea76382f9d61b72154d09455c951f0e
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetBodySlim3DData(JII[F[F[F[F)V (table at 0x10cc710)
// Calls external APIs: memcpy

jlong sub_56339c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 178 instructions
    /* 0x56339c */ stp x29, x30, [sp, #-0x50]!;
    /* 0x5633a0 */ str x25, [sp, #0x10];
    /* 0x5633a4 */ stp x24, x23, [sp, #0x20];
    /* 0x5633a8 */ stp x22, x21, [sp, #0x30];
    /* 0x5633ac */ stp x20, x19, [sp, #0x40];
    /* 0x5633b0 */ mov x29, sp;
    /* 0x5633b4 */ cbz x2, #0x5635e0;
    /* 0x5633b8 */ cmp w3, #8;
    /* 0x5633bc */ b.hi #0x5635e0;
    /* 0x5633c0 */ mov w8, #0x18;
    /* 0x5633c4 */ sxtw x24, w4;
    sub_563f8c();
    memcpy();
    sub_563f8c();
    return x0;
    memcpy();
}
