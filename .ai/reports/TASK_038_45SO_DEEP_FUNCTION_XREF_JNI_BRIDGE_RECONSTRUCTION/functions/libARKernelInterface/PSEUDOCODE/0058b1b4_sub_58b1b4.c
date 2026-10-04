// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b1b4
// Recovered Name: sub_58b1b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b1b4 | Size: 28 bytes | SHA256: b64dcea79f014b4852b0cf22ea9994d5546f337a1c010110d3842fc0a95bf88d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetParamType(J)I (table at 0x10d0628)

jlong sub_58b1b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b1b4 */ cbz x2, #0x58b1c8;
    /* 0x58b1b8 */ ldr x8, [x2];
    /* 0x58b1bc */ mov x0, x2;
    /* 0x58b1c0 */ ldr x1, [x8, #0x10];
    /* 0x58b1c4 */ br x1;
    /* 0x58b1c8 */ mov w0, wzr;
    return x0;
}
