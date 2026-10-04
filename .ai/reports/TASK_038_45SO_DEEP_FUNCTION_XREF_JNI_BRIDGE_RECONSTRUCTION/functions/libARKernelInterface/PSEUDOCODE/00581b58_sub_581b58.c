// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581b58
// Recovered Name: sub_581b58
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581b58 | Size: 32 bytes | SHA256: c182c2257f25eb8347fef7443850c8c560c4b02ad67a79200045c36d2e79cef5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetEndTimestamp(J)F (table at 0x10cf350)

jlong sub_581b58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x581b58 */ cbz x2, #0x581b70;
    /* 0x581b5c */ ldr x0, [x2, #0x260];
    /* 0x581b60 */ cbz x0, #0x581b78;
    /* 0x581b64 */ ldr x8, [x0];
    /* 0x581b68 */ ldr x1, [x8, #0x30];
    /* 0x581b6c */ br x1;
    /* 0x581b70 */ movi d0, #0000000000000000;
    return x0;
}
