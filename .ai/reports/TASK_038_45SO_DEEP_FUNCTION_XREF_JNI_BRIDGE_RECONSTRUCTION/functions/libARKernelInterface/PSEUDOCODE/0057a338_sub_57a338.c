// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a338
// Recovered Name: sub_57a338
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a338 | Size: 16 bytes | SHA256: f5dbfdf6cb03f82c50aa505966fb49c0ba36e944bfa155cea0313a9964212524
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSeekBGM(JF)V (table at 0x10ce5d0)

jlong sub_57a338(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57a338 */ cbz x2, #0x57a344;
    /* 0x57a33c */ mov x0, x2;
    /* 0x57a340 */ b #0x90ae24;
    return x0;
}
