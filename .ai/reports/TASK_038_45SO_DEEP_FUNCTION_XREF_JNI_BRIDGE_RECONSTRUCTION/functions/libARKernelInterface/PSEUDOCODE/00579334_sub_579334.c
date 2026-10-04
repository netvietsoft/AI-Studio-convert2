// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579334
// Recovered Name: sub_579334
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579334 | Size: 100 bytes | SHA256: f69294e17dad25640ebf4ea5a8629c1ac77a890d5665fb474e3f8b32c987066f
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetGenderType(J)I (table at 0x10ce288)

jlong sub_579334(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x579334 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x579338 */ str x19, [sp, #0x10];
    /* 0x57933c */ mov x29, sp;
    /* 0x579340 */ cbz x2, #0x579388;
    /* 0x579344 */ mov x0, x2;
    /* 0x579348 */ mov x19, x2;
    sub_8e0ae4();
    /* 0x579350 */ cmp w0, #2;
    /* 0x579354 */ b.ne #0x579360;
    /* 0x579358 */ mov w0, wzr;
    /* 0x57935c */ b #0x57938c;
    sub_8e0ae4();
    sub_8e0ae4();
    return x0;
}
