// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567538
// Recovered Name: sub_567538
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567538 | Size: 20 bytes | SHA256: e3dfff70d16b3d8ab623303c0ec2a8328b1afc9e57c2a61ff4546b7ba4036704
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceCount(J)I (table at 0x10cca70)

jlong sub_567538(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567538 */ cbz x2, #0x567544;
    /* 0x56753c */ ldr w0, [x2, #0xc];
    return x0;
    /* 0x567544 */ mov w0, wzr;
    return x0;
}
