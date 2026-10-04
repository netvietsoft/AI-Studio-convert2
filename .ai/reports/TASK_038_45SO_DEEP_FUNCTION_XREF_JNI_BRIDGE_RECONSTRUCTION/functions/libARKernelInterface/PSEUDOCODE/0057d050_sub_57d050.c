// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d050
// Recovered Name: sub_57d050
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d050 | Size: 20 bytes | SHA256: ab1af42522d45cc7f709b812c9d7b91cfbd92fe359bb7943cdea17bd75f00946
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTextureUserDefineFlag(JII)V (table at 0x10cec00)

jlong sub_57d050(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d050 */ cbz x2, #0x57d060;
    /* 0x57d054 */ mov w8, #0x64;
    /* 0x57d058 */ smaddl x8, w3, w8, x2;
    /* 0x57d05c */ str w4, [x8, #0x60];
    return x0;
}
