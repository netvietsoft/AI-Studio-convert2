// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x588ae0
// Recovered Name: sub_588ae0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x588ae0 | Size: 32 bytes | SHA256: 01d68de58c768e42ca972b1f220989b22cd117e06ba52f9e0caa32033f67d0cf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextLayout(J)I (table at 0x10cff98)

jlong sub_588ae0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x588ae0 */ cbz x2, #0x588af8;
    /* 0x588ae4 */ ldr x0, [x2, #0xb00];
    /* 0x588ae8 */ cbz x0, #0x588b00;
    /* 0x588aec */ ldr x8, [x0];
    /* 0x588af0 */ ldr x1, [x8, #0x30];
    /* 0x588af4 */ br x1;
    /* 0x588af8 */ mov w0, #-1;
    return x0;
}
