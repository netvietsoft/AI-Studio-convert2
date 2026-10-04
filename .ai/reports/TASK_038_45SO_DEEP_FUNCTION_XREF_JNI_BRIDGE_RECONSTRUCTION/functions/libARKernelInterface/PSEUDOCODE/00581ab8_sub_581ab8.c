// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581ab8
// Recovered Name: sub_581ab8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581ab8 | Size: 32 bytes | SHA256: bff9cfd2300c2b39ee77e045a1f5ed74cfd31e2accc23e0f81734b3d9250d505
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetBeginTimestamp(J)F (table at 0x10cf320)

jlong sub_581ab8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x581ab8 */ cbz x2, #0x581ad0;
    /* 0x581abc */ ldr x0, [x2, #0x200];
    /* 0x581ac0 */ cbz x0, #0x581ad8;
    /* 0x581ac4 */ ldr x8, [x0];
    /* 0x581ac8 */ ldr x1, [x8, #0x30];
    /* 0x581acc */ br x1;
    /* 0x581ad0 */ movi d0, #0000000000000000;
    return x0;
}
