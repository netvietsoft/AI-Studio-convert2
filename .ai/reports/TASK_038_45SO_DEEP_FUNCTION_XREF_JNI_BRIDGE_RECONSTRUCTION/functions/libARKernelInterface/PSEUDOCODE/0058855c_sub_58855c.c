// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58855c
// Recovered Name: sub_58855c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58855c | Size: 32 bytes | SHA256: dce6519145d7e51130c4e1372d0dbfde0743039cb7ba8b05aa631146f0b06e8e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetJustify(J)I (table at 0x10cfe30)

jlong sub_58855c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x58855c */ cbz x2, #0x588574;
    /* 0x588560 */ ldr x0, [x2, #0x800];
    /* 0x588564 */ cbz x0, #0x58857c;
    /* 0x588568 */ ldr x8, [x0];
    /* 0x58856c */ ldr x1, [x8, #0x30];
    /* 0x588570 */ br x1;
    /* 0x588574 */ mov w0, wzr;
    return x0;
}
