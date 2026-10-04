// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55df44
// Recovered Name: sub_55df44
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55df44 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10cc0e0)

jlong sub_55df44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x55df44 */ cbz x2, #0x55df58;
    /* 0x55df48 */ ldr x8, [x2];
    /* 0x55df4c */ mov x0, x2;
    /* 0x55df50 */ ldr x1, [x8, #0x18];
    /* 0x55df54 */ br x1;
    return x0;
}
