// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x588e88
// Recovered Name: sub_588e88
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x588e88 | Size: 32 bytes | SHA256: 1014517a7e1c277479280b2d7d1c39cb331c33f1543288bd6759d62169002713
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetSequenceStyle(J)I (table at 0x10d0028)

jlong sub_588e88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x588e88 */ cbz x2, #0x588ea0;
    /* 0x588e8c */ ldr x0, [x2, #0xda0];
    /* 0x588e90 */ cbz x0, #0x588ea8;
    /* 0x588e94 */ ldr x8, [x0];
    /* 0x588e98 */ ldr x1, [x8, #0x30];
    /* 0x588e9c */ br x1;
    /* 0x588ea0 */ mov w0, wzr;
    return x0;
}
