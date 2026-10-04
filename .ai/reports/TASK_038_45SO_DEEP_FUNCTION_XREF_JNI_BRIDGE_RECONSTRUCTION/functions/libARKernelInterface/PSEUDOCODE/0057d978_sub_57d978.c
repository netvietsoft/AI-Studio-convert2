// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d978
// Recovered Name: sub_57d978
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d978 | Size: 28 bytes | SHA256: c7009ae8e3e9f7e601c8c99de4626b8cc6f8aa9bb97ec498f7bfaf528dc97869
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerAdsorbDatumAngles(JII)V (table at 0x10cf1d0)

jlong sub_57d978(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57d978 */ cbz x2, #0x57d990;
    /* 0x57d97c */ ldr w8, [x2, #0x100];
    /* 0x57d980 */ cmp w8, w3;
    /* 0x57d984 */ b.le #0x57d990;
    /* 0x57d988 */ add x8, x2, w3, sxtw #2;
    /* 0x57d98c */ str w4, [x8, #0x104];
    return x0;
}
