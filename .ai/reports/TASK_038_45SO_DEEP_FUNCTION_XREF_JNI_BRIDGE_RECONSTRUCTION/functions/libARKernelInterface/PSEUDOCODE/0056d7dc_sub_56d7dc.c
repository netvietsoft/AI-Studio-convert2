// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d7dc
// Recovered Name: sub_56d7dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d7dc | Size: 20 bytes | SHA256: e3dfff70d16b3d8ab623303c0ec2a8328b1afc9e57c2a61ff4546b7ba4036704
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFoodCount(J)I (table at 0x10cd340)

jlong sub_56d7dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56d7dc */ cbz x2, #0x56d7e8;
    /* 0x56d7e0 */ ldr w0, [x2, #0xc];
    return x0;
    /* 0x56d7e8 */ mov w0, wzr;
    return x0;
}
