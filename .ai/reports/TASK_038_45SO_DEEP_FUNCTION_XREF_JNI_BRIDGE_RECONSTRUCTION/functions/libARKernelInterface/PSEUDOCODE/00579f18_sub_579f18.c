// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579f18
// Recovered Name: sub_579f18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579f18 | Size: 16 bytes | SHA256: e8cf4f668448dc693530408993d77ba01a4f1d44bfd73bc4c2e000930353a0ae
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeResetState(J)V (table at 0x10ce498)

jlong sub_579f18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x579f18 */ cbz x2, #0x579f24;
    /* 0x579f1c */ mov x0, x2;
    /* 0x579f20 */ b #0x90a808;
    return x0;
}
