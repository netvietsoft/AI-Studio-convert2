// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a264
// Recovered Name: sub_58a264
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a264 | Size: 16 bytes | SHA256: 9ea0411bd716f895805a9750479ddccef255c95639ce61e6c8c775b4937f88df
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentColorOpacity(JF)V (table at 0x10d01c0)

jlong sub_58a264(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a264 */ cbz x2, #0x58a270;
    /* 0x58a268 */ mov x0, x2;
    /* 0x58a26c */ b #0xa2c174;
    return x0;
}
