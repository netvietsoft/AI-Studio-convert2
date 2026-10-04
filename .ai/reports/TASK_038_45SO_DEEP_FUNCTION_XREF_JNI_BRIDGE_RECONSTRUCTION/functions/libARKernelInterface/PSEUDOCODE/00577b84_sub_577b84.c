// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577b84
// Recovered Name: sub_577b84
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577b84 | Size: 20 bytes | SHA256: a62500e8e0c533b673200c3abb8f17c8e5c5523cb1c1eb74741d630d3a8da5ab
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTotalFaceState(J)I (table at 0x10cde68)

jlong sub_577b84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x577b84 */ cbz x2, #0x577b90;
    /* 0x577b88 */ mov x0, x2;
    /* 0x577b8c */ b #0x57568c;
    /* 0x577b90 */ mov w0, wzr;
    return x0;
}
