// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579e08
// Recovered Name: sub_579e08
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579e08 | Size: 20 bytes | SHA256: 813662d1e1d9a3f27396a094eced36473cf649a729be9fc38b8bf06e2d22ff97
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetEyePartAlphaSide(J)I (table at 0x10ce3d8)

jlong sub_579e08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579e08 */ cbz x2, #0x579e14;
    /* 0x579e0c */ mov x0, x2;
    /* 0x579e10 */ b #0x8e0e90;
    /* 0x579e14 */ mov w0, wzr;
    return x0;
}
