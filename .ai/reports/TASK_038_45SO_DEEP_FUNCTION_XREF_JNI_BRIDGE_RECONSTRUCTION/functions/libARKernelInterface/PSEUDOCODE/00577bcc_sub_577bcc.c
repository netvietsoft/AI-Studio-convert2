// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577bcc
// Recovered Name: sub_577bcc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577bcc | Size: 16 bytes | SHA256: f2f1064d5fe628c7d7f03a73b780fabf7bd493dbe588e4c7653184bb79175b47
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetAllPartsAlpha(JF)V (table at 0x10cdeb0)

jlong sub_577bcc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x577bcc */ cbz x2, #0x577bd8;
    /* 0x577bd0 */ mov x0, x2;
    /* 0x577bd4 */ b #0x5757e0;
    return x0;
}
