// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573d98
// Recovered Name: sub_573d98
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573d98 | Size: 20 bytes | SHA256: 6db5652adabe3e241498e858ce7bb3f19f502a5778383249d3eb7cd00675285c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetImageDataUserDefineFlag(JII)V (table at 0x10cdb20)

jlong sub_573d98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x573d98 */ cbz x2, #0x573da8;
    /* 0x573d9c */ mov w8, #0x58;
    /* 0x573da0 */ smaddl x8, w3, w8, x2;
    /* 0x573da4 */ str w4, [x8, #0x20];
    return x0;
}
