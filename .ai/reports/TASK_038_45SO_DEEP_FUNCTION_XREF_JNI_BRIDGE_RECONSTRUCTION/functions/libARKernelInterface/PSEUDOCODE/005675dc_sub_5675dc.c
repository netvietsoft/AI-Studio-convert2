// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5675dc
// Recovered Name: sub_5675dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5675dc | Size: 20 bytes | SHA256: 44971904b3327dff920bf8c207ae43861d33851ae6e4601652906452ec772763
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetReconstructVertexs(JIJ)V (table at 0x10ccb18)

jlong sub_5675dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5675dc */ cbz x2, #0x5675ec;
    /* 0x5675e0 */ mov w8, #0x88;
    /* 0x5675e4 */ smaddl x8, w3, w8, x2;
    /* 0x5675e8 */ str x4, [x8, #0x20];
    return x0;
}
