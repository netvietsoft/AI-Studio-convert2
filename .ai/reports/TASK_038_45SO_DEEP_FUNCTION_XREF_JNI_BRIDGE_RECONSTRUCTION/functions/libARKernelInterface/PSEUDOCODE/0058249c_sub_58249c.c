// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58249c
// Recovered Name: sub_58249c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58249c | Size: 32 bytes | SHA256: 5486a4e4c83876665a4d63724adf70bd0f22206dd1eff3880437bcfef8e54343
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetScale(J)F (table at 0x10cf4e8)

jlong sub_58249c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x58249c */ cbz x2, #0x5824b4;
    /* 0x5824a0 */ ldr x0, [x2, #0x290];
    /* 0x5824a4 */ cbz x0, #0x5824bc;
    /* 0x5824a8 */ ldr x8, [x0];
    /* 0x5824ac */ ldr x1, [x8, #0x30];
    /* 0x5824b0 */ br x1;
    /* 0x5824b4 */ movi d0, #0000000000000000;
    return x0;
}
