// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a698
// Recovered Name: sub_8a698
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a698 | Size: 28 bytes | SHA256: 5846d52eafa5f868c673dacfc8a8c441a5c62efa20c0cff82c3199545e511481
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeVendor(J)I (table at 0x9aa40)

jlong sub_8a698(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8a698 */ cbz x2, #0x8a6ac;
    /* 0x8a69c */ ldr x8, [x2];
    /* 0x8a6a0 */ mov x0, x2;
    /* 0x8a6a4 */ ldr x1, [x8, #0x18];
    /* 0x8a6a8 */ br x1;
    /* 0x8a6ac */ mov w0, wzr;
    return x0;
}
