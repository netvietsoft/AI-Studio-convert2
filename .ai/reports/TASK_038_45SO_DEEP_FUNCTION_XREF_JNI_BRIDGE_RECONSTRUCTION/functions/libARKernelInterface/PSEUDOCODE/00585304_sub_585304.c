// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585304
// Recovered Name: sub_585304
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585304 | Size: 20 bytes | SHA256: 35119e072fbb409756ddfa0e0390a159fae55ff3721a94c859045c226f2ed951
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeResizeCanvas(JJ)V (table at 0x10cf968)

jlong sub_585304(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x585304 */ cbz x2, #0x585314;
    /* 0x585308 */ mov x0, x2;
    /* 0x58530c */ mov x1, x3;
    /* 0x585310 */ b #0x583eac;
    return x0;
}
