// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d7dc
// Recovered Name: sub_57d7dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d7dc | Size: 12 bytes | SHA256: d8d9be73335bfe0302ac7f2b594bd9f11b65d9229bdc89d55ca242f030555225
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerMoveAdsorbOValue(JI)V (table at 0x10cf080)

jlong sub_57d7dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d7dc */ cbz x2, #0x57d7e4;
    /* 0x57d7e0 */ str w3, [x2, #0x4c];
    return x0;
}
