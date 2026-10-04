// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d034
// Recovered Name: sub_57d034
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d034 | Size: 28 bytes | SHA256: a6b4cca718f3f04f9021b02e8319a9dc9083423ae45994b136a550755aa9a810
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextureHeight(JI)I (table at 0x10cebe8)

jlong sub_57d034(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57d034 */ cbz x2, #0x57d048;
    /* 0x57d038 */ mov w8, #0x64;
    /* 0x57d03c */ smaddl x8, w3, w8, x2;
    /* 0x57d040 */ ldr w0, [x8, #0x70];
    return x0;
    /* 0x57d048 */ mov w0, wzr;
    return x0;
}
