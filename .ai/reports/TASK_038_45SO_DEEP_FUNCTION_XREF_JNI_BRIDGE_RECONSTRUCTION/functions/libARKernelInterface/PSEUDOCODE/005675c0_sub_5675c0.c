// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5675c0
// Recovered Name: sub_5675c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5675c0 | Size: 28 bytes | SHA256: 034dcc1c9274870c2344ba91db0b8d63c8b725a6b1f15d0651313fce4982012f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMeshVertexNum(JI)I (table at 0x10ccb00)

jlong sub_5675c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5675c0 */ cbz x2, #0x5675d4;
    /* 0x5675c4 */ mov w8, #0x88;
    /* 0x5675c8 */ smaddl x8, w3, w8, x2;
    /* 0x5675cc */ ldr w0, [x8, #0x18];
    return x0;
    /* 0x5675d4 */ mov w0, wzr;
    return x0;
}
