// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567560
// Recovered Name: sub_567560
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567560 | Size: 28 bytes | SHA256: e0a1e9275a863147bf7eb0602c97e84bcbd1462be11c4d9a1815ffcf9b218f98
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMeshTriangleNum(JI)I (table at 0x10ccaa0)

jlong sub_567560(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x567560 */ cbz x2, #0x567574;
    /* 0x567564 */ mov w8, #0x88;
    /* 0x567568 */ smaddl x8, w3, w8, x2;
    /* 0x56756c */ ldr w0, [x8, #0x40];
    return x0;
    /* 0x567574 */ mov w0, wzr;
    return x0;
}
