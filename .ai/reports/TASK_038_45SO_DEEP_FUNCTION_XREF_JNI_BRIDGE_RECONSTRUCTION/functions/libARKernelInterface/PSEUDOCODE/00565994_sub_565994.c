// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x565994
// Recovered Name: sub_565994
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x565994 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10cc770)

jlong sub_565994(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x565994 */ cbz x2, #0x5659a8;
    /* 0x565998 */ ldr x8, [x2];
    /* 0x56599c */ mov x0, x2;
    /* 0x5659a0 */ ldr x1, [x8, #0x18];
    /* 0x5659a4 */ br x1;
    return x0;
}
