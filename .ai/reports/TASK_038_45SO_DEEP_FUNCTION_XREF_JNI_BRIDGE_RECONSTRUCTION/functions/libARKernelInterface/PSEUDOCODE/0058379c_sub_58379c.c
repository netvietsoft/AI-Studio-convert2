// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58379c
// Recovered Name: sub_58379c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58379c | Size: 32 bytes | SHA256: 732e6ec534ce83961e7ea770c7eaeb2d8536b298da397f9928fa67e1d687fc84
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextInTimestamp(J)F (table at 0x10cf8f0)

jlong sub_58379c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x58379c */ cbz x2, #0x5837b4;
    /* 0x5837a0 */ ldr x0, [x2, #0xc70];
    /* 0x5837a4 */ cbz x0, #0x5837bc;
    /* 0x5837a8 */ ldr x8, [x0];
    /* 0x5837ac */ ldr x1, [x8, #0x30];
    /* 0x5837b0 */ br x1;
    /* 0x5837b4 */ movi d0, #0000000000000000;
    return x0;
}
