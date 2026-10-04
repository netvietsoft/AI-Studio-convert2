// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5883ec
// Recovered Name: sub_5883ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5883ec | Size: 60 bytes | SHA256: 3414ed75bdd522b44bf6498e3a38f3e59860dcfbce06ad3046a76035b254b5a1
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsUnderline(J)Z (table at 0x10cfdd0)

jlong sub_5883ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5883ec */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5883f0 */ mov x29, sp;
    /* 0x5883f4 */ cbz x2, #0x588418;
    /* 0x5883f8 */ ldr x0, [x2, #0x740];
    /* 0x5883fc */ cbz x0, #0x588424;
    /* 0x588400 */ ldr x8, [x0];
    /* 0x588404 */ ldr x8, [x8, #0x30];
    /* 0x588408 */ blr x8;
    /* 0x58840c */ and w0, w0, #1;
    /* 0x588410 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
