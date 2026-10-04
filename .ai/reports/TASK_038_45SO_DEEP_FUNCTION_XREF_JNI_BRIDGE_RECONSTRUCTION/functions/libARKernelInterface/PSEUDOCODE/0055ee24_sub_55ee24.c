// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55ee24
// Recovered Name: sub_55ee24
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55ee24 | Size: 20 bytes | SHA256: e3dfff70d16b3d8ab623303c0ec2a8328b1afc9e57c2a61ff4546b7ba4036704
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetAnimalCount(J)I (table at 0x10cc218)

jlong sub_55ee24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x55ee24 */ cbz x2, #0x55ee30;
    /* 0x55ee28 */ ldr w0, [x2, #0xc];
    return x0;
    /* 0x55ee30 */ mov w0, wzr;
    return x0;
}
