// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5724f0
// Recovered Name: sub_5724f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5724f0 | Size: 20 bytes | SHA256: e3dfff70d16b3d8ab623303c0ec2a8328b1afc9e57c2a61ff4546b7ba4036704
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHandCount(J)I (table at 0x10cd7d8)

jlong sub_5724f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5724f0 */ cbz x2, #0x5724fc;
    /* 0x5724f4 */ ldr w0, [x2, #0xc];
    return x0;
    /* 0x5724fc */ mov w0, wzr;
    return x0;
}
