// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x568c60
// Recovered Name: sub_568c60
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x568c60 | Size: 20 bytes | SHA256: fe233ca84ee844e2a01dee7fc895a3244d6870204ae27fa7b385b7fe547b84b9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceID(JII)V (table at 0x10cccf8)

jlong sub_568c60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x568c60 */ cbz x2, #0x568c70;
    /* 0x568c64 */ mov w8, #0x3d8;
    /* 0x568c68 */ smaddl x8, w3, w8, x2;
    /* 0x568c6c */ str w4, [x8, #0x14];
    return x0;
}
