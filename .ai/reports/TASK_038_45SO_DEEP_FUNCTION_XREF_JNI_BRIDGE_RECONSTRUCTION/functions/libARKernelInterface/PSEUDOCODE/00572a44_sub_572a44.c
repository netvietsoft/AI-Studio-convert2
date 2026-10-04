// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572a44
// Recovered Name: sub_572a44
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572a44 | Size: 216 bytes | SHA256: 387b3e4eac8607e28ba64dc25d50c2e677842fa2eb428383de76bc679688c685
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetNailKeyPoints(JI[F)V (table at 0x10cd9a0)
// Calls external APIs: memcpy

jlong sub_572a44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x572a44 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x572a48 */ stp x24, x23, [sp, #0x10];
    /* 0x572a4c */ stp x22, x21, [sp, #0x20];
    /* 0x572a50 */ stp x20, x19, [sp, #0x30];
    /* 0x572a54 */ mov x29, sp;
    /* 0x572a58 */ cbz x2, #0x572b08;
    /* 0x572a5c */ mov w21, w3;
    /* 0x572a60 */ cmp w3, #9;
    /* 0x572a64 */ b.hi #0x572b08;
    /* 0x572a68 */ ldr x8, [x0];
    /* 0x572a6c */ mov x1, x4;
    memcpy();
    return x0;
}
