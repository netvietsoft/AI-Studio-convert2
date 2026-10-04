// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e5a8
// Recovered Name: sub_56e5a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e5a8 | Size: 20 bytes | SHA256: 95b33c61ae3f96ccb736c49835d1397feb068cf925da2122490b155bc59f0645
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeStopSoundService()V (table at 0x10cd4d8)

jlong sub_56e5a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56e5a8 */ adrp x8, #0x10d0000;
    /* 0x56e5ac */ add x8, x8, #0xc30;
    /* 0x56e5b0 */ ldr w8, [x8];
    /* 0x56e5b4 */ cmp w8, #2;
    /* 0x56e5b8 */ b.gt #0x56e60c;
}
