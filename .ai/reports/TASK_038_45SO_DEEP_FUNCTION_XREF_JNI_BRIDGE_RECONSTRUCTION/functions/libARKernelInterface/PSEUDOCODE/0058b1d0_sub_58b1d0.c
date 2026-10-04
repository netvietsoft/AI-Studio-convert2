// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b1d0
// Recovered Name: sub_58b1d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b1d0 | Size: 28 bytes | SHA256: 5846d52eafa5f868c673dacfc8a8c441a5c62efa20c0cff82c3199545e511481
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetParamFlag(J)I (table at 0x10d0640)

jlong sub_58b1d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b1d0 */ cbz x2, #0x58b1e4;
    /* 0x58b1d4 */ ldr x8, [x2];
    /* 0x58b1d8 */ mov x0, x2;
    /* 0x58b1dc */ ldr x1, [x8, #0x18];
    /* 0x58b1e0 */ br x1;
    /* 0x58b1e4 */ mov w0, wzr;
    return x0;
}
