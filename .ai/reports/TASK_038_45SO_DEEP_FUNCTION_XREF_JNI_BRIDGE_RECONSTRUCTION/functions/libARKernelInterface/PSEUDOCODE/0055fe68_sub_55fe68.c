// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55fe68
// Recovered Name: sub_55fe68
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55fe68 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10cc350)

jlong sub_55fe68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x55fe68 */ cbz x2, #0x55fe7c;
    /* 0x55fe6c */ ldr x8, [x2];
    /* 0x55fe70 */ mov x0, x2;
    /* 0x55fe74 */ ldr x1, [x8, #0x18];
    /* 0x55fe78 */ br x1;
    return x0;
}
