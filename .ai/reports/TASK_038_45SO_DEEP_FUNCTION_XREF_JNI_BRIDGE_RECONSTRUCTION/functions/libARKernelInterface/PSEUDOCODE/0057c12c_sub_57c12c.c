// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c12c
// Recovered Name: sub_57c12c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c12c | Size: 20 bytes | SHA256: e3dfff70d16b3d8ab623303c0ec2a8328b1afc9e57c2a61ff4546b7ba4036704
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetShoulderCount(J)I (table at 0x10ce9c0)

jlong sub_57c12c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57c12c */ cbz x2, #0x57c138;
    /* 0x57c130 */ ldr w0, [x2, #0xc];
    return x0;
    /* 0x57c138 */ mov w0, wzr;
    return x0;
}
