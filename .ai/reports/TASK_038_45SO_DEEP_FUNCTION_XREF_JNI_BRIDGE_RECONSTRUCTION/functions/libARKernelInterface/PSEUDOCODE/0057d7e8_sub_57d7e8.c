// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d7e8
// Recovered Name: sub_57d7e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d7e8 | Size: 20 bytes | SHA256: 9aab6dc90e81819594f261ac009fd6af85fe044dbdd7fc006e140ad60edf8dc7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerMoveAdsorbOValue(J)I (table at 0x10cf098)

jlong sub_57d7e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d7e8 */ cbz x2, #0x57d7f4;
    /* 0x57d7ec */ ldr w0, [x2, #0x4c];
    return x0;
    /* 0x57d7f4 */ mov w0, wzr;
    return x0;
}
