// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5853ec
// Recovered Name: sub_5853ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5853ec | Size: 16 bytes | SHA256: 9ce41fb31801254dfcb96aa0cf655d2dba7bbe3956173c656d60c34321ea912b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDispatch(J)V (table at 0x10cf9e0)

jlong sub_5853ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5853ec */ cbz x2, #0x5853f8;
    /* 0x5853f0 */ mov x0, x2;
    /* 0x5853f4 */ b #0x583ed4;
    return x0;
}
