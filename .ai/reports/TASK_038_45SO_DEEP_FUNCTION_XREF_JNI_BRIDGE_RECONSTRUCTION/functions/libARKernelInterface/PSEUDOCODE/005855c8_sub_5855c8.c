// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5855c8
// Recovered Name: sub_5855c8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5855c8 | Size: 32 bytes | SHA256: b55f34b1b8e5d5ec7a8a318de1d56f152564770a8b3800410b2f4ddd4a4a1ef6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetEnablePickup(JJZ)V (table at 0x10cfb18)

jlong sub_5855c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x5855c8 */ cbz x2, #0x5855e4;
    /* 0x5855cc */ tst w4, #0xff;
    /* 0x5855d0 */ mov x0, x2;
    /* 0x5855d4 */ mov w1, w3;
    /* 0x5855d8 */ cset w8, ne;
    /* 0x5855dc */ mov w2, w8;
    /* 0x5855e0 */ b #0x5843bc;
    return x0;
}
