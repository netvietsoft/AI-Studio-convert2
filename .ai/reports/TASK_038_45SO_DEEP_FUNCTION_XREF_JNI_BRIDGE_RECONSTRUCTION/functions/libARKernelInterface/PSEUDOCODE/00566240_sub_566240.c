// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566240
// Recovered Name: sub_566240
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566240 | Size: 20 bytes | SHA256: c795a913762c59ffa009ed33007ea32857566bc0463fd0681073841b84d294f0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetVertexNum(JII)V (table at 0x10cc950)

jlong sub_566240(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x566240 */ cbz x2, #0x566250;
    /* 0x566244 */ mov w8, #0x38;
    /* 0x566248 */ smaddl x8, w3, w8, x2;
    /* 0x56624c */ str w4, [x8, #0x30];
    return x0;
}
