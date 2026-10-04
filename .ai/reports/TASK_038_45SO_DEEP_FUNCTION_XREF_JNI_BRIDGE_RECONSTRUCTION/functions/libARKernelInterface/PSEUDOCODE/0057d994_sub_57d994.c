// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d994
// Recovered Name: sub_57d994
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d994 | Size: 36 bytes | SHA256: 083786b9629b6adb16fdf063fffced890580d7ca167ba8f973749ef19eef6e64
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerAdsorbDatumAngles(JI)I (table at 0x10cf1e8)

jlong sub_57d994(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x57d994 */ cbz x2, #0x57d9b0;
    /* 0x57d998 */ ldr w8, [x2, #0x100];
    /* 0x57d99c */ cmp w8, w3;
    /* 0x57d9a0 */ b.le #0x57d9b0;
    /* 0x57d9a4 */ add x8, x2, w3, sxtw #2;
    /* 0x57d9a8 */ ldr w0, [x8, #0x104];
    return x0;
    /* 0x57d9b0 */ mov w0, wzr;
    return x0;
}
