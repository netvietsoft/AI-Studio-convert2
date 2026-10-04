// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a674
// Recovered Name: sub_58a674
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a674 | Size: 16 bytes | SHA256: 2dbbc567f8d5d7ebdc0b95e6b7b11240cbd36a39041052ff61bf32a9278242de
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValue(JF)V (table at 0x10d0400)

jlong sub_58a674(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a674 */ cbz x2, #0x58a680;
    /* 0x58a678 */ mov x0, x2;
    /* 0x58a67c */ b #0xa2d4bc;
    return x0;
}
