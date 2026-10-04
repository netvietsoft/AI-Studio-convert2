// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d808
// Recovered Name: sub_57d808
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d808 | Size: 20 bytes | SHA256: cdb84bcd6b53e6fcc0f499251b8c8ebd8518a2823b011bdbb43a4f9f26ecf095
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerAdsorbDatumLineCount(J)I (table at 0x10cf0c8)

jlong sub_57d808(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d808 */ cbz x2, #0x57d814;
    /* 0x57d80c */ ldr w0, [x2, #0x50];
    return x0;
    /* 0x57d814 */ mov w0, wzr;
    return x0;
}
