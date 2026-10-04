// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577b38
// Recovered Name: sub_577b38
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577b38 | Size: 20 bytes | SHA256: 1ab5cb01cf9e0ae72fff2633663ab9d13a74509b56abd88807595660dcb491ce
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNativeRuntimeModifyFaceData(JJ)V (table at 0x10cde20)

jlong sub_577b38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x577b38 */ cbz x2, #0x577b48;
    /* 0x577b3c */ mov x0, x2;
    /* 0x577b40 */ mov x1, x3;
    /* 0x577b44 */ b #0x575528;
    return x0;
}
