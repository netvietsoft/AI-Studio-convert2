// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585570
// Recovered Name: sub_585570
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585570 | Size: 24 bytes | SHA256: 7f4ea5652af8756b754f558cd76a1822b1819726d1a4e8db7159007a300392f6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerAlpha(JJ)F (table at 0x10cfad0)

jlong sub_585570(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x585570 */ cbz x2, #0x585580;
    /* 0x585574 */ mov x0, x2;
    /* 0x585578 */ mov x1, x3;
    /* 0x58557c */ b #0x5843a4;
    /* 0x585580 */ movi d0, #0000000000000000;
    return x0;
}
