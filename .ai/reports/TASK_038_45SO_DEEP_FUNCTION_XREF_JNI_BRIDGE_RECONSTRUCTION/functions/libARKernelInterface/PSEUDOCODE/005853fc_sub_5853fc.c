// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5853fc
// Recovered Name: sub_5853fc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5853fc | Size: 16 bytes | SHA256: f45b45f3103f23723f21886e1c4dc25568503f26e6564ea2db524a9652f9ee4a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSortLayer(J)V (table at 0x10cf9f8)

jlong sub_5853fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5853fc */ cbz x2, #0x585408;
    /* 0x585400 */ mov x0, x2;
    /* 0x585404 */ b #0x583edc;
    return x0;
}
